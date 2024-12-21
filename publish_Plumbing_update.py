import os
import boto3
import datetime
import subprocess
from   git import Repo, GitCommandError

# Set AWS credentials as environment variables
os.environ['AWS_ACCESS_KEY_ID']     = ''
os.environ['AWS_SECRET_ACCESS_KEY'] = ''

# Get the absolute path to the directory where the script is located
script_dir          = os.path.dirname(os.path.abspath(__file__))
repo_path           = script_dir
bucket_name         = ""
firmware_folder     = os.path.join(script_dir, '.pio', 'build', 'esp12e')
new_firmware_name   = ""
version_file_path   = os.path.join(script_dir, 'version.txt')

def check_and_commit_changes():
    repo    = Repo(repo_path)
    origin  = repo.remotes.origin
    origin.fetch()

    if repo.is_dirty(untracked_files=True):
        print("Local repository has uncommitted changes.")
        
        repo.git.add(A=True)
        print("Staged all changes.")

        commit_message = f"Automated commit on {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}"
        repo.index.commit(commit_message)
        print(f"Committed changes with message: {commit_message}")

    else:
        print("No uncommitted changes found.")

    local_commit    = repo.head.commit
    remote_commit   = repo.head.ref.tracking_branch().commit
    
    if local_commit == remote_commit:
        print("Local repository is up to date with the remote repository.")
    else:
        print("Local repository is not up to date with the remote repository.")
        try:
            origin.push()
            print("Pushed committed changes to the remote repository.")
        except GitCommandError as e:
            print(f"Error pushing changes: {e}")

def update_platformio():
    try:
        print("Checking for PlatformIO updates...")
        subprocess.run(["pip", "install", "--upgrade", "platformio"], check=True)
        print("PlatformIO is up-to-date.")
    except subprocess.CalledProcessError as e:
        print(f"Error updating PlatformIO: {e}")

def build_project():
    try:
        print(f"Building project in {repo_path} using PlatformIO...")
        result = subprocess.run(["pio", "run"], cwd=repo_path, check=True, capture_output=True, text=True)
        print("Build completed successfully!")
        print("Build output:\n", result.stdout)
    except subprocess.CalledProcessError as e:
        print("Build failed. Please check the output below for more details:")
        print(e.stderr)

def update_firmware_version():
    global new_firmware_name
    firmware_file = os.path.join(firmware_folder, "firmware.bin")

    try:
        with open(version_file_path, "r") as version_file:
            version_data = version_file.read().strip()
            new_version = version_data.split('\n')[0].split(": ")[1].strip()
            new_firmware_name = f"firmware_v{new_version}.bin"
        
        new_firmware_path = os.path.join(firmware_folder, new_firmware_name)
        os.rename(firmware_file, new_firmware_path)
        print(f"Renamed firmware file to {new_firmware_name}")
    except FileNotFoundError:
        print("Version file not found. Skipping firmware update.")
    except Exception as e:
        print(f"Error updating firmware version: {e}")

def upload_to_s3(file_paths, bucket_name):
    # Initialize the S3 client
    s3 = boto3.client('s3')
    
    for file_path in file_paths:
        file_name = os.path.basename(file_path)
        s3_key = file_name
        
        try:
            s3.upload_file(file_path, bucket_name, s3_key)
            print(f"Uploaded {file_name} to S3 bucket {bucket_name} with key {s3_key}")
        except boto3.exceptions.S3UploadFailedError as e:
            print(f"Failed to upload {file_name}: {e}")
        except Exception as e:
            print(f"An error occurred: {e}")

if __name__ == "__main__":
    # print("Starting repository status check and update...")                       # Disabled for jenkins untill issue resolved
    # check_and_commit_changes()
    print("\nUpdating PlatformIO to the latest version...")
    update_platformio()
    print("\nBuilding the project with PlatformIO...")
    build_project()
    print("\nUpdating firmware version...")
    update_firmware_version()

    print("\nUploading firmware to S3...")
    file_paths = [
        version_file_path,
        os.path.join(firmware_folder, new_firmware_name)
    ]      
    upload_to_s3(file_paths, bucket_name)
    print("\nProcess completed.")
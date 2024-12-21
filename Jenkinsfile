pipeline {
    agent any

    stages {
        stage('Clone or Fetch Repository') {
            steps {
                script {
                    // Clone the repository if it's not already cloned, otherwise fetch the latest changes
                    checkout scm
                }
            }
        }

        stage('Clean Build Directory') {
            steps {
                script {
                    // Print the current working directory
                    sh 'pwd'

                    // Clean the build directory using PlatformIO command
                    sh 'platformio run --target clean'  
                }
            }  
        }

        stage('Build Project') {
            steps {
                // Print the current working directory
                sh 'pwd' 

                // Run my automation script
                sh 'python3 publish_Plumbing_update.py'
            } 
        }
    }
}
pipeline {
    agent {
        docker { 
            image 'gcc:latest' // Obraz zawierający kompilator g++ i narzędzia make
        }
    }

    stages {
        stage('Setup') {
            steps {
                echo 'Installing CMake...'
                sh 'apt-get update && apt-get install -y cmake'
            }
        }

        stage('Build') {
            steps {
                echo 'Building project...'
                sh '''
                    mkdir -p build
                    cd build
                    cmake ..
                    make
                '''
            }
        }

        stage('Unit Tests') {
            steps {
                echo 'Run unit tests...'
                sh './build/run_tests'
            }
        }

        stage('Static Analysis') {
            steps {
                echo 'CPPcheck...'
                sh 'apt-get install -y cppcheck'
                sh 'cppcheck --enable=all app/'
            }
        }
    }
}
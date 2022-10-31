function build() {
    sudo rm -rf build
    mkdir build
    cd build
    cmake ..
}

# exit when any command fails
set -e

build
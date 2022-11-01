#!/bin/bash

# exit when any command fails
set -e

sudo rm -rf build
mkdir build
cd build
cmake ..
make
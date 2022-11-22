#!/bin/bash

# exit when any command fails
set -e

cd build
sudo make install -j4
cd ..
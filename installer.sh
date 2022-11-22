#!/bin/bash

# exit when any command fails
set -e

sudo rm -rf /usr/local/bin/rocket_league
sudo rm -rf /usr/local/bin/rocket_league-server
sudo rm -rf /usr/local/bin/librocket_league-common.so
sudo rm -rf /usr/local/bin/assets

cd build
sudo make install -j4
cd ..
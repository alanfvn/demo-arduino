#!/bin/bash

# Install dependencies
sudo apt-get update
sudo apt-get install tar curl git -y

cd .

# Install arduino-cli
curl -L -o arduino-cli.tar.bz2 https://downloads.arduino.cc/arduino-cli/arduino-cli-latest-linux64.tar.bz2
tar xjf arduino-cli.tar.bz2
rm arduino-cli.tar.bz2
mv arduino-cli /usr/bin/arduino-cli

# Install python, pip and pyserial
# curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
# python get-pip.py
# pip install pyserial

# Install esp32 core
printf "board_manager:\n  additional_urls:\n    - https://dl.espressif.com/dl/package_esp32_index.json\n" > .arduino-cli.yaml
arduino-cli core update-index --config-file .arduino-cli.yaml
arduino-cli core install esp32:esp32 --config-file .arduino-cli.yaml

# Install 'native' packages
# arduino-cli lib install "ArduinoJson"
# cd -

# Install 'third-party' packages: find proper location and 'git clone'
cd `arduino-cli config dump | grep sketchbook | sed 's/.*\ //'`/libraries
git clone https://github.com/ayushsharma82/ElegantOTA
cd -

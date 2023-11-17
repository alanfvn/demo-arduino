#!/bin/bash

# Install dependencies
sudo apt-get update
sudo apt-get install curl git -y

cd .

# Install arduino-cli
curl -L -o arduino-cli.tar.bz2 https://downloads.arduino.cc/arduino-cli/arduino-cli-latest-linux64.tar.bz2
tar xjf arduino-cli.tar.bz2
rm arduino-cli.tar.bz2
sudo mv arduino-cli /usr/bin/arduino-cli

# Install esp32 core
printf "board_manager:\n  additional_urls:\n    - https://dl.espressif.com/dl/package_esp32_index.json\n" > .arduino-cli.yaml
arduino-cli core update-index --config-file .arduino-cli.yaml
arduino-cli core install esp32:esp32 --config-file .arduino-cli.yaml

# Install 'native' packages
# arduino-cli lib install "ArduinoJson"
# cd -

# Install 'third-party' packages: find proper location and 'git clone'
LIBRARY_PATH="$(arduino-cli config dump | grep sketchbook | sed 's/.*\ //' )/libraries"
mkdir -p "$LIBRARY_PATH"
cd "$LIBRARY_PATH"
git clone https://github.com/ayushsharma82/ElegantOTA
cd -

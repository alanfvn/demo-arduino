
#!/bin/bash

# Install dependencies
sudo apt-get update
sudo apt-get install cmake curl git -y

# AT THIS POINT WE ARE IN THE ROOT OF THE REPOSITORY

# setup the test framework
cd .

planck_dir="./planck-unit"
git clone https://github.com/alanfvn/planck-unit
rm -rf $planck_dir/tests/
# add the library to the includes
sudo cp -r $planck_dir/src/* /usr/include/
# move all files to root dir
cp -rf $planck_dir/* .
ls -la

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
git clone https://github.com/ThingPulse/esp8266-oled-ssd1306
cd -

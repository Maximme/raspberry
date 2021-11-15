g++ MFRC522.cpp main.cpp -std=c++11 -lbcm2835 -lwiringPi
sudo ./a.out

tout est dans le main.cpp


sudo raspi-config
Interfacing options -> enable I2C (lcd) & SPI
**sudo apt-get install i2c-tools

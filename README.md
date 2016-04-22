# arduinoVoltmeter

###What is this?

This project is an Arduino Nano voltmeter with an small I2C 128x64 OLED display and ESP8266 in AT mode. Voltage is read, displayed on the display and posted to a Thingspeak.com channel.

I used an external voltage reference for this project, just for fun and to see if I could get a better precision than when using the internal one.

Why the ESP8266 in AT mode? Well I was not able to make the display work directly on the ESP and I never tried to work with the ESP in AT mode so I decided to give it a go and keep the display on the Nano.

###Hardware
- Adafruit HUZZAH
- Arduino Nano
- I2C 128x64 OLED (the cheap ones from eBay)
- 5V Shunt Voltage Reference LM4040

###Schematic
<img src="https://cloud.githubusercontent.com/assets/11507542/14757252/7dc6bab0-08bf-11e6-8dfe-a98279858d81.jpg" width="50%"></img>

###Libraries used
- U8glib
- SoftwareSerial

###IDE
- PlatformIO [http://platformio.org/](http://platformio.org/)

###Pictures
The display is broken in this pic. Waiting for a new one.

<img src="https://cloud.githubusercontent.com/assets/11507542/14336691/8d8d3f9c-fc34-11e5-9f61-27a3a559474b.jpg" width="15%"></img> 

###Things to come
- KiCAD schematics
- Bare ESP-12 instead of HUZZAH
- Pictures

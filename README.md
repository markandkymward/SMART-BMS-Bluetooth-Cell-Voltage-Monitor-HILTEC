# SMART-BMS-Bluetooth-Cell-Voltage-Monitor-HILTEC
Small cell voltage monitor for XIAOXIANG SMART BMS Bleutooth BLE, only requires 5vdc connection
Smart-BMS-Bluetooth-ESP32
Program to read out and display data from xiaoxiang Smart BMS over Bluetooth Low Energy
https://www.lithiumbatterypcb.com/
Tested with original BLE module provided. Might work with generic BLE module when UUIDs are modified

Needs ESP32 and graphic display.
Tested on HILTEC ESP32 WROOM 32: https://heltec.org/project/wifi-kit-32/

Fork from the work of: (c) Miroslav Kolinsky 2019 https://www.kolins.cz

thanks to Petr Jenik for big parts of code
thanks to Milan Petrzilka

heavily inspired by https://github.com/bres55/Smart-BMS-arduino-Reader

![](esp32.gif) 
![](esp32.jpg)

Notes:

1. Install Hardware libraries on Arduinio IDE per this turotial: https://robotzero.one/heltec-wifi-kit-32/
2. Download the *.ino into working Arduino folder and flash the ESP32 - that's it!
3. I used this case from Thingiverse. PLA, 15% infill. Extended the longer dimesion by 2% in the print. https://www.thingiverse.com/thing:3148876
4. The only connection required is 5vDC from ESC, BLE connection is automatic.
5. Display bars inspired by esk8.news JANPOM.  They show the relative difference in cell voltage from the pack mean voltage.  
6. The number in parentheses in the top line is the maximum cell voltage delta (high-low).
7. "B" means that cell is being actively balanced.
8. Written for 10S, might get tight for more cells.  This ESP32 actually has a touch interface that you can actually swipe a second screen.  

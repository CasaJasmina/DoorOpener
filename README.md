# Door Opener
A combination of a capacitive keypad/doorbell and a hacked lockitron.
At the moment there is a wired connection between the two parts of the project allowing the opening of the door when the right combination is pressed.

## The keypad
![alt tag](https://raw.github.com/CasaJasmina/DoorOpener/master/pics/front plate.jpg)

![alt tag](https://raw.github.com/CasaJasmina/DoorOpener/master/pics/capacitive_board.jpg)

The keypad is based on Arduino YUN.
It uses MPR1221 for capacitive touch detection and addressable RGB led to provide feedbacks to the user.
find more inside the keypad folder

## The lockitron

![alt tag](https://raw.github.com/CasaJasmina/DoorOpener/master/pics/lockitron.jpg)

![alt tag](https://raw.github.com/CasaJasmina/DoorOpener/master/pics/esp_lockitron_board.jpg)
To open the door a old model of lockitron was hacked. You can get the mechanical parts from Adafruit.
A custom PCB based on ESP8266 was designed and milled.

## TODO
- connect the system to Arduino Cloud

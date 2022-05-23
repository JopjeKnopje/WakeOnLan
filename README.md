# WakeOnLan

Controls a computers power button.
<br />
## Introduction

A cursed hardware implementation for WakeOnLan using a esp8266 running a simple [Telegram bot](https://core.telegram.org/bots) controlling a relay.


## Building 

### Hardware
- [5v Relay board](https://nl.aliexpress.com/item/1005002617199944.html?spm=a2g0o.search0304.0.0.27c02a257Dg3bo).
- [nodemcu v3](https://nl.aliexpress.com/item/32520574539.html?spm=a2g0o.productlist.0.0.6ee422daVuEDwZ).
- a few wires.


### Installation

Breakout the power button wires.

Build the [schematic](tmp).<br />
Install the  [esp8266 package](https://arduino-esp8266.readthedocs.io/en/latest/installing.html) and the [UniversalTelegramBot](https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot#installing) library.

Compile... <br />
Aaaaaand upload.

## Features
- Only responds to a specified client_id so no one else can turn on your pc.


## Pictures
![alt text](https://raw.githubusercontent.com/JopjeKnopje/WakeOnLan/main/pics/1.png?raw=true)

![alt text](https://raw.githubusercontent.com/JopjeKnopje/WakeOnLan/main/pics/2.png?raw=true)




### Todo
- [ ] Use something other than Telegram lol.
- [ ] Add timer class instead of loose variables.
- [ ] Log declined commands to file.
- [ ] Steal laptops USB power so we don't have to use a external adapter
- [ ] poweroff time longer?



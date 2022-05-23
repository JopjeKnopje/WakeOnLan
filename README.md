# WakeOnLan

Controls a computers power button.
<br />
## Introduction

A cursed hardware implementation for WakeOnLan using a esp8266 running a simple [Telegram bot](https://core.telegram.org/bots) controlling a relay.


## Hardware
- [5v Relay board](https://nl.aliexpress.com/item/1005002617199944.html?spm=a2g0o.search0304.0.0.27c02a257Dg3bo)
- [nodemcu v3](https://nl.aliexpress.com/item/32520574539.html?spm=a2g0o.productlist.0.0.6ee422daVuEDwZ)
- a few wires


## Installation

Build the [schematic](tmp)<br />
Install the  [esp8266 package](https://arduino-esp8266.readthedocs.io/en/latest/installing.html) and the [UniversalTelegramBot](https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot#installing) library

Compile... <br />
Aaaaaand upload.

## Features
- Only responds to a specified client_id so no one else can turn on your pc


### Todo
- [ ] Use something else than Telegram lol
- [ ] Add timer class instead of loose variables
- [ ] Log declined commands to file
- [ ] Add schematic 
- [ ] Add photos



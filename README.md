# Firmware of I2C CAN Bus Module

[![Actions Status](https://github.com/arduino/arduino-cli-example/workflows/test/badge.svg)](https://github.com/arduino/arduino-cli-example/actions)
[![Spell Check](https://github.com/arduino/compile-sketches/workflows/Spell%20Check/badge.svg)](https://github.com/arduino/compile-sketches/actions?workflow=Spell+Check)
[![codecov](https://codecov.io/gh/arduino/compile-sketches/branch/main/graph/badge.svg?token=Uv6f1ebMZ4)](https://codecov.io/gh/arduino/compile-sketches)

Firmware of I2C CAN Bus Module.

## Installation Arduino libraries

This project requires two libraries:
- **[Arduino CAN BUS MCP2515 Library](https://github.com/Longan-Labs/Aruino_CAN_BUS_MCP2515)**. Driver for the MPC2515 CAN Bus transceiver.
- **[SBWire](https://github.com/freespace/SBWire)**. Replacement for the default Arduino Wire (i<sup>2</sup>c) library with basic timeouts to fix the board from occasionally not correctly responding to i<sup>2</sup>c messages. See this [post](https://www.fpaynter.com//2018/08/known-defect-in-arduino-i2c-code-causes-hangup-problems/).

Please install the both libraries first before compiling this sketch. 
To install a library

1. Download both libraries ([Arduino CAN BUS MCP2515 Library](https://github.com/Longan-Labs/Aruino_CAN_BUS_MCP2515/archive/refs/heads/master.zip) and the [SBWire](https://github.com/freespace/SBWire/archive/refs/heads/master.zip)).
2. In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library, select the just downloaded zip file.
3. Repeat for the second library. 

## Get a Dev Board

If you need a Dev board, please try,

- [I2C CAN Bus Module](https://www.longan-labs.cc/1030017.html) 

You can get others CAN Dev board below,

- [Serial CAN Bus Module](https://www.longan-labs.cc/1030001.html)
- [CAN Bus Shield for Arduino](https://www.longan-labs.cc/1030016.html)
- [CANBed V1](https://www.longan-labs.cc/1030008.html)
- [CANBed M0](https://www.longan-labs.cc/1030014.html)
- [OBD-II CAN Bus GPS Dev Kit](https://www.longan-labs.cc/1030003.html)

## License

```
MIT License

Copyright (c) 2018 @ Longan Labs

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## Contact us

If you have any question, please feel free to contact [support@longan-labs.cc](support@longan-labs.cc)

## I<sup>2</sup>C Registers

The device default I<sup>2</sup>C slave address is 0x25 but can be changed by writing to address 1. Note that the new address is stored inside the internal EEPROM of the chip, and therefore changes in the bus address will remain after power loss. 

The following table contains the various registers that are available on the i2c interface of the CAN Module.

| Address | Name   | Length   | Type | Default Value | Description                                   |
| ------- | ------ | -------- | ---- | ------------- | --------------------------------------------- |
| 0x01    | Addr   | 1 Byte   | W    | 0x25          | I2C slave Address                             |
| 0x02    | DNUM   | 1 Byte   | R    | 0             | No. of CAN frames in RX buffer (max 16)       |
| 0x03    | BAUD   | 1 Byte   | W    | 16(500kb/s)   | Set the CAN baudrate                          |
| 0x04    | Errors | 3 Bytes  | R    | 0             | B0: Error flags, B1: TX errors, B2: Rx errors |
| 0x30    | Send   | 16 Bytes | W    | -             | Send CAN frame                                |
| 0x40    | Recv   | 16 Bytes | R    | -             | Read CAN frame from Recv buffer               |
| 0x60    | Mask0  | 5 Bytes  | W/R  | 0             | Mask 0                                        |
| 0x65    | Mask1  | 5 Bytes  | W/R  | 0             | Mask 1                                        |
| 0x70    | Filt0  | 5 Bytes  | W/R  | 0             | Filter 0                                      |
| 0x80    | Filt1  | 5 Bytes  | W/R  | 0             | Filter 1                                      |
| 0x90    | Filt2  | 5 Bytes  | W/R  | 0             | Filter 2                                      |
| 0xA0    | Filt3  | 5 Bytes  | W/R  | 0             | Filter 3                                      |
| 0xB0    | Filt4  | 5 Bytes  | W/R  | 0             | Filter 4                                      |
| 0xC0    | Filt5  | 5 Bytes  | W/R  | 0             | Filter 5                                      |

### 0x03 - CAN baudrates

| Value  | CAN Baudrate (kb/s) |
| ------ | ------------------- |
| 1      | 5                   |
| 2      | 10                  |
| 3      | 20                  |
| 4      | 25                  |
| 5      | 31.2                |
| 6      | 33                  |
| 7      | 40                  |
| 8      | 50                  |
| 9      | 80                  |
| 10     | 83.3                |
| 11     | 95                  |
| 12     | 100                 |
| 13     | 125                 |
| 14     | 200                 |
| 15     | 250                 |
| **16** | **500** (default)   |
| 17     | 666                 |
| 18     | 1000                |
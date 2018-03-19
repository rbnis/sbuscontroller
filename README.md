# Arduino SBUS Controller

This Arduino-Sketch lets you connect your SBUS compatible radio wirelessly as controller to your pc.

You just need a SBUS receiver and connect it to your Arduino and you're ready.

## Hardware Setup

1. **Uninvert the SBUS Signal *(FrSky only)***

   To uninvert your SBUS Signal have a look at [this post from Oscar Liang](https://oscarliang.com/uninverted-sbus-smart-port-frsky-receivers/) where he shows an wich pads you can get an uninderted Signal, so you dont have to use an inverter.

1. **Connect your receiver to your arduino according to this table**

   | Receiver | Arduino |
   | --- | --- |
   | Uninverted SBUS | RX |
   | 5V | RAW / 5V|
   | GND | GND |

## Software Setup

### Prerequisites

Befor you can compile this sketch you need to download the following libraries and place them in Arduino libraries folder.

* [FUTABA_SBUS](https://github.com/mikeshub/FUTABA_SBUS)
* [ArduinoJoystickLibrary](https://github.com/MHeironimus/ArduinoJoystickLibrary)

On **Linux** this folder is by deafult `$HOME/Arduino/libraries`

On **Windows** this folder is by default `%userprofile%\Documents\Arduino\libraries`

### Installation

Just upload the `sbuscontroller.ino` file to your Arduino and your good to go.

## Compatibility

### Only ATmega32U4 based arduinos (like the [arduino micro](https://store.arduino.cc/arduino-micro)) are supported, since they can be recognized as HID.

This should work on any OS with USB-Support and with any (uninverted) SBUS receiver but this is what it's tested with.

| Arduino   | Receiver | Operating System |
| :--- | :--- | :--- |
| Pro Micro | X4R-SB   | Linux |
|  |  | Windows 10 |

If you use this on any other platform please report back, so I can add it to this list.

## Limitations

Currently there are only the first 7 channels that get mapped as controller. Channel 1-6 get mapped as analog and channel 7 as digital button.

## Authors

* **Robin Tripp** - *Initial work* - [Robinhuett](https://github.com/Robinhuett)

See also the list of [contributors](https://github.com/Robinhuett/sbuscontroller/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* **mikeshub** - *[FUTABA_SBUS](https://github.com/mikeshub/FUTABA_SBUS)*
* **MHeironimus** - *[ArduinoJoystickLibrary](https://github.com/MHeironimus/ArduinoJoystickLibrary)*
* **Oscar Liang** - *[Getting Uninverted SBUS and Smart Port from Frsky Receivers](https://oscarliang.com/uninverted-sbus-smart-port-frsky-receivers/)*

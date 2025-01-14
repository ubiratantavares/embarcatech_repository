https://www.tomshardware.com/news/raspberry-pi-pico-tutorials-pinout-everything-you-need-to-know


Raspberry Pi Pico - Tutorials, Pinout, What You Need to Know (Updated)
News
By Les Pounder last updated June 30, 2022
How to make the most of the Raspberry Pi Pico and Raspberry Pi Pico W


 
 
 
 
 
 Comments (2)
When you purchase through links on our site, we may earn an affiliate commission. Here’s how it works.

Raspberry Pi Pico W
(Image credit: Tom's Hardware)
The Raspberry Pi Pico is a radical change from previous Pis, because it’s not a Linux computer, but a a microcontroller board like Arduino . The biggest selling points of the Raspberry Pi Pico are the price, $4 and the RP2040 chip which provides ample power for embedded projects and enables users of any age or ability to learn coding and electronics. If you have a Windows, Apple, Linux computer or even a different Raspberry Pi, then you are already well on your way to using the Raspberry Pi Pico in your next project. Unlike most other Raspberry Pi, the Pico comes with an unsoldered header, but using one of the best soldering irons from our list will soon see your Pico ready for big projects.

Raspberry Pi Pico W

(Image credit: Tom's Hardware)
In June 2022, Raspberry Pi announced its latest iteration, the Raspberry Pi Pico W. As you can probably guess, the W stand for Wi-Fi and this is provided via Infineon's CYW43439 chip which provides 2.4 GHz Wi-Fi using an onboard antenna. For just $6, $2 more than the original Pico, we have a low cost and easy to use IoT platform.

In our review we managed to get our Pico W online in mere moments, a combination of great hardware and an easy to use MicroPython module means the Pico W will soon be powering thousands of IoT devices across the world.

Sponsored Links
Video from our partners
Brought to you by Taboola
Jogue na maior loteria do mundo sem sair de casa!
TheLotter
Getting Started with Raspberry Pi Pico 
Raspberry Pi Pico

(Image credit: Tom's Hardware)
The Raspberry Pi Pico is vastly different from any model before it. It is the first device to use RP2040 “Pi Silicon” which is a custom System on Chip (SoC) developed by the Raspberry Pi team which features a dual core Arm Cortex M0+ running at 133 MHz, 264KB of SRAM and 2MB of flash memory used to store files. 

LATEST VIDEOS FROM tomshardware
The one downside of the Raspberry Pi Pico is that there is no wireless connectivity. Something that has since been rectified thanks to the Raspberry Pi Pico W. The RP2040 is the first microcontroller in the Pi range and this brings with it a new way of working. The Pico is not a computer, rather we need to write code in an external application on a different computer and “flash” the code to the microcontroller over USB. In our tutorial on how to get started with Raspberry Pi Pico, we explain how to connect a PC to the Pico and use it to upload MicroPython code.

Coding with the Raspberry Pi Pico 
Raspberry Pi Pico

(Image credit: Tom's Hardware)
The Pico and third-party RP2040 boards can use a variety of programming languages, include MicroPython, CircuitPython, C/C++ and Arduino language. There's even Piper Play, a block-based version of Python for the Pico.

MicroPython and C/C++ are the officially supported languages from the Pi Foundation, but CircuitPython, which is similar, has certain advantages such as its built-in support for USB HID, which means that you can turn your Pico into a keyboard, mouse or joystick that's recognized by a PC.

Stay On the Cutting Edge: Get the Tom's Hardware Newsletter
Get Tom's Hardware's best news and in-depth reviews, straight to your inbox.

Your Email Address
Contact me with news and offers from other Future brands
Receive email from us on behalf of our trusted partners or sponsors
By submitting your information you agree to the Terms & Conditions and Privacy Policy and are aged 16 or over.
MicroPython on Raspberry Pi Pico 
MicroPython is a version of Python 3 for microcontrollers. It was created by Damien George and first used with the PyBoard development board back in 2014. Since then, more devices have adopted this easy to use language and there is a further fork of MicroPython,CircuitPython created by Adafruit which adds further enhancements for their range of boards.  Writing MicroPython code for the Raspberry Pi Pico is possible using the Thonny Python IDE, which is available for all the major OSes, and it is the most accessible way to get started with your Pico. 

Firmware options for the Raspberry Pi Pico

(Image credit: Raspberry Pi LTD)
With the release of the Raspberry Pi Pico W, we now see two different firmware options, one for the new Pico W 2 and the other for the original board. In the announcement blog post, Raspberry Pi LTD CEO explains why this is required.

"This UF2 firmware we’re making available for Pico W is a separate build to the existing MicroPython firmware for our original Pico board. We’ll be upstreaming the changes to the main MicroPython repository soon after launch, but as MicroPython has separate binaries on a per-board rather than per-architecture basis there will always be two distinct UF2 firmware releases going forward. One for Pico, the other for Pico W."

A fork of MicroPython, CircuitPython has been released for RP2040 boards. Created by Adafruit, CircuitPython has an impressive library of pre-written modules for sensors, LCD / OLED / LED screens and output devices such as thermal printers. Flashing CircuitPython to the Raspberry Pi Pico is as simple as flashing MicroPython, and it is reversible should you wish to revert back to MicroPython or C/C++.

C/C++ 
Writing code in C/C++ is made possible via two methods. Firstly we can write the code directly in a text editor of our choice and then follow a workflow to build the files which are then flashed to the Pico. Or we can use a graphical workflow and have Microsoft’s Visual Studio Code handle the creation, build and flash process in one application. 

You can now now use the Arduino IDE to write code for your Pico. Arduino code is loosely a version of C/C++ so this might be a simpler way to write and upload your code.

Raspberry Pi Pico GPIO Pinout 
Raspberry Pi Pico

(Image credit: Tom's Hardware)
26 × multi-function 3.3V GPIO pins
2 × SPI, 2 × I2C, 2 × UART, 3 × 12-bit ADC, 16 × controllable PWM channels
8 × Programmable I/O (PIO) state machines for custom peripheral support.
Castellated module allows soldering directly to carrier boards.
Operating at 3.3V, the Raspberry Pi Pico and the newer Raspberry Pi Pico W both have a 40 pin GPIO. The GPIO does not share the same form factor as the Raspberry Pi that came before it. We have GPIO pins for digital inputs / outputs, pulse width modulation (PWM) and for specialist communication protocols such as I2C, SPI, UART/Serial. The GPIO also has three Analog inputs, something other Raspberry Pis lack,  that use variable voltages to connect to, for example, a potentiometers, joystick or light-dependent resistor (see resistor color codes).  

Raspberry Pi Pico

(Image credit: Tom's Hardware)
The GPIO pins themselves feature castellations, small cutouts that permit the Raspberry Pi Pico to be soldered in place into a project or carrier board.  

Raspberry Pi Pico

(Image credit: Tom's Hardware)
More importantly, we can also solder header pins to the Pico and use it in a breadboard. See our tutorial on how to solder Raspberry Pi Pico pins for more details. 

What You Do With a Raspberry Pi Pico 
Raspberry Pi Pico

(Image credit: Tom's Hardware)
Retailing for $4, the Raspberry Pi Pico is a cost effective means to tinker with electronics projects and study physical computing. 

We can use the power of Pico at the heart of robotics and motorized projects, collect data using sensors for temperature, humidity, light and pollution and we can learn the basics of programming and electronics.

The RP2040: Raspberry Pi Silicon
The Raspberry Pi Pico is the first but not the only board to use RP2040. There are around a dozen third-party boards that have been announced and three that we know have hit the market thus far. 

Our favorite third-party RP2040 board is Adafruit's Feather RP2040, which features 16MB of storage (versus 2MB on the Pico), 4 ADC channels (versus 3 on the Pico), an RGB light, a built-in Lipo battery connector and, most importantly, the ability to connect to Adafruit's huge ecosystem of Featherwing add-on boards.

We've also tested the Pimoroni Tiny RP2040, which is an extremely-small board that sports 4 ADC channels, 8MB of storage and an RGB light. SparkFun's MicroMod RP2040 puts the SoC on a tiny M.2 board which you can plug into a variety of carrier boards with different features.

Adafruit has also announced an ItsyBitsy 2040, which follows the "ItsyBitsy" form factor and a tiny QT Py 2040 board. Arduino have announced that they are working on the Arduino Nano RP2040 Connect, a variant of the RP2040 with WiFi and Bluetooth. In addition to the MicroMod, SparkFun has two other RP2040 boards coming out. 

RP2040 Board Comparison
Row 0 - Cell 0	Raspberry Pi Pico W	Raspberry Pi Pico	Adafruit Feather RP2040	Adafruit ItsyBitsy RP2040	Adafruit QT Py RP2040	Adafruit Trinkey QT2040	Arducam Pico4ML	Arduino Nano RP2040 Connect	Cytron Maker Pi Pico	Cytron Maker Pi RP2040	Pimoroni Keybow 2040	Pimorono Pico Lipo	Pimoroni Tiny 2040	SparkFun MicroMod	SparkFun Pro Micro	SparkFun Thing Plus
GPIO	26 × multi-function GPIO pins 2 × SPI, 2 × I2C, 2 × UART, 3 × 12-bit ADC, 8 × Programmable I/O (PIO) state machines for custom peripheral support Castellated module allows soldering directly to carrier boards.	26 × multi-function GPIO pins 2 × SPI, 2 × I2C, 2 × UART, 3 × 12-bit ADC, 8 × Programmable I/O (PIO) state machines for custom peripheral support Castellated module allows soldering directly to carrier boards.	21 × multi-function 2 × SPI, 2 × I2C, 2 × UART, 4 × 12-bit ADC, 16 × controllable PWM channels 8 × Programmable I/O (PIO) state machines for custom peripheral support. Castellated module allows soldering directly to carrier boards.	23 GPIO pins 16 x PWM outputs 10 x Digital I/O, 4 x Analog 12-bit ADC, 2 x I2C, SPI, 2 x UART, 10 x Programmable IO	11 GPIO pins. 7 x Digital I/O, 4 x Analog 12-bit ADC, 2 x I2C (including Stemma QT), SPI, UART, 6 x Programmable IO.	Stemma QT / Qwiic connector	26 × multi-function GPIO pins 2 × SPI, 2 × I2C, 2 × UART, 3 × 12-bit ADC, 16 × controllable. 8 × Programmable I/O (PIO) state machines for custom peripheral support	20× multi-function 3.3V GPIO pins 1× SPI, 1 × I2C, 1 × UART, 8 × 12-bit ADC, 20 × controllable PWM channels 8× Programmable I/O (PIO) state machines for custom peripheral support. 1x User LED (GPIO 13)	26 × multi-function GPIO pins 2 × SPI, 2 × I2C, 2 × UART, 3 × 12-bit ADC, 16 × controllable. 8 × Programmable I/O (PIO) state machines for custom peripheral support	No direct GPIO access, 7 x Grove connectors provide GPIO access 4 x Servo headers, can be used as GPIO	A small selection of GPIO is broken out for use. I2C, Serial / UART. Access to these pins requires soldering.	26 × multi-function GPIO pins 2 × SPI, 2 × I2C, 2 × UART, 3 × 12-bit ADC, 16 × controllable. 8 × Programmable I/O (PIO) state machines for custom peripheral support	12 GPIO pins. 7 x Digital I/O, 4 x Analog 12-bit ADC, 2 x I2C, SPI, UART, Debug	30 × multi-function GPIO pins 2 × SPI, 2 × I2C, 2 × UART, 3 × 12-bit ADC, 16 × PWM controllable. 8 × Programmable I/O (PIO) state machines for custom peripheral support	20 × multi-function GPIO pins 1 × SPI, 1 × I2C (Qwiic), 2 × UART, 4 × 12-bit ADC, 10 × PWM controllable. 8 × Programmable I/O (PIO) state machines for custom peripheral support	18 × multi-function GPIO pins 2 × SPI, 2 × I2C (Qwiic), 2 × UART, 4 × 12-bit ADC, 8 × PWM controllable. 8 × Programmable I/O (PIO) state machines for custom peripheral support
Flash Storage	2MB	2MB	8MB	8MB	8MB	8MB	2MB	16MB	2MB	2MB	2MB	4 / 16MB	8MB	16MB	16MB	16MB
Wi-Fi / Bluetooth	Infineon CYW43439 2.4 GHz Wi-Fi with onboard antenna	N/A	N/A	N/A	N/A	N/A	N/A	Nina W102 uBlox Wi-Fi module Bluetooth / BLE 4.2	Via ESP01 / ESP8266	N/A	N/A	N/A	N/A	N/A	N/A	N/A
Extra Feautres	N/A	N/A	1 x WS2812B Neopixel STEMMA QT / Qwiic connector Onboard battery charging and support for hot swappable LiPo and Lilon batteries.	1 x WS2812B NeoPixel	1 x WS2812B NeoPixel Stemma QT / Qwiic connector	USB A connector Stacking Stemma QT boards	HiMax HM01B0, Up to QVGA (320 x 240 @60fps) 0.96 inch LCD SPI Display (160 x 80, ST7735) 3-Axis Gyroscope 3-Axis Accelerometer 3-Axis Compass Mems Microphone	ST LSM6DSOXTR 6-axis IMU ST MP34DT06JTR MEMS Microphone ATECC608A-MAHDA-T Cryptographic Coprocessor	Micro SD card reader 6 x Grove Connectors Onboard test LEDs Audio output via 3.5mm jack and buzzer RGB LED User Buttons	MX1508 Motor Controller with two DC motor outputs and motor test buttons LiPo charging 2 x WS2812B NeoPixel RGB LEDs	16 Kailh hot swappable keys 16 RGB LEDs	MCP73831 charger with 215mA charging current. XB6096I2S battery protector Stemma QT / Qwiic Connector Power button LED Status Indicators	User controllable RGB LED	MicroMod follows an M.2 form factor and as such is designed for use in carrier boards that add extra features.	WS2812 Addressable LED Qwiic / Stemma QT breakout	LiPo battery charging Charge and Status LEDs WS2812 Addressable LED
USB Port	Micro USB	Micro USB	USB-C	USB-C	USB-C	USB-A	Micro USB	Micro USB	Micro USB	Micro USB	USB-C	USB-C	USB-C	Carrier board dependent	USB-C	USB-C
Dimensions	51 x 21 mm	51 x 21 mm	50.8 x 22.8 mm	36 x 18 mm	22 x 18 mm	2.54 x 17.8 mm	51 x 21 mm	45 x 18 mm	94 x 68 mm	88 x 64 mm	76 x 76 mm	53 x 21 mm	22.9 x 18.2 mm	22 x 22 mm	33 x 17.8 mm	58.4 x 22.8 mm
Accessories and Add-ons
Image 1 of 6
Pimoroni Pico Accessories
(Image credit: Pimoroni)

Pimoroni Pico Accessories
(Image credit: Pimoroni)

Pimoroni Pico Accessories
(Image credit: Pimoroni)

Pimoroni Pico Accessories
(Image credit: Pimoroni)

Pimoroni Pico Accessories
(Image credit: Pimoroni)

Pimoroni Pico Accessories
(Image credit: Pimoroni)

First and third part accessories are the life blood of the Raspberry Pi and maker communities. They bring extra features and enable projects to be realised more easily. 

With the Raspberry Pi Pico's new form factor there is a need for new accessories and the first to market at Pimoroni, a UK based official Raspberry Pi reseller. They have released 12 new accessories for the Pico that range from simple breakout boards enabling multiple addons to be used at once, to advanced audio output devices and a VGA Demo board which uses the Programmable IO of the RP2040 to create DVI video signals. If your interests are more LED inclined then the Unicorn Pack sees 112 RGB LEDs ready to dazzle your eyeballs. 

We've had a chance to review several Pico accessories, including:

Seeed Grove Shield for Raspberry Pi Pico Review
Pimoroni Pico Display Review
Pimoroni Pico Explorer Base Review
Red Robotics Pico 2 Review: Use HATs with Pico
Cytron Maker Pi Pico Review
Pimoroni Keybow 2040 Review: 2040-powered Keypad
Kitronik Pico Motor Driver and Robotics Board Review
Pimoroni Pico Wireless Review
Uctronics TinyML Learning Kit Review
Red Robotics Pico 2 Pi Review
Tutorials and Support
The best things about Raspberry Pi is the great community and the thousands of tutorials that have been created. From basic to complex there are great tutorials to help you learn new skills. 

In the relatively short time that the Pico has been on the market, the Raspberry Pi community has already developed a ton of resources. At Tom's Hardware, we've been publishing our fair share of Pico how-tos, which you can find below. 

How to Set Up and Program Raspberry Pi Pico
How To Solder Pins to Your Raspberry Pi Pico
How to Get Wi-Fi, Internet on Raspberry Pi Pico
How to Program Raspberry Pi Pico with Arduino IDE
How to Build a Raspberry Pi Pico Weather Station
How to Connect an Analog Joystick to a Raspberry Pi Pico
How to Use Your Raspberry Pi Pico With DC Motors
How to Use a Motion Sensor with Raspberry Pi Pico
How to Use an Ultrasonic Sensor with Raspberry Pi Pico
How to Use an OLED Display with Raspberry Pi Pico
How to Use a 7-Segment Display with Raspberry Pi Pico
How to Reset Your Raspberry Pi Pico With a Button
How to Use an I2C LCD Display With Raspberry Pi Pico
How To Build A Simple Raspberry Pi Pico Robot


https://www.tomshardware.com/reviews/raspberry-pi-pico-w

Raspberry Pi Pico W Review - Built-in Wi-Fi Comes to Pico
For just $6, you get a Wi-Fi-enabled microcontroller.
Reviews
By Les Pounder
last updated June 30, 2022
 
 
 
 
 
 Comments (3)
When you purchase through links on our site, we may earn an affiliate commission. Here’s how it works.

Raspberry Pi Pico WEditor's Choice
(Image: © Tom's Hardware)
Tom's Hardware Verdict
Solid hardware, good software, and Wi-Fi access see this incremental update elevate the Raspberry Pi Pico to a truly versatile development board.

Pros
+Solid hardware
+Backwards compatibility
+Wi-Fi connects effortlessly
 
Cons
-No Bluetooth
-Micro USB
Why you can trust Tom's Hardware  Our expert reviewers spend hours testing and comparing products and services so you can choose the best for you. Find out more about how we test.

It is fair to say that when the Raspberry Pi Pico arrived in late January 2021, it had two glaring omissions. First was a lack of reset button (of course you can add your own) but the biggest omission was Wi-Fi. In an age of thumbnail sized IoT boards, it felt like the Raspberry Pi Pico was behind the times. In our Raspberry Pi Pico review we marked the lack of Wi-Fi as a con, but we still love the $4 microcontroller that brought the RP2040 SoC to the world.

With a surprise June 2022 release, we see a new Raspberry Pi Pico, this time correcting one of the omissions. The Raspberry Pi Pico W is a $6 microcontroller that looks much like its predecessor, but under a tiny silver case lies a Wi-Fi chip which takes the Pico into the world of IoT. It may not be the first RP2040 board to offer Wi-Fi –  but we are sure that the Raspberry Pi Pico W is going to go straight onto our list of best RP2040 boards.

Image 1 of 3
Raspberry Pi Pico W
(Image credit: Tom's Hardware)

Raspberry Pi Pico W
(Image credit: Tom's Hardware)

Raspberry Pi Pico W
(Image credit: Tom's Hardware)

During the global chip shortage, Raspberry Pi’s RP2040 SoC has been in plentiful supply. Raspberry Pi even used the chip in its Build HAT Lego compatible board for the Raspberry Pi due to dwindling STM32 microcontroller stocks. Pi Founder and CEO Eben Upton has said that they can make thousands of RP2040 chips. This is in stark contrast to other Raspberry Pis which are often in short supply. The Raspberry Pi Pico W could replace many Raspberry Pi Zero W based projects, such as low powered robots and data collection projects. 

Sponsored Links
Video from our partners
Brought to you by Taboola
Jogue na maior loteria do mundo sem sair de casa!
TheLotter
Raspberry Pi Pico W

(Image credit: Tom's Hardware)
Is the Raspberry Pi Pico W  better than the original? Should we throw away our old Picos? Can we connect to the world? To learn all this and more we need to put it on the bench. 

LATEST VIDEOS FROM tomshardware
Raspberry Pi Pico W Hardware Specifications
Header Cell - Column 0	Raspberry Pi Pico W	Raspberry Pi Pico
SoC	RP2040 Arm Cortex M0+ Dual Core at 133 MHz	RP2040 Arm Cortex M0+ Dual Core at 133 MHz
RAM	264KB SRAM	264KB SRAM
Storage	2MB Flash	2MB Flash
Connectivity	Infineon CYW43439 2.4 GHz Wi-Fi with onboard antenna	None
 	Connected via SPI	 
GPIO	40 Pin GPIO	40 Pin GPIO
 	26 Multi-function pins	26 Multi-function pins
 	23 x Digital I/O	23 x Digital I/O
 	3 x Analog Inputs	3 x Analog Inputs
 	2 x I2C	2 x I2C
 	2 x SPI	2 x SPI
 	2 x UART	2 x UART
 	1 x Arm Serial Wire Debug (SWD)	1 x Arm Serial Wire Debug (SWD)
Power / Data	Micro USB for data and power	Micro USB for data and power
Dimensions	51 x 21 mm	51 x 21 mm
Price	$6	$4
As you can see there isn’t really much difference between the original Raspberry Pi Pico and the new Pico W. We have the same GPIO, microUSB port, dimensions and SoC. The only difference is the inclusion of Infineon’s CYW43439 2.4-GHz Wi-Fi chip. Looking at Infineon’s datasheet for this chip, we spotted that it also is capable of transmittingBluetooth 5.2, but in the Raspberry Pi documentation, there is no mention of this. Upton told us that  Bluetooth is not as of yet enabled in the Pico W’s firmware. How long until some enterprising hackers enable Bluetooth on the Pico W for themselves? We shall wait and see.

Getting online with the Raspberry Pi Pico W
If you have ever used an ESP8266, ESP32 or other MicroPython compatible Wi-Fi dev board, then you’ll notice that the Pico W is exactly the same. We followed the example script to connect to our Wi-Fi network  and noticed that it was stock MicroPython.All it took were five lines of MicroPython and our Raspberry Pi Pico W was happily connected to the Internet.

import network
wlan = network.WLAN(network.STA_IF)
wlan.active(True)
wlan.connect("SSID","PASSWORD")
print(wlan.isconnected())
Raspberry Pi Pico W

(Image credit: Tom's Hardware)
We then tested our connection using uPing from Shawwwn which mimics the ping command. We confirmed that we had a connection to the wider world, and this really opens up the possibilities of the Pico W.

Raspberry Pi Pico W

(Image credit: Tom's Hardware)
Taking the test further, we used urequests, a network request module, to download data on air raid siren status in Ukraine. We got the data as JSON, saved it into a dictionary. We then used the Ukrainian city, Kharkiv as the key to search the dictionary for its status. This status was then displayed in the Python REPL, and via a strip of NeoPixel LEDs.

Can we take our tests further? Sure! We installed a version of uMQTT, a version of MQTT (Message Query Telemetry Transport, a publish / subscribe data communication protocol) and used our own broker. Our Pico W would publish a message using a specific topic, the broker would then send that message to a subscriber. In this case our subscriber was my laptop running Node-RED. The message made it through the network, and appeared in the debug area of Node-RED. 

Raspberry Pi Pico W

(Image credit: Tom's Hardware)
Why is this important? Well now we have a $6 IoT board from Raspberry Pi Ltd that can use a plethora of sensors and then send the data over a reliable network, where it can be collated and worked on. We no longer have the overhead of a full Linux OS to deal with. All of this is done on a $6 microcontroller instead of a $10 to $15 single board computer.

The ease with which we got online was astounding. Though we have plenty of experience with MicroPython’s network module, even a beginner would be able to write and understand the five lines of code needed to make the connection. This is what the Raspberry Pi Pico should’ve had from day one. But for the original $4 price point there had to be a sacrifice, and Wi-Fi was it.

The nearest Raspberry Pi we can compare to the Raspberry Pi Pico W is the original Raspberry Pi Zero W and its newer incarnation the Raspberry Pi Zero 2 W. Computationally, the Pico W is slow, even compared to the Zero W, but if we don’t need the horsepower and bloat of a full Linux OS, or if your project doesn’t need a camera, then the Pico W makes sense. It is cheap, low power and can be used with many of the sensors and inputs used on the Zero W. If all we are doing is collecting temperature / humidity and air pressure data, do we need a Linux OS? 

General use of the Raspberry Pi Pico W
The Raspberry Pi Pico W comes just like any other Pico, with no header pins. This means that we need to break out the soldering iron and solder up the 40 GPIO pins ready for the breadboard. We did just that using our Pinecil soldering iron and after connecting via the micro USB port (we still wish the Pico had USB-C), we then hooked up a strip of WS2812B (NeoPixels) for a project. Using a community created MicroPython library we soon had those RGB LEDs color changing and pulsing with light.

Image 1 of 3
Raspberry Pi Pico W
(Image credit: Tom's Hardware)

Raspberry Pi Pico W
(Image credit: Tom's Hardware)

Raspberry Pi Pico W
(Image credit: Tom's Hardware)

For basic electronics and breadboarding projects, the Raspberry Pi Pico W behaves exactly like its predecessor. We wrote a few lines to “blink” and LED on and off to prove that our hardware was working.The Pico W GPIO pinout is the same so all you need to do is flash your code onto the Pico W, replace the older Pico and away you go. We also tested I2C connectivity using an I2C HD44780 16 x 2 LCD screen and it worked with zero issues. 

The Raspberry Pi Pico introduced analog inputs to a Raspberry Pi board, and the Pico W retains those same three analog inputs. We mocked up a quick demo using a 10K Ohm potentiometer (a variable resistor with resistance between 0 and 10 Kiloohm) and were able to see raw ADC values scrolling along the REPL. 

Raspberry Pi Pico W Software Support
The Raspberry Pi Pico may have been released with support for just MicroPython and C++, but in a very short amount of time we saw support for many alternative programming languages. First off there was CircuitPython, a fork of MicroPython under the stewardship of Adafruit and Scott Shawcroft. 

CircuitPython is the pinnacle of easy to use and it has become our preferred means to code for the Pico. At the time of writing there is no version for the Raspberry Pi Pico W, but we believe that will change once the board is officially released. 

The Raspberry Pi Pico W does support C/C++ but we have been unable to test this given time constraints. While C/C++ does offer an improved level of performance, many users will favor MicroPython / CircuitPython for its ease of use. The version of MicroPython provided on our review model was “MicroPython v1.18-673-gdf8d97171 on 2022-06-24”, a fairly recent release which supports the Pico W hardware. MicroPython on the Pico W worked exceptionally well with Thonny, the chosen editor for Pico MicroPython development.

What about add on boards? The identical GPIO pinout lends itself to reusing our old Pico addons. Right now, the various third-party resellers are playing catch up. A new Raspberry Pi Pico W means they will have to test and update their software in order for us to reuse our old kit. Resellers often bundle its libraries into a bespoke firmware which can be flashed to the Pico as a UF2 file. For now we cannot reliably test addons, but we shall and provide you with the information in a future update.

Other Wi-Fi Enabled Development Boards
Raspberry Pi Pico W

(Image credit: Tom's Hardware)
In the time that the Pico has been with us, there have been a few notable attempts to add Wi-Fi connectivity to Raspberry Pi’s RP2040 processor The first was via Adafruit’s Airlift Featherwing Co-Processor. We managed to connect to and use this board with a Raspberry Pi Pico. A more “refined” alternative came in the form of Pimoroni’s Pico Wireless, which came as a “pack” that slotted over the entire GPIO. While easy to use, we had no GPIO to play with.

Raspberry Pi Pico W

(Image credit: Tom's Hardware)
Until now, the most obvious choice was Arduino’s Nano RP2040 Connect, which retails for $28, over four times the cost of the Pico W. Arduino’s board comes with Wi-Fi and Bluetooth, an IMU, microphone and a cryptographic coprocessor which could offset the higher cost.

If you need professional features, by all means go for the Arduino Nano RP2040 Connect, but most folks will probably find the Pico W a better value.

Raspberry Pi Pico W

(Image credit: Tom's Hardware)
Some makers may now be thinking that you can buy an ESP32, ESP8266, W600 etc for around the same price. You are quite correct. I am also part of those communities and share a love for those boards, one of which powers the decorations at Christmas time. 

For those of us who are seasoned with Wi-Fi development boards, the Pico W is more of a curiosity. For $6 we can dip our toe and spend a pleasant afternoon hacking around. But for those of us new to the scene, and that is where a good percentage of Pi users come from, the ease of use and price of the Raspberry Pi Pico W are backed up with lots of tutorials and forum posts already in the general public’s vision.

What Projects Can We Build With the Raspberry Pi Pico W?
The world is our oyster! With Wi-Fi connectivity we can now build remote control robots, gather data and transmit it to the world, gather information and display it on LCD and OLED displays. For $6 we have a powerful microcontroller (it can even play Doom!) with enough smarts for machine learning and computer vision. 

The addition of Wi-Fi will see the Raspberry Pi Pico W powering many projects which ultimately would’ve been powered by the $10 Raspberry Pi Zero W. The Pico W will be an even more compelling board if and when someone enables its Bluetooth 5.2 capability. With Bluetooth, one could turn the Pico W into a wireless computer peripheral such as a game controller or mouse.

Bottom Line
Raspberry Pi Pico W

(Image credit: Tom's Hardware)
At $4 the Raspberry Pi Pico was a good investment. At $6 the Raspberry Pi Pico W is a great investment. If you know the Pico, then you will have no trouble with the Raspberry Pi Pico W. New users will pick it up relatively quickly thanks to a multitude of guides and resources. 

Raspberry Pi has a track record of coming without power buttons, and the lack of a reset switch is still a glaring omission, we don’t like unplugging the cable each time we need to reset, but we can forgive Pico W.

The Raspberry Pi Pico W is the ideal starter microcontroller. We have solid hardware, good software (it will get even better with time) and compatibility with accessories and addons that ultimately we will already own. Right now $6 doesn’t buy you much, but with the Raspberry Pi Pico W we get the world.



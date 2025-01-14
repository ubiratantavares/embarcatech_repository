https://how2electronics.com/raspberry-pi-pico-w-send-bme280-sensor-data-to-blynk-2-0/

Raspberry Pi Pico W send BME280 Sensor Data to Blynk 2.0
AdminBy AdminUpdated:March 8, 20233 Comments6 Mins Read
Share
BME280 Raspberry Pi Pico W Blynk
Share

Overview
In this project, we will learn how to send BME280 Sensor Weather Station Data to Blynk 2.0 Applications using the WiFi capability of Raspberry Pi Pico W.

The BME280 sensor is a versatile and widely-used environmental sensor that measures temperature, humidity, and barometric pressure. When combined with the Raspberry Pi Pico W microcontroller, it can be used to create a powerful and cost-effective weather monitoring system. By connecting this system to the Blynk app, it is possible to remotely monitor and visualize weather data in real time.

Blynk is a popular platform for building IoT applications that enable users to remotely control and monitor a wide range of devices. With Blynk, users can create custom dashboards, receive push notifications, and even trigger actions based on sensor data. By integrating the BME280 sensor with the Raspberry Pi Pico W microcontroller and the Blynk app, it is possible to create a weather monitoring system that can be accessed from anywhere in the world. This type of system can be useful for a variety of applications, from agriculture and environmental monitoring to personal weather tracking.

Bill of Materials
In this guide, I used SunFounder Raspberry Pi Pico W Kit to test different Modules. You can buy the kit and perform some other operations as well. From this kit, you can use the following components.

Raspberry Pi Pico W- 1
BME280 Sensor – 1
Jumper Wires – 10
Breadbaord – 1
Micro-USB Cable – 1




BME280 Barometric Pressure Sensor
The BME280 is Barometric Pressure Sensor that can measure temperature, Humidity & Atmospheric Pressure. The Sensor has an I2C Bus and operates on 3.3V Power Supply. The unit combines high linearity and high accuracy sensors and is perfectly feasible for low current consumption, long-term stability, and high EMC robustness.



This sensor is simple to use, comes pre-calibrated, and requires no additional components, so you can start measuring relative humidity, temperature, barometric pressure, and altitude in no time.

The sensor is best for measuring humidity with ±3% accuracy, barometric pressure with ±1 hPa absolute accuracy, and temperature with ±1.0°C accuracy. Because pressure changes with altitude and the pressure measurements are so good, you can also use it as an altimeter with ±1 meter or better accuracy.

To learn more about the BME280 Sensor refer to the BME280 datasheet or you may follow the BME280 Raspberry Pi Pico interfacing guide.

Interfacing BME280 Sensor with Raspberry Pi Pico W
Let us connect the BME280 Barometric Pressure Sensor with Raspberry Pi Pico W via I2C pins. This sensor communicates using the I2C communication protocol, so the wiring is very simple.

BME280 Raspberry Pi Pico W

Raspberry Pi Pico W has multiple I2C pins, you may use any. Connect the VCC, GND, SCL & SDA pin of BME280 Sensor to 3.3V, GND, GP21 & GP20 of Raspberry Pi Pico W respectively.

BME280 Raspberry Pi Pico W IoT Weather Station






Setting up Blynk 2.0 Application
To control the 4 Home Appliances using Blynk and Raspberry Pi Pico W, you need to create a Blynk project and set up a dashboard in the mobile or web application. Here’s how you can set up the dashboard:

Visit blynk.cloud and create a Blynk account on the Blynk website. Or you can simply sign in using the registered Email ID.

Click on +New Template.



Give any name to the Hardware. Choose the Hardware type as Other and the connection type as WiFi.



The template is created successfully.



Now we need to add New Devices here.



Select the device from a template that you created earlier.



Give any name and click on Create.



A device authentication token is generated now. Copy this token as this will be used in the code.



Now go to the Web Dashboard.



In the Web Dashboard, drag and drop 3 widgets Gauge on the dashboard.



You need to set all the 3 widgets one by one. Assign virtual pin V0, V1 and V2 to Temperature, Humidity and Pressure values.



The Blynk Dashboard setup is successfully completed now.

MicroPython Code
If you are a beginner and want to learn how to get started with Raspberry Pi Pico W, you may refer to the Getting Started guide.

The code for interfacing the BME280 Sensor with Raspberry Pi Pico W & sending the sensor data to Blynk Dashboard is divided into 3 parts:

bme280.py
BlynkLib.py
main.py




bme280.py
The library to read from the BME280 sensor isn’t part of the standard MicroPython library by default. So, you need to upload the BME280 MicroPython library to your Raspberry Pi Pico W Board. The library has all the required modules and registers details to extract the data from the Sensor.

Open your Thonny IDE and paste the following code to the Thonny Editor. Save the file in the Raspberry Pi Pico W and name it bme280.py.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
import time
from ustruct import unpack, unpack_from
from array import array
 
# BME280 default address.
BME280_I2CADDR = 0x76
 
# Operating Modes
BME280_OSAMPLE_1 = 1
BME280_OSAMPLE_2 = 2
BME280_OSAMPLE_4 = 3
BME280_OSAMPLE_8 = 4
BME280_OSAMPLE_16 = 5
 
BME280_REGISTER_CONTROL_HUM = 0xF2
BME280_REGISTER_CONTROL = 0xF4
 
 
class BME280:
 
    def __init__(self,
                 mode=BME280_OSAMPLE_1,
                 address=BME280_I2CADDR,
                 i2c=None,
                 **kwargs):
        # Check that mode is valid.
        if mode not in [BME280_OSAMPLE_1, BME280_OSAMPLE_2, BME280_OSAMPLE_4,
                        BME280_OSAMPLE_8, BME280_OSAMPLE_16]:
            raise ValueError(
                'Unexpected mode value {0}. Set mode to one of '
                'BME280_ULTRALOWPOWER, BME280_STANDARD, BME280_HIGHRES, or '
                'BME280_ULTRAHIGHRES'.format(mode))
        self._mode = mode
        self.address = address
        if i2c is None:
            raise ValueError('An I2C object is required.')
        self.i2c = i2c
 
        # load calibration data
        dig_88_a1 = self.i2c.readfrom_mem(self.address, 0x88, 26)
        dig_e1_e7 = self.i2c.readfrom_mem(self.address, 0xE1, 7)
        self.dig_T1, self.dig_T2, self.dig_T3, self.dig_P1, \
            self.dig_P2, self.dig_P3, self.dig_P4, self.dig_P5, \
            self.dig_P6, self.dig_P7, self.dig_P8, self.dig_P9, \
            _, self.dig_H1 = unpack("<HhhHhhhhhhhhBB", dig_88_a1)
 
        self.dig_H2, self.dig_H3 = unpack("<hB", dig_e1_e7)
        e4_sign = unpack_from("<b", dig_e1_e7, 3)[0]
        self.dig_H4 = (e4_sign << 4) | (dig_e1_e7[4] & 0xF)
 
        e6_sign = unpack_from("<b", dig_e1_e7, 5)[0]
        self.dig_H5 = (e6_sign << 4) | (dig_e1_e7[4] >> 4)
 
        self.dig_H6 = unpack_from("<b", dig_e1_e7, 6)[0]
 
        self.i2c.writeto_mem(self.address, BME280_REGISTER_CONTROL,
                             bytearray([0x3F]))
        self.t_fine = 0
 
        # temporary data holders which stay allocated
        self._l1_barray = bytearray(1)
        self._l8_barray = bytearray(8)
        self._l3_resultarray = array("i", [0, 0, 0])
 
    def read_raw_data(self, result):
        """ Reads the raw (uncompensated) data from the sensor.
 
            Args:
                result: array of length 3 or alike where the result will be
                stored, in temperature, pressure, humidity order
            Returns:
                None
        """
 
        self._l1_barray[0] = self._mode
        self.i2c.writeto_mem(self.address, BME280_REGISTER_CONTROL_HUM,
                             self._l1_barray)
        self._l1_barray[0] = self._mode << 5 | self._mode << 2 | 1
        self.i2c.writeto_mem(self.address, BME280_REGISTER_CONTROL,
                             self._l1_barray)
 
        sleep_time = 1250 + 2300 * (1 << self._mode)
        sleep_time = sleep_time + 2300 * (1 << self._mode) + 575
        sleep_time = sleep_time + 2300 * (1 << self._mode) + 575
        time.sleep_us(sleep_time)  # Wait the required time
 
        # burst readout from 0xF7 to 0xFE, recommended by datasheet
        self.i2c.readfrom_mem_into(self.address, 0xF7, self._l8_barray)
        readout = self._l8_barray
        # pressure(0xF7): ((msb << 16) | (lsb << 8) | xlsb) >> 4
        raw_press = ((readout[0] << 16) | (readout[1] << 8) | readout[2]) >> 4
        # temperature(0xFA): ((msb << 16) | (lsb << 8) | xlsb) >> 4
        raw_temp = ((readout[3] << 16) | (readout[4] << 8) | readout[5]) >> 4
        # humidity(0xFD): (msb << 8) | lsb
        raw_hum = (readout[6] << 8) | readout[7]
 
        result[0] = raw_temp
        result[1] = raw_press
        result[2] = raw_hum
 
    def read_compensated_data(self, result=None):
        """ Reads the data from the sensor and returns the compensated data.
 
            Args:
                result: array of length 3 or alike where the result will be
                stored, in temperature, pressure, humidity order. You may use
                this to read out the sensor without allocating heap memory
 
            Returns:
                array with temperature, pressure, humidity. Will be the one from
                the result parameter if not None
        """
        self.read_raw_data(self._l3_resultarray)
        raw_temp, raw_press, raw_hum = self._l3_resultarray
        # temperature
        var1 = ((raw_temp >> 3) - (self.dig_T1 << 1)) * (self.dig_T2 >> 11)
        var2 = (((((raw_temp >> 4) - self.dig_T1) *
                  ((raw_temp >> 4) - self.dig_T1)) >> 12) * self.dig_T3) >> 14
        self.t_fine = var1 + var2
        temp = (self.t_fine * 5 + 128) >> 8
 
        # pressure
        var1 = self.t_fine - 128000
        var2 = var1 * var1 * self.dig_P6
        var2 = var2 + ((var1 * self.dig_P5) << 17)
        var2 = var2 + (self.dig_P4 << 35)
        var1 = (((var1 * var1 * self.dig_P3) >> 8) +
                ((var1 * self.dig_P2) << 12))
        var1 = (((1 << 47) + var1) * self.dig_P1) >> 33
        if var1 == 0:
            pressure = 0
        else:
            p = 1048576 - raw_press
            p = (((p << 31) - var2) * 3125) // var1
            var1 = (self.dig_P9 * (p >> 13) * (p >> 13)) >> 25
            var2 = (self.dig_P8 * p) >> 19
            pressure = ((p + var1 + var2) >> 8) + (self.dig_P7 << 4)
 
        # humidity
        h = self.t_fine - 76800
        h = (((((raw_hum << 14) - (self.dig_H4 << 20) -
                (self.dig_H5 * h)) + 16384)
              >> 15) * (((((((h * self.dig_H6) >> 10) *
                            (((h * self.dig_H3) >> 11) + 32768)) >> 10) +
                          2097152) * self.dig_H2 + 8192) >> 14))
        h = h - (((((h >> 15) * (h >> 15)) >> 7) * self.dig_H1) >> 4)
        h = 0 if h < 0 else h
        h = 419430400 if h > 419430400 else h
        humidity = h >> 12
 
        if result:
            result[0] = temp
            result[1] = pressure
            result[2] = humidity
            return result
 
        return array("i", (temp, pressure, humidity))
 
    @property
    def values(self):
        """ human readable values """
 
        t, p, h = self.read_compensated_data()
 
        p = p // 256
        pi = p // 100
        pd = p - pi * 100
 
        hi = h // 1024
        hd = h * 100 // 1024 - hi * 100
        return ("{}*C".format(t / 100), "{}.{:02d} hPa".format(pi, pd),
                "{}.{:02d} %".format(hi, hd))
BlynkLib.py
This library provides an API that enables connectivity between your IoT hardware, which supports Micropython/Python, and the Blynk Cloud. With this API, you can send both raw and processed sensor data and remotely control any connected hardware (such as relays, motors, and servos) from anywhere in the world using the Blynk mobile apps available on both iOS and Android.

Copy the following code and save it to your Raspberry Pi Pico W board with name ‘BlynkLib.py’.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189
190
191
192
193
194
195
196
197
198
199
200
201
202
203
204
205
206
207
208
209
210
211
212
213
214
215
216
217
218
219
220
221
222
223
224
225
226
227
228
229
230
231
232
233
234
235
236
237
238
239
240
241
242
243
244
245
246
247
248
249
250
251
252
253
254
255
256
257
258
259
260
261
262
263
264
# Copyright (c) 2015-2019 Volodymyr Shymanskyy. See the file LICENSE for copying permission.
 
__version__ = "1.0.0"
 
import struct
import time
import sys
import os
 
try:
    import machine
    gettime = lambda: time.ticks_ms()
    SOCK_TIMEOUT = 0
except ImportError:
    const = lambda x: x
    gettime = lambda: int(time.time() * 1000)
    SOCK_TIMEOUT = 0.05
 
def dummy(*args):
    pass
 
MSG_RSP = const(0)
MSG_LOGIN = const(2)
MSG_PING  = const(6)
 
MSG_TWEET = const(12)
MSG_NOTIFY = const(14)
MSG_BRIDGE = const(15)
MSG_HW_SYNC = const(16)
MSG_INTERNAL = const(17)
MSG_PROPERTY = const(19)
MSG_HW = const(20)
MSG_HW_LOGIN = const(29)
MSG_EVENT_LOG = const(64)
 
MSG_REDIRECT  = const(41)  # TODO: not implemented
MSG_DBG_PRINT  = const(55) # TODO: not implemented
 
STA_SUCCESS = const(200)
STA_INVALID_TOKEN = const(9)
 
DISCONNECTED = const(0)
CONNECTING = const(1)
CONNECTED = const(2)
 
print("""
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \\/  '_/
 /____/_/\\_, /_//_/_/\\_\\
        /___/ for Python v""" + __version__ + " (" + sys.platform + ")\n")
 
class EventEmitter:
    def __init__(self):
        self._cbks = {}
 
    def on(self, evt, f=None):
        if f:
            self._cbks[evt] = f
        else:
            def D(f):
                self._cbks[evt] = f
                return f
            return D
 
    def emit(self, evt, *a, **kv):
        if evt in self._cbks:
            self._cbks[evt](*a, **kv)
 
 
class BlynkProtocol(EventEmitter):
    def __init__(self, auth, tmpl_id=None, fw_ver=None, heartbeat=50, buffin=1024, log=None):
        EventEmitter.__init__(self)
        self.heartbeat = heartbeat*1000
        self.buffin = buffin
        self.log = log or dummy
        self.auth = auth
        self.tmpl_id = tmpl_id
        self.fw_ver = fw_ver
        self.state = DISCONNECTED
        self.connect()
 
    def virtual_write(self, pin, *val):
        self._send(MSG_HW, 'vw', pin, *val)
 
    def send_internal(self, pin, *val):
        self._send(MSG_INTERNAL,  pin, *val)
 
    def set_property(self, pin, prop, *val):
        self._send(MSG_PROPERTY, pin, prop, *val)
 
    def sync_virtual(self, *pins):
        self._send(MSG_HW_SYNC, 'vr', *pins)
 
    def log_event(self, *val):
        self._send(MSG_EVENT_LOG, *val)
 
    def _send(self, cmd, *args, **kwargs):
        if 'id' in kwargs:
            id = kwargs.get('id')
        else:
            id = self.msg_id
            self.msg_id += 1
            if self.msg_id > 0xFFFF:
                self.msg_id = 1
                
        if cmd == MSG_RSP:
            data = b''
            dlen = args[0]
        else:
            data = ('\0'.join(map(str, args))).encode('utf8')
            dlen = len(data)
        
        self.log('<', cmd, id, '|', *args)
        msg = struct.pack("!BHH", cmd, id, dlen) + data
        self.lastSend = gettime()
        self._write(msg)
 
    def connect(self):
        if self.state != DISCONNECTED: return
        self.msg_id = 1
        (self.lastRecv, self.lastSend, self.lastPing) = (gettime(), 0, 0)
        self.bin = b""
        self.state = CONNECTING
        self._send(MSG_HW_LOGIN, self.auth)
 
    def disconnect(self):
        if self.state == DISCONNECTED: return
        self.bin = b""
        self.state = DISCONNECTED
        self.emit('disconnected')
 
    def process(self, data=None):
        if not (self.state == CONNECTING or self.state == CONNECTED): return
        now = gettime()
        if now - self.lastRecv > self.heartbeat+(self.heartbeat//2):
            return self.disconnect()
        if (now - self.lastPing > self.heartbeat//10 and
            (now - self.lastSend > self.heartbeat or
             now - self.lastRecv > self.heartbeat)):
            self._send(MSG_PING)
            self.lastPing = now
        
        if data != None and len(data):
            self.bin += data
 
        while True:
            if len(self.bin) < 5:
                break
 
            cmd, i, dlen = struct.unpack("!BHH", self.bin[:5])
            if i == 0: return self.disconnect()
                      
            self.lastRecv = now
            if cmd == MSG_RSP:
                self.bin = self.bin[5:]
 
                self.log('>', cmd, i, '|', dlen)
                if self.state == CONNECTING and i == 1:
                    if dlen == STA_SUCCESS:
                        self.state = CONNECTED
                        dt = now - self.lastSend
                        info = ['ver', __version__, 'h-beat', self.heartbeat//1000, 'buff-in', self.buffin, 'dev', sys.platform+'-py']
                        if self.tmpl_id:
                            info.extend(['tmpl', self.tmpl_id])
                            info.extend(['fw-type', self.tmpl_id])
                        if self.fw_ver:
                            info.extend(['fw', self.fw_ver])
                        self._send(MSG_INTERNAL, *info)
                        try:
                            self.emit('connected', ping=dt)
                        except TypeError:
                            self.emit('connected')
                    else:
                        if dlen == STA_INVALID_TOKEN:
                            self.emit("invalid_auth")
                            print("Invalid auth token")
                        return self.disconnect()
            else:
                if dlen >= self.buffin:
                    print("Cmd too big: ", dlen)
                    return self.disconnect()
 
                if len(self.bin) < 5+dlen:
                    break
 
                data = self.bin[5:5+dlen]
                self.bin = self.bin[5+dlen:]
 
                args = list(map(lambda x: x.decode('utf8'), data.split(b'\0')))
 
                self.log('>', cmd, i, '|', ','.join(args))
                if cmd == MSG_PING:
                    self._send(MSG_RSP, STA_SUCCESS, id=i)
                elif cmd == MSG_HW or cmd == MSG_BRIDGE:
                    if args[0] == 'vw':
                        self.emit("V"+args[1], args[2:])
                        self.emit("V*", args[1], args[2:])
                elif cmd == MSG_INTERNAL:
                    self.emit("internal:"+args[0], args[1:])
                elif cmd == MSG_REDIRECT:
                    self.emit("redirect", args[0], int(args[1]))
                else:
                    print("Unexpected command: ", cmd)
                    return self.disconnect()
 
import socket
 
class Blynk(BlynkProtocol):
    def __init__(self, auth, **kwargs):
        self.insecure = kwargs.pop('insecure', False)
        self.server = kwargs.pop('server', 'blynk.cloud')
        self.port = kwargs.pop('port', 80 if self.insecure else 443)
        BlynkProtocol.__init__(self, auth, **kwargs)
        self.on('redirect', self.redirect)
 
    def redirect(self, server, port):
        self.server = server
        self.port = port
        self.disconnect()
        self.connect()
 
    def connect(self):
        print('Connecting to %s:%d...' % (self.server, self.port))
        s = socket.socket()
        s.connect(socket.getaddrinfo(self.server, self.port)[0][-1])
        try:
            s.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
        except:
            pass
        if self.insecure:
            self.conn = s
        else:
            try:
                import ussl
                ssl_context = ussl
            except ImportError:
                import ssl
                ssl_context = ssl.create_default_context()
            self.conn = ssl_context.wrap_socket(s, server_hostname=self.server)
        try:
            self.conn.settimeout(SOCK_TIMEOUT)
        except:
            s.settimeout(SOCK_TIMEOUT)
        BlynkProtocol.connect(self)
 
    def _write(self, data):
        #print('<', data)
        self.conn.write(data)
        # TODO: handle disconnect
 
    def run(self):
        data = b''
        try:
            data = self.conn.read(self.buffin)
            #print('>', data)
        except KeyboardInterrupt:
            raise
        except socket.timeout:
            # No data received, call process to send ping messages when needed
            pass
        except: # TODO: handle disconnect
            return
        self.process(data)
main.py
Copy the following code and save it to the Raspberry Pi Pico W with name ‘main.py’.

1
2
3
4
5
6
# WiFi credentials
WIFI_SSID = "SSID"
WIFI_PASSWORD = "Password"
 
# Blynk authentication token
BLYNK_AUTH = "**************************"
From these lines change the WiFi SSID, Password & Blynk Authentication Token.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
from machine import Pin, I2C        #importing relevant modules & classes
import bme280        #importing BME280 library
import network
import time
import BlynkLib
 
i2c=I2C(0,sda=Pin(0), scl=Pin(1), freq=400000)    #initializing the I2C method 
 
# WiFi credentials
WIFI_SSID = "SSID"
WIFI_PASSWORD = "Password"
 
# Blynk authentication token
BLYNK_AUTH = "**************************"
 
 
# Connect to WiFi network
wifi = network.WLAN(network.STA_IF)
wifi.active(True)
wifi.connect(WIFI_SSID, WIFI_PASSWORD)
 
# Wait for the connection to be established
while not wifi.isconnected():
    sleep(1)
 
# Initialize Blynk
blynk = BlynkLib.Blynk(BLYNK_AUTH)
 
# Run the main loop
while True:
    # Read BME280 sensor data
    bme = bme280.BME280(i2c=i2c)
    temperature, pressure, humidity = bme.read_compensated_data()
 
    # Print sensor data to console
    print('Temperature: {:.1f} C'.format(temperature/100))
    print('Humidity: {:.1f} %'.format(humidity/1024))
    print('Pressure: {:.1f} hPa'.format(pressure/25600))
 
    # Send sensor data to Blynk
    blynk.virtual_write(1, temperature/100)  # virtual pin 1 for temperature
    blynk.virtual_write(2, humidity/1024)    # virtual pin 2 for humidity
    blynk.virtual_write(3, pressure/25600)   # virtual pin 3 for pressure
 
    # Run Blynk
    blynk.run()
 
    # Delay for 10 seconds
    time.sleep(5)





Sending BME280 Readings to Blynk 2.0 with Raspberry Pi Pico W
Save the above code and run it on the Pico W board.

You can now test the the Blynk web app. Open the web app and navigate to the project dashboard. Click on the button widget, and the BME280 Sensor Data gets uploaded.

BME280 Blynk Raspberry Pi Pico W

You can also view the BME280 temperature, pressure and humidity readings on Blynk Dashboard.



In conclusion, this project provides a practical guide to sending BME280 Sensor Weather Station data to Blynk 2.0 applications through the Raspberry Pi Pico W’s WiFi capability. The BME280 Sensor measures temperature, humidity, and pressure, making it an essential tool for creating weather stations.

By integrating it with Blynk 2.0 applications, we can remotely monitor and visualize the data. The Raspberry Pi Pico W’s WiFi capability makes it possible to transmit data wirelessly, enabling us to easily set up a weather station and monitor it from anywhere. This project is an excellent starting point for anyone interested in creating IoT projects that involve weather monitoring and wireless data transmission.

# ESP8266 ESP-01 WIFI Wireless with 2CH Relay Module Board

The Dual WiFi Relay Module is an advanced control solution built on the ESP-01 WiFi module and powered by the STM8S103 high-performance microprocessor. It enables seamless wireless control of a dual-channel relay via a mobile application, requiring only minimal setup within a local area network (LAN). Ideal for home automation, industrial control, and other IoT applications.


<img src="docs/images/esp-01-relay-x2_preview.jpg" alt="Device preview" width="400">


## Features
**Integrated Components:**
Equipped with **ESP-01 WiFi module** for reliable wireless communication.
Powered by **STM8S103 microcontroller** for stable and efficient operation.
**Durable Relay Design:** 5V 10A 250V AC (or 10A 30V DC) with diode protection and 100k+ cycles.
**User-Friendly Board:** Status indicators, jumpers, UART & SWIM interfaces for development.

## Specifications

**Model:** ESP8266 (ESP-01)
**Channels:** 2 (Dual-channel)
**Board Size:** 59 x 40 mm
**Weight:** Approx. 36g
**Power Supply:** 5V input

## Pinout

<img src="docs/images/esp-01-relay-x2.jpg" alt="Device preview" width="400">


| Pin/Port	                | Description                                                    |
| ------------------------- | -------------------------------------------------------------- |
| IN+, IN-	                | 5V power input                                                 |
| 5V, GND, SWIM, NRST       | STM8S program download port                                    |
| TX, RX	                | UART serial communication                                      |
| Button S1	                | Switch between Mode 1 & Mode 2                                 |
| Button S2	                | Restore factory settings                                       |
| LED D7 (Red)	            | Mode 1 indicator                                               |
| LED D5 (Blue)	            | Mode 2 indicator                                               |
| LED D6 (Green)	        | Working condition (off / 0.5s / 2s flash / solid)              |
| LED D28 & D4 (Red)        | Relay ON indicator lights                                      |
| 2 Jumper Caps	            | RX ↔ RX1 and TX ↔ TX1 (normal use), debugging (top position)   |
| COM1, COM2	            | Common relay terminals                                         |
| NO1, NO2	                | Normally open terminals                                        |
| NC1, NC2	                | Normally closed terminals                                      |


## Relay Control Instructions (HEX)

Turn ON Relay 1: A0 01 01 A2
Turn OFF Relay 1: A0 01 00 A1
Turn ON Relay 2: A0 02 01 A3
Turn OFF Relay 2: A0 02 00 A2

## Setup Requirements

  * 5V/1A Power Adapter

## Using this relay via Relay Controller

1. **Include the Relay Controller library**

  **Method 1:**
    1. Select **Library management**
    2. Enter **Relay Controller**
    3. Find **Relay Controller by javavirys (UDFSOFT)** Click the **Install** button

  **Method 2:**
    1. Download the repository as a .zip file.
    2. In the Arduino IDE, go to **Sketch** -> **Include Library** -> **Add .ZIP Library...**.
    3. Select the downloaded file.

2. Include the Relay Controller header files in your sketch.

```cpp
#include "SerialRelayController.h" // To control this relay, we need the SerialRelayController class.
```

3. Create an instance of the SerialRelayController class and configure it.

```cpp
  #define RELAY_RX 3  // GPIO3 (RX)
  #define RELAY_TX 1  // GPIO1 (TX)
  
  RelayController* createRelayController() {
    static SoftwareSerial _serial(RELAY_RX, RELAY_TX);
    _serial.begin(115200);

    return new SerialRelayController(_serial, 2);  // 2CH Relay Module
  }
```

  **That's it, you're all set! Now you can control the relay :)**

4. **Relay Control**
  **Turning on the Relay**
  ```cpp
    relay->setOn(1); // sending a command to turn on Relay #1
    relay->setOn(2); // sending a command to turn on Relay #2
  ```

  **Turning off the Relay**
  ```cpp
    relay->setOff(1); // sending a command to turn off Relay #1
    relay->setOff(2); // sending a command to turn off Relay #2
  ```

```cpp
  #define RELAY_RX 3  // GPIO3 (RX)
  #define RELAY_TX 1  // GPIO1 (TX)
  
  RelayController* createRelayController() {
    static SoftwareSerial _serial(RELAY_RX, RELAY_TX);
    _serial.begin(115200);

    return new SerialRelayController(_serial, 2);  // 2CH Relay Module
  }

  void setup() {
  relay = createRelayController();
  relay->begin();

  relay->setOn(1); // sending a command to turn on Relay #1
  relay->setOn(2); // sending a command to turn on Relay #2

  relay->setOff(1); // sending a command to turn off Relay #1
  relay->setOff(2); // sending a command to turn off Relay #2
}

```
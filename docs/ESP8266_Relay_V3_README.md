# ESP8266 Relay V3

This is a smart relay module based on the ESP-01/ESP-01S serial WiFi transceiver module. It's designed for smart home, IoT, and other DIY projects. With this smart relay, you can easily create your own smart switch to control any device using your phone or Wi-Fi.

The kit includes: 1 ESP8266 relay module and 1 ESP-01 serial WiFi transceiver module.

## Images

<img src="https://github.com/UDFSmart/Smart-Relay/blob/main/SerialSmartRelay/docs/images/esp-01_relay_x1_module.png" alt="Device preview" width="400">

## Specifications:
  * Model: ESP8266 3V Wi-Fi Relay Module with ESP-01S Board
  * Package Includes:
    * 1 x ESP8266 ESP-01S Relay Module
    * 1 x ESP-01S Serial WiFi Transceiver Module
  * Operating Voltage: 5 VDC
  * Relay Load Capacity: 10 A @ 250 VAC, 10 A @ 125 VAC, 10 A @ 30 VDC, 10 A @ 28 VDC.
  * Maximum Transmission Range: ~400 m (in open areas)
  * Dimensions in mm (L x W x H):
    37 x 25 x 20

## Relay Control Instructions (HEX)

**Turn ON Relay:** A0 01 01 A2

**Turn OFF Relay:** A0 01 00 A1


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

2. **Include the Relay Controller header files in your sketch.**

```cpp
#include <SerialRelayController.h> // To control this relay, we need the SerialRelayController class.
```

**3. Create an instance of the SerialRelayController class and configure it.**

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
    relay->setOn(1); // sending a command to turn on Relay
  ```

  **Turning off the Relay**
  ```cpp
    relay->setOff(1); // sending a command to turn off Relay
  ```

### Example

```cpp
  #include <Arduino.h>
  #include <SerialRelayController.h>

  #define RELAY_RX 3  // GPIO3 (RX)
  #define RELAY_TX 1  // GPIO1 (TX)

  RelayController* relay = nullptr;
  
  RelayController* createRelayController() {
    static SoftwareSerial _serial(RELAY_RX, RELAY_TX);
    _serial.begin(115200);

    return new SerialRelayController(_serial, 2);  // 2CH Relay Module
  }

  void setup() {
    relay = createRelayController();
    relay->begin();
  }

  void loop() {
    relay->setOn(1); // sending a command to turn on Relay
    delay(3000);

    relay->setOff(1); // sending a command to turn off Relay
    delay(3000);
  }
```

## Using the library

[Smart-Relay](https://github.com/UDFSmart/Smart-Relay)

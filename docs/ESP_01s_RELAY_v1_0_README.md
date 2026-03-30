# ESP-01S Relay v1.0

This ESP-01S Relay based on AI-Thinker ESP-01S WIFI module. It is designed for smart home, Internet of thing and others DIY project. With this smart relay, you will easy to DIY your smart switch to control any device by your phone anywhere.
In the version, we use the GPIO0 of ESP-01S to control the Relay by Hight level.


<img src="images/esp-01s/esp-01s_relay_v1_0_front.png" alt="Device preview" width="400">
<img src="images/esp-01s/esp-01s_relay_v1_0_back.png" alt="Device preview" width="400">

## Schematic

<img src="images/esp-01s/esp-01s_relay_v1_0_Schematic.png" alt="Device preview" width="400">

## Parameter
 
 * Working voltage: DC5V
 * Working current: ≥250mA
 * Communication: ESP-01S WIFI module
 * Transmission distance: the maximum transmission distance of 400m (open environment, mobile phone equipped with WIFI module)
 * Load: 10A/250VAC 10A/30VDC, the relay pulls 100,000 times
 * GPIO0 of ESP-01S Control the Relay (High level active)
 * Product size: 37 * 25mm
 
## Usage

### Software

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
#include <PinRelayController.h> // To control this relay, we need the PinRelayController class.
```

**3. Create an instance of the PinRelayController class and configure it.**

```cpp
  
  RelayController* createRelayController() {
    static uint8_t relayPins[] = { 0 };
    return new PinRelayController(relayPins, 1);
  }
```

4. **Relay Control**
  **Turning on the Relay**
  ```cpp
    relay->setOn(1); // sending a command to turn on Relay
  ```

  **Turning off the Relay**
  ```cpp
    relay->setOff(1); // sending a command to turn off Relay
  ```

### Hardware


  1) Hardware connection
     
     Just plug the ESP-01S to the 2*4 pin header after download the code to ESP-01S.
     
     Show as below:
     
  2) Power supply
     
     Connect a DC 5V power to the GND and VCC.

  4) That's all, you can now use this device.
     

     <img src="images/esp-01s/test_connection.png" alt="Device preview" width="400">

     [Video](https://vt.tiktok.com/ZSHLanS3q/)

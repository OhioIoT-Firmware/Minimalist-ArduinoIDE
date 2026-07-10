# OhioIoT — Minimalist for Arduino IDE

The **Minimalist** tier of the OhioIoT device firmware SDK for ESP32.

This code base is designed to help you connect your device to the OhioIoT cloud-based MQTT broker.  

*** THIS CODE IS STILL UNDER DEVELOPMENT *** 
If you have any questions, please send a note from the web page at [OhioIoT.com/contact](https://ohioiot.com/contact).

```cpp

// define your variables

void setup() {
    controller.setup(WIFI_SSID, WIFI_PASS, MQTT_USER, MQTT_PASS);
    // add your own code
}

void loop()  {
    controller.loop();
    // add your own code
}

```

## Quick Start

1. Download this repo as a ZIP (green **Code** button -> Download ZIP).
2. Arduino IDE: **Sketch -> Include Library -> Add .ZIP Library**, choose the ZIP.
3. Open **File -> Examples -> OhioIoT-Minimalist -> Basic**.
4. Fill in the four WiFi/MQTT values at the top of the sketch, then Upload.

## What's Included

- _certificates
- _controller
- device_id
- wifi_tools
- mqtt

## The Controller
The controller quarterbacks the remaining modules so that they can remain relatively unaware of each other.
You do not need to edit this module for this to work.  It is plain,
readable source. Open it any time to see how the pieces fit together, or tweak it
to change how the framework behaves. Nothing here is a black box.

Feedback is welcome.

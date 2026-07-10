# OhioIoT — Minimalist (ArduinoIDE)

The **Minimalist** tier of the OhioIoT device firmware SDK for ESP32.

This code base is designed to help you connect your device to the OhioIoT cloud-based MQTT broker.  

IT IS STILL UNDER DEVELOPMENT - if you have any questions, please visit the website and leave a message.

Connect to WiFi and MQTT, publish, and react to raw messages. The smallest, most readable starting point.

## Quick start

1. Download this repo as a ZIP (green **Code** button -> Download ZIP).
2. Arduino IDE: **Sketch -> Include Library -> Add .ZIP Library**, choose the ZIP.
3. Open **File -> Examples -> OhioIoT-Minimalist -> Basic**.
4. Fill in the four WiFi/MQTT values at the top of the sketch, then Upload.

## What's included

- _certificates
- device_id
- wifi_tools
- mqtt

## The controller

You don't need to touch it — but the controller in `src/_controller/` is plain,
readable source. Open it any time to see how the pieces fit together, or tweak it
to change how the framework behaves. Nothing here is a black box.

## Feedback

This SDK is built to be read. If something's unclear or could be better, open an
issue — feedback is welcome.

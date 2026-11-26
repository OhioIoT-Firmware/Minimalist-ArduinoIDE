# AGENTS.md: OhioIoT Minimalist SDK for Arduino IDE

Notes for AI coding tools.  Read this before you review or change a sketch that uses this repo.

## What this is

ESP32 firmware SDK that connects a device to the OhioIoT MQTT broker (`mqtt.ohioiot.com`, port 8883, TLS, CA built in).  Connecting is simple: add the library, enter WiFi and OhioIoT credentials, and there is no device registration.  The SDK keeps WiFi (fixed 10 second retry) and MQTT (retry with backoff) connected.

This is the **Minimalist** tier.  Tiers stack: Minimalist, then Scaler, then Champion.  Modules in this tier: `controller`, `_certificates`, `device_id`, `wifi_tools`, `mqtt`.

## Files that matter

- `examples/Basic/Basic.ino`: the starting sketch, with the four WiFi and MQTT values at the top.
- `src/OhioIoT-Minimalist.h`: the one header a sketch includes.
- `src/controller/`: the controller.  It runs the modules from `setup()` and `loop()`.
- `src/<module>/`: one folder per module.
- `library.properties`: library name, version, and the PubSubClient dependency.

A user's own `.ino` lives in their sketch folder, not in this repo.  Read it against this library.

## How a sketch uses it

- Include: `#include <OhioIoT-Minimalist.h>` brings in `controller`, `mqtt`, and every module in this tier.
- In `setup()`: `controller.setup(WIFI_SSID, WIFI_PASS, MQTT_USER, MQTT_PASS);` then `mqtt.set_subscriptions(list);` and `mqtt.set_callback(handler);`.
- In `loop()`: call `controller.loop();` on every pass.  It keeps WiFi and MQTT up and delivers incoming messages.
- A subscription list ends with `nullptr`: `static const char * list[] = { "~/~/inbox", nullptr };`.
- Handler: `void handler(char * topic, char * payload)`.  `topic` arrives fully expanded.
- Topic shorthand: `~/` becomes `{mqtt_user}/`, and `~/~/` becomes `{mqtt_user}/{device_id}/` (this device).  `~/+/inbox` subscribes to `inbox` on all your devices.
- `mqtt.publish(topic, value)` takes text, int, float, or bool.  `~/~/numb/{graph}/{field}` makes an automatic graph.
- Publish only when `mqtt.is_connected` is true.  A publish while disconnected is dropped.
- The SDK never calls `Serial.begin()`.  The sketch does.
- Every incoming message goes straight to your handler.  This tier has no message router.

## Requirements

- arduino-esp32 core 2.0.17.  Core 3.x is not supported.
- PlatformIO: the official `espressif32` platform (core 2.x, tested on 6.13.0), not pioarduino.  Arduino IDE: esp32 boards package 2.0.17.
- PubSubClient 2.8 or later.

## Common mistakes to check

- Wrong core: 3.x, or the pioarduino platform.
- `controller.loop()` missing from `loop()`.
- `delay()` or other blocking code in `loop()`, so `controller.loop()` runs rarely and connections drop.  Time work with `millis()`.
- Publishing before `mqtt.is_connected` is true, including from `setup()`.  MQTT connects later, inside `controller.loop()`.
- A subscription list without `nullptr` at the end.
- `+` or `#` in a publish topic.  Wildcards are for subscriptions only.
- Real WiFi or MQTT credentials committed or pasted into a chat.  Use placeholders.
- Hard-coding a device id.  The SDK makes one on first boot (8 lowercase letters and digits) and keeps it in NVS.
- Using features this tier doesn't ship.  Minimalist has no message router, commands, clear_counters, restart route, heartbeat, OTA, provisioning, settings, or power.  The router features start in Scaler.  OTA, provisioning, settings, and power are Champion only.

## More

OhioIoT: https://ohioiot.com.  Docs for this tier: https://ohioiot.com/docs/code-samples/minimalist

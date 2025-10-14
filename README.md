# SmaRI – Smart Remote Intercom

**SmaRI** (Smart Remote Intercom) is a compact and smart Wi-Fi-enabled device that upgrades any traditional intercom system, allowing you to open gates or doors remotely through the internet using an Android app.

---

## 🚀 Project Overview

SmaRI connects to your existing intercom’s control lines and gives it Wi-Fi connectivity using an **ESP32-based Arduino board**.  
It uses two **5V mechanical relays** to simulate button presses for gate or door opening, and an **OLED display (SSD1306 128×64)** to show network status, Wi-Fi signal strength, and operation feedback.

The goal is to make any analog intercom “smart” — controllable from anywhere — with minimal modification to the original installation.

---

## ⚙️ How It Works

- The **ESP32 module**, mounted on an Arduino-compatible board, manages Wi-Fi and control logic.  
- It connects to your **home network** and listens for **HTTP GET** requests from an **Android app** or a web interface.  
- When a command is received, it **activates one of the two relays** for about 0.5–1 second to mimic pressing a button.  
- The **OLED display** shows:
  - Wi-Fi connection status  
  - Signal strength  
  - Action feedback (e.g., “Gate Opening”, “Pedestrian Gate Triggered”)  

---

## 🧩 Hardware Components

| Component | Description |
|------------|-------------|
| **ESP32 with onboard OLED (SSD1306 128×64)** | Main microcontroller with display |
| **2-channel 5V relay module** | Controls two independent circuits (garage gate + pedestrian gate) |
| **5V Power Supply** | Powers ESP32 and relays |
| **DDNS / Port Forwarding** | Enables remote internet control |
| **Wires, breadboard, connectors** | For wiring and prototyping |
| **3D-Printed Case** | Enclosure for all components |

---

## 🧠 Features

- 🌐 Wi-Fi remote control via HTTP GET requests  
- 📱 Android app support for easy operation  
- 🔌 Dual relay output — control two different gates or functions  
- 🖥️ Onboard OLED display showing connection, signal, and operation status  
- 🧾 Supports DDNS for remote access outside the local network  
- 🧰 Fully open-source and Arduino-compatible  

---

## 🧱 Development Steps

1. **Hardware Setup** – Connect ESP32, relays, OLED display, and power supply.  
2. **Basic Test Script** – Verify each relay toggles correctly via serial monitor.  
3. **Wi-Fi Integration** – Connect to local network and handle HTTP GET commands.  
4. **Display UI** – Show connection, RSSI signal, and triggered actions.  
5. **App Communication** – Send relay commands from Android app or browser.  
6. **Enclosure Design** – 3D print a custom box for the device.  
7. **Final Test** – Integrate with real intercom and verify timing and reliability.  

---

## 🧭 Future Improvements

- Add MQTT / Home Assistant integration  
- Include configuration menu on OLED screen  
- Add local button input for manual gate control  
- Implement OTA firmware updates  

---

## 📜 License

This project is open-source. Feel free to contribute, adapt, and improve!

---

## 🧑‍💻 Author

**micBar0ne**  
Smart Remote Intercom – 2025

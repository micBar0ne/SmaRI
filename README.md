# SmaRI – Smart Remote Intercom

**SmaRI** (Smart Remote Intercom) is a compact and smart device that upgrades any traditional intercom, allowing you to open gates or doors remotely through the internet using an Android app.

---

## 🚀 Project Overview

SmaRI connects to your existing intercom system and gives it Wi-Fi connectivity using an Arduino-based controller.  
It operates silently thanks to solid-state relays and can trigger intercom or gate commands remotely through simple HTTP requests.

The project’s goal is to make any analog intercom “smart” — controllable from anywhere — with minimal modification to the original system.

---

## ⚙️ How It Works

- The **Arduino** (ESP32 / ESP8266 / Arduino Mini) is connected to your intercom’s control lines.  
- It connects to your **Wi-Fi network** and waits for commands from an **Android app** or a **web request**.
- When a command is received, it **activates a relay** for a short time (≈0.5–1 second) to simulate pressing the gate/door button.
- The system can **report its status** or confirm that the action has been executed.

---

## 🧩 Hardware Components

| Component | Description |
|------------|-------------|
| Arduino Mini / ESP8266 / ESP32 | Main microcontroller board |
| 2-channel Relay Module (SRD) | For reliable gate control |
| 5V Power Supply | Powers the board and relays |
| Wi-Fi Module | Built-in or external for internet access |
| Wires, breadboard, connectors | For prototyping |
| 3D-Printed Enclosure | Custom case for all components |

---

## 🧠 Features

- 🌐 Internet remote control via HTTP GET commands  
- 📱 Android app interface  
- 🔇 Silent relay operation (no clicks)  
- 🚪 Dual-relay control — garage + pedestrian gate  
- 🧰 Modular and open-source design  
- 🧾 Supports DDNS for external access  

---

## 🧱 Development Steps

1. 🔌 **Hardware Setup** – Connect Arduino and relays to the intercom.  
2. 💡 **Basic Test Script** – Verify relay activation via serial or Wi-Fi.  
3. 🌍 **Network Integration** – Implement HTTP GET control with DDNS.  
4. 📲 **App Communication** – Pair Android app with the device.  
5. 🧩 **Enclosure Design** – 3D model and print the housing.  
6. 🧪 **Real Intercom Testing** – Validate control and timing with actual system.  
7. 🎉 **Deployment** – Install and enjoy a smart, quiet, internet-enabled intercom.

---

## 🧭 Future Improvements

- Add MQTT / Home Assistant support  
- Include OLED display for local feedback  
- Integrate push notifications or voice assistants  

---

## 📜 License

This project is open-source. Feel free to contribute, adapt, and improve!

---

## 🧑‍💻 Author

**micBar0ne**  
Smart Remote Intercom – 2025

# 🎵 Audio Visualizer System using Arduino

## 📌 Project Overview

This project is an Embedded Audio Experience System that reacts to sound and generates real-time LED visual effects.

## ⚙️ Features

* 🎵 AUX-based audio playback
* 🎤 Sound detection using microphone sensor
* 💡 Music-reactive LED strip
* 📺 OLED display for system info
* ⚡ Real-time processing using Arduino

## 🧩 Components Used

* Arduino Nano
* LM386 Audio Amplifier
* Sound Sensor (KY-038 / MAX9814)
* LED Strip (2-wire)
* MOSFET (IRFZ44N)
* OLED Display (SSD1306)
* Speaker
* AUX Cable

## 🔌 System Architecture

Phone → AUX → LM386 → Speaker
Speaker → Sound Sensor → Arduino
Arduino → MOSFET → LED Strip
Arduino → OLED Display

## 🧠 Working Principle

The sound sensor captures audio signals and converts them into analog voltage. The Arduino reads this signal and generates PWM output to control LED brightness. The OLED displays real-time system information.

## 📸 Project Images

(Add your images in /images folder)

## 📊 Future Improvements

* Add Bluetooth audio
* Use WS2812B LEDs for RGB effects
* Add mobile app control

## 🔌 Circuit Connections (Arduino Uno)

### 🟢 Power Connections

* Arduino **5V** → OLED VCC, Sound Sensor VCC, LM386 VCC
* Arduino **GND** → All module GND (OLED, Sensor, LM386, MOSFET Source, LED Supply GND)

⚠️ All grounds must be common

---

### 🔊 Audio Module (LM386 + AUX + Speaker)

* AUX Left/Right → LM386 IN
* AUX GND → Arduino GND
* LM386 VCC → 5V
* LM386 GND → GND
* LM386 OUT+ → Speaker +
* LM386 OUT− → Speaker −

---

### 🎤 Sound Sensor

* VCC → 5V
* GND → GND
* A0 → Arduino **A0**
* D0 → Not used

---

### 💡 LED Strip (2-wire) with MOSFET

* LED + → External Power (+5V or +12V depending on strip)
* LED − → MOSFET Drain

#### MOSFET Connections:

* Source → GND
* Gate → Arduino **D6** (through 220Ω resistor)
* Gate → GND (through 10k resistor)

---

### 📺 OLED Display (SSD1306 I2C)

* VCC → 5V
* GND → GND
* SDA → Arduino **A4**
* SCL → Arduino **A5**

---

### 📍 Pin Summary

| Component       | Arduino Pin |
| --------------- | ----------- |
| Sound Sensor A0 | A0          |
| MOSFET Gate     | D6          |
| OLED SDA        | A4          |
| OLED SCL        | A5          |

---

### ⚡ Power Note

* If LED strip is **12V**, use separate 12V adapter
* Always connect Arduino GND with LED power GND

---

### 🔄 System Flow

Phone → AUX → LM386 → Speaker
Speaker → Sound Sensor → Arduino
Arduino → MOSFET → LED Strip
Arduino → OLED Display



Your Name

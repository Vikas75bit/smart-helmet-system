# smart-helmet-system
Smart Helmet Safety System using Arduino with alcohol detection, drowsiness monitoring, and LCD display (standalone transmitter version)

# 🪖 Smart Helmet System (Standalone Version)

## 📌 Overview
This project implements a smart helmet safety system that detects:
- Helmet wearing status
- Alcohol presence
- Drowsiness

It displays real-time data on an LCD and provides alerts using a buzzer.

---

## ⚙️ Features
- Helmet detection using IR sensor
- Alcohol detection using MQ3 sensor
- Drowsiness detection using IR sensor
- LCD display output (I2C)
- Buzzer alert system
- Standalone operation (no RF receiver)

---

## 🧰 Components Used
- Arduino Uno / Nano
- MQ3 Alcohol Sensor
- IR Sensors (x2)
- 16x2 LCD (I2C)
- Buzzer
- LED
- Breadboard

---

## 🔌 Working Principle
The system continuously reads sensor values:
- If helmet is not worn → alert
- If alcohol detected → alert
- If drowsiness detected → alert

The LCD displays system status in real time.

---

## 🖥️ Code
Located in:

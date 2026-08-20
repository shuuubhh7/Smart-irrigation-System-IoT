# Smart-irrigation-System-IoT
Smart Irrigation System  Smart Irrigation System is an IoT-based solution that automates watering using soil moisture sensors and real-time environmental data. It optimizes water usage, reduces wastage, improves crop health, and enables remote monitoring and control through a web or mobile dashboard for efficient and sustainable agriculture.

Smart Irrigation System using ESP32, Blynk, DHT11, Soil Moisture Sensor, PIR Sensor & LCD

🌱 Project Overview

The Smart Irrigation System is an IoT-based agricultural automation project that monitors soil moisture, temperature, humidity, and motion detection in real time. The system uses an ESP32 microcontroller connected to Blynk Cloud for remote monitoring and control. A relay-controlled water pump can be operated from the Blynk mobile application, enabling efficient water management and reducing water wastage.

The project displays sensor readings on a 16x2 I2C LCD and sends live data to the Blynk dashboard.


---

🚀 Features

Real-time Soil Moisture Monitoring

Temperature and Humidity Monitoring using DHT11

Remote Water Pump Control via Blynk App

LCD Display for Local Monitoring

Motion Detection using PIR Sensor

Instant Blynk Notifications on Motion Detection

IoT-Based Smart Farming Solution

Low Cost and Easy to Deploy



---

🏗️ Project Architecture

┌─────────────────┐
                    │   Blynk Cloud   │
                    └────────┬────────┘
                             │ WiFi
                             │
                    ┌────────▼────────┐
                    │      ESP32      │
                    └───────┬─────────┘
                            │
        ┌───────────────────┼───────────────────┐
        │                   │                   │
        │                   │                   │
   ┌────▼────┐        ┌─────▼─────┐      ┌─────▼─────┐
   │ DHT11   │        │ Soil      │      │ PIR       │
   │ Sensor  │        │ Moisture  │      │ Sensor    │
   └────┬────┘        └─────┬─────┘      └─────┬─────┘
        │                   │                   │
        │                   │                   │
        └──────────┬────────┴───────────┬──────┘
                   │                    │
             ┌─────▼─────┐        ┌────▼────┐
             │  LCD I2C  │        │ Relay   │
             │ Display   │        │ Module  │
             └─────┬─────┘        └────┬────┘
                   │                   │
                   │                   │
                   │             ┌─────▼─────┐
                   │             │ Water Pump│
                   │             └───────────┘


---

📋 Components Required

Component	Quantity

ESP32 Development Board	1
DHT11 Sensor	1
Soil Moisture Sensor	1
PIR Motion Sensor	1
1-Channel Relay Module	1
Water Pump	1
16x2 I2C LCD Display	1
Jumper Wires	As Required
Breadboard	1
Power Supply	1



---

🔌 Pin Connections

DHT11 Sensor

DHT11 Pin	ESP32 Pin

Data	GPIO 2
VCC	3.3V
GND	GND



---

Soil Moisture Sensor

Sensor Pin	ESP32 Pin

AO	GPIO 4
VCC	3.3V
GND	GND



---

PIR Sensor

PIR Pin	ESP32 Pin

OUT	GPIO 13
VCC	5V
GND	GND



---

Relay Module

Relay Pin	ESP32 Pin

IN	GPIO 25
VCC	5V
GND	GND



---

LCD I2C

LCD Pin	ESP32 Pin

SDA	GPIO 21
SCL	GPIO 22
VCC	5V
GND	GND



---

📱 Blynk Dashboard Configuration

Template Details

#define BLYNK_TEMPLATE_ID "TMPL3Dkypls3P"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"


---

Virtual Pins

Virtual Pin	Function

V5	Temperature
V6	Humidity
V8	Soil Moisture
V14	Pump Control Switch



---

⚙️ Working Principle

1. Soil Monitoring

The soil moisture sensor continuously measures the water content in the soil.

int soilVal = analogRead(SOIL_PIN);

The value is converted into percentage:

int soilPer = map(soilVal, 0, 4095, 100, 0);


---

2. Temperature & Humidity Monitoring

DHT11 collects environmental data:

float h = dht.readHumidity();
float t = dht.readTemperature();


---

3. Data Upload to Blynk

Sensor readings are uploaded every 2 seconds.

Blynk.virtualWrite(V5, t);
Blynk.virtualWrite(V6, h);
Blynk.virtualWrite(V8, soilPer);


---

4. Pump Control

The user controls the water pump from the Blynk mobile application.

BLYNK_WRITE(V14)

Relay Logic:

digitalWrite(RELAY_PIN, !relayState);

The relay is configured as Active-Low.


---

5. Motion Detection

The PIR sensor detects movement around the farm.

if (digitalRead(PIR_PIN) == HIGH)

Blynk notification:

Blynk.logEvent("pirmotion", "Motion Detected!");


---

6. LCD Display

The LCD displays:

Temperature
Humidity
Soil Moisture

Example:

T:28C H:65%
Soil: 78%


---

📂 Project Structure

Smart-Irrigation-System/
│
├── src/
│   └── Smart_Irrigation.ino
│
├── images/
│   ├── architecture.png
│   ├── circuit_diagram.png
│   ├── blynk_dashboard.png
│
├── docs/
│   └── project_report.pdf
│
├── README.md
│
└── LICENSE


---

📊 Data Flow

Sensors
   │
   ▼
ESP32
   │
   ▼
Sensor Processing
   │
   ├── LCD Display
   │
   ├── Blynk Cloud
   │
   └── Relay Control
          │
          ▼
      Water Pump


---

🌍 Applications

Smart Agriculture

Precision Farming

Greenhouse Automation

Water Conservation Systems

Smart Gardens

Crop Monitoring Systems



---

🔮 Future Enhancements

Automatic Irrigation based on Soil Moisture Threshold

Weather Forecast Integration

AI-Based Water Requirement Prediction

GSM/SMS Alerts

Solar Powered Irrigation System

Multiple Zone Irrigation Control

Mobile App Analytics Dashboard

Cloud Data Logging



---

🛠️ Technologies Used

ESP32

Arduino IDE

Blynk IoT Platform

Embedded C++

Wi-Fi Communication

IoT Sensors

LCD I2C Display



---

📈 Expected Benefits

Reduces Water Wastage

Increases Crop Productivity

Enables Remote Monitoring

Saves Labor Costs

Improves Resource Utilization

Supports Sustainable Farming



---

👨‍💻 Author

SHUBHAM SHARMA
B.Tech Information Technology
IoT & Smart Agriculture Project


---

⭐ If you found this project useful, please give it a Star on GitHub! ⭐

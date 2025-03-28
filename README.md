# KWAME NKRUMAH UNIVERSITY OF SCIENCE AND TECHNOLOGY  
## COLLEGE OF ENGINEERING  
### DEPARTMENT OF COMPUTER ENGINEERING 
**COE 381 MICROPROCESSORS**  
![School logo](https://www.google.com/url?sa=i&url=https%3A%2F%2Fseeklogo.com%2Fvector-logo%2F432012%2Fknust&psig=AOvVaw2lZ43UcwGWRey3GPsnSK5O&ust=1743268276018000&source=images&cd=vfe&opi=89978449&ved=0CBQQjRxqFwoTCLCf5MSirYwDFQAAAAAdAAAAABAE)


## PROJECT: LPG LEAK DETECTION SYSTEM
### GROUP NUMBER: 4  

### **GROUP MEMBERS:**  
1. **TANDOH ELIZABETH MAAME AMA** - *1828522*  
2. **NANA KWASI OPARE LARBI** - *1823822*  
3. **ISAAC QUARTEY** - *1827422*  
4. **ADJAPONG YEBOAH CLEMENT** - *1813722*  
5. **EDWARD MENSAH OWUSU** - *1826822*  
6. **ASIAMAH OMARI YAW** - *1818322*  
7. **ISHOLA FAAZELE ADEBIYI** - *1853722*  
8. **ASIEDU ENOCH OFORI KWASI** - *1818522*  
9. **DEFIAT SELORM ZION** - *1821422*  


## Project Overview

This project is an LPG (Liquefied Petroleum Gas) leak detection system developed as part of a microprocessors course. The system continuously monitors the LPG concentration in the air using a gas sensor. When the LPG level surpasses a predefined threshold, the system:

- Sounds an alarm using a buzzer.
- Blinks an LED bar proportional to the LPG level.
- Displays the LPG concentration on an LCD screen.
- Sends real-time data to a Blynk dashboard, visualizing the LPG level using a gauge and chart.
- Triggers an alarm notification on the Blynk dashboard.
- Allows users to adjust the LPG threshold for detection via the Blynk dashboard.

## Features

- **Real-time LPG Monitoring:** Continuously reads LPG levels using a gas sensor.
- **Alarm System:** Triggers a buzzer when the LPG level crosses the set threshold.
- **Visual Indicators:** Blinking LED bar and OLED display for real-time monitoring.
- **Remote Monitoring:** Integration with Blynk dashboard for remote visualization.
- **Configurable Threshold:** Users can adjust the detection threshold via the Blynk app.
- **Platform Support:** Developed using PlatformIO in VS Code with Wokwi simulation support.


## Schematic and Connections

![Image Description](https://github.com/ishola-faazele/LPG_DETECTION_MICROP/blob/main/Schematic_LPG_DETECTION_SCHEMATIC_2025-03-26.png)

### Components Used

- **ESP32 Microcontroller**
- **MQ-2 Gas Sensor** (LPG detection)
- **OLED Display (SSD1306)** (LPG level visualization)
- **Buzzer** (Alarm system)
- **LED Bar** (Indicates LPG level)
- Ten 1k ohms resistors
- **Blynk IoT Dashboard** (Remote monitoring and control)

### APPROACH
The LPG leak detection system uses an ESP32 microcontroller to control various components, including the MQ2 gas sensor, an OLED display, a buzzer, and an LED bar graph. The system continually monitors the gas levels and activates an alarm if the concentration surpasses a pre-set threshold. The data is also sent to Blynk, an IoT platform that allows for remote monitoring of the system. 
  

### Wiring Instructions:

#### **1. MQ-2 Gas Sensor (LPG Detection)**
| Pin | Connection |
|-----|-----------|
| **VCC** | Connect to **3.3V** |
| **GND** | Connect to **GND** |
| **SIG** | Connect to a **viable ESP32 analog pin** |

---

#### **2. OLED Display (SSD1306)**
| Pin | Connection |
|-----|-----------|
| **VCC** | Connect to **3.3V** |
| **GND** | Connect to **GND** |
| **SDA** | Connect to **ESP32 Pin 21** |
| **SCL** | Connect to **ESP32 Pin 22** |

---

#### **3. Buzzer (Alarm System)**
| Pin | Connection |
|-----|-----------|
| **+ (Positive)** | Connect to a **viable ESP32 digital output pin** |
| **- (Negative)** | Connect to **GND** |

---

#### **4. LED Bar Graph (Indicates LPG Level)**
| Pin | Connection |
|-----|-----------|
| **Cathode (-)** | Connect to **GND** |
| **Anode (+)** | Connect to resistors and then to **multiple viable ESP32 digital output pins** |

---
#### **ESP32 DevKit V4 Pin Functions**

| Pin | Function |
|-----|----------|
| **GPIO0** | Boot mode selection, can be used as input/output |
| **GPIO1 / TX0** | Serial TX (debugging, UART communication) |
| **GPIO3 / RX0** | Serial RX (debugging, UART communication) |
| **GPIO4** | Digital I/O, PWM, ADC, Touch Sensor |
| **GPIO5** | Digital I/O, PWM, SPI (SS) |
| **GPIO12** | Digital I/O, ADC, Touch Sensor |
| **GPIO13** | Digital I/O, ADC, Touch Sensor, SPI (MOSI) |
| **GPIO14** | Digital I/O, PWM, ADC, Touch Sensor, SPI (SCK) |
| **GPIO15** | Digital I/O, ADC, Touch Sensor, SPI (CS) |
| **GPIO16** | Digital I/O |
| **GPIO17** | Digital I/O |
| **GPIO18** | Digital I/O, SPI (SCK) |
| **GPIO19** | Digital I/O, SPI (MISO) |
| **GPIO21** | **I²C SDA** |
| **GPIO22** | **I²C SCL** |
| **GPIO23** | Digital I/O, SPI (MOSI) |
| **GPIO25** | Digital I/O, ADC, DAC |
| **GPIO26** | Digital I/O, ADC, DAC |
| **GPIO27** | Digital I/O, ADC, Touch Sensor |
| **GPIO32** | Digital I/O, ADC, Touch Sensor |
| **GPIO33** | Digital I/O, ADC, Touch Sensor |
| **GPIO34** | **Analog Input (No Output)** |
| **GPIO35** | **Analog Input (No Output)** |
| **GPIO36** | **Analog Input (No Output)** |
| **GPIO39** | **Analog Input (No Output)** |



## Software & Tools

- **PlatformIO** (Development environment)
- **Visual Studio Code** (Code editor)
- **Wokwi Extension** (Simulation and testing)
- **Blynk IoT Dashboard** (Cloud-based monitoring)

## Installation & Setup

1. Run an online simulation here:
   - https://wokwi.com/projects/426166087854034945
2. Or to run a local simluation, install Vscode and follow the steps below:
   - https://code.visualstudio.com/download
3. **Clone the Repository**
   ```bash
   git clone https://github.com/ishola-faazele/LPG_DETECTION_MICROP.git
   cd LPG_DETECTION_MICROP
   ```
4. **Install PlatformIO**
   - Install the PlatformIO extension in VS Code.
5. **Open the Project in PlatformIO**
   - Open the project folder in VS Code and ensure PlatformIO is installed.
6. **Connect Blynk**
   - Set up a new Blynk project.
   - Obtain the authentication token.
   - Update the `main.cpp` file with your Blynk credentials.
7. **Compile and Upload Code**
   ```bash
   pio run --target upload
   ```
8. **Monitor Serial Output**
   ```bash
   pio device monitor
   ```

## File Structure

- `src/main.cpp`: Contains the core logic for sensor reading, alarm activation, and Blynk integration.
- `diagram.json`: Wokwi simulation setup file.
- `.pio\build\esp32dev\firmware.bin`: [generated after building] Contains compiled binary
- `.pio\build\esp32dev\firmware.hex`: [generated after building]  Contains compiled firmware
- `platformio.ini`: Contains project configurations.
- `wokwi.toml`: Contains wokwi configurations.
- `schematic.png`: Schematic diagram of the project.

## Usage

1. Run the simulation
2. Observe the LPG level on the OLED display.
3. If the gas level exceeds the threshold, the buzzer will sound, and the LED bar will blink.
4. Open the Blynk app to view LPG levels and adjust the threshold remotely.

## Conclusion  

The **LPG leak detection system** successfully addresses the problem of detecting and alerting individuals to the presence of dangerous gas leaks.  

### **Key Conclusions:**  
- **Effectiveness:** The system accurately detects gas leaks and alerts both **locally** (via LED/buzzer) and **remotely** (via Blynk).  
- **Real-Time Monitoring:** With the integration of **Blynk**, users can monitor gas levels remotely, adding an extra layer of safety.  
- **Reliability:** The combination of **MQ2 sensor, ESP32, Nokia LCD,** and **Blynk** works seamlessly, providing a robust solution for detecting and responding to gas leaks.  

### **Challenges:**  
- Ensuring the **accuracy** of the **MQ2 sensor readings**, as environmental factors can influence sensor output.  
- Fine-tuning the **threshold value** to minimize false alarms while ensuring safety.  


## Future Improvements

- Implement Wi-Fi notifications (email/SMS alerts).
- Improve sensor calibration for higher accuracy.
- Add a mobile app for more advanced remote control.

## Credits

Developed as part of a microprocessors course using PlatformIO, VS Code, and Wokwi simulation.

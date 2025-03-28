# LPG Leak Detection System

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
- **Visual Indicators:** Blinking LED bar and LCD display for real-time monitoring.
- **Remote Monitoring:** Integration with Blynk dashboard for remote visualization.
- **Configurable Threshold:** Users can adjust the detection threshold via the Blynk app.
- **Platform Support:** Developed using PlatformIO in VS Code with Wokwi simulation support.

## Components Used

- **ESP32 Microcontroller**
- **MQ-2 Gas Sensor** (LPG detection)
- **OLED Display (SSD1306)** (LPG level visualization)
- **Buzzer** (Alarm system)
- **LED Bar** (Indicates LPG level)
- **Blynk IoT Dashboard** (Remote monitoring and control)

## Schematic and Connections


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

## Future Improvements

- Implement Wi-Fi notifications (email/SMS alerts).
- Improve sensor calibration for higher accuracy.
- Add a mobile app for more advanced remote control.

## Credits

Developed as part of a microprocessors course using PlatformIO, VS Code, and Wokwi simulation.

#define BLYNK_TEMPLATE_ID "TMPL2enzJ42fm"
#define BLYNK_TEMPLATE_NAME "microprocessor project"
#define BLYNK_AUTH_TOKEN "pxh_V61fhj-Pz815KkLGldVoSCVDYCE5"

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define MQ2pin 33  
const int BuzzerPin = 27; 
const int LED_PINS[] = {23, 19, 18, 5, 17, 16, 4,0, 2, 15};
const int LED_COUNT = 10;
int LPG_THRESHOLD = 3000;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

BlynkTimer timer;

void checkLPGLevel();
void updateLedBar(int);
void updateOled(int);
void initializeOled();
BLYNK_WRITE(V3)
{
    LPG_THRESHOLD = param.asInt(); // assigning incoming value from pin V1 to a variable
}

void setup() {
    pinMode(BuzzerPin, OUTPUT);
    for(int thisLed = 0; thisLed < LED_COUNT; thisLed++) {
      pinMode(LED_PINS[thisLed], OUTPUT);
    }
    
    Serial.begin(115200);
    // WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected to WiFi");
    Wire.begin(21, 22);

    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }
    display.display();
    delay(2000); 

    initializeOled();

    Blynk.begin(auth, ssid, pass);
    
    timer.setInterval(3000L, checkLPGLevel);

    
}

void loop() {
    Blynk.run();
    timer.run();
}

void checkLPGLevel() {
    int sensorValue = analogRead(MQ2pin);
    Blynk.virtualWrite(V0, sensorValue);
    Serial.print("Sensor Value: ");
    Serial.print(sensorValue);

    Serial.print("  |  Threshold: ");
    Serial.println(LPG_THRESHOLD);
    bool isAlert = (sensorValue > LPG_THRESHOLD);
    
    digitalWrite(BuzzerPin, isAlert ? HIGH : LOW);
    updateLedBar(sensorValue);
    updateOled(sensorValue);
    Blynk.virtualWrite(V2, isAlert? "LPG LEVEL ABOVE THRESHOLD": "LPG LEVEL BELOW THRESHOLD");
    
    Blynk.virtualWrite(V1, isAlert ? 1 : 0);
    if (isAlert) {
        Blynk.logEvent("LPG_LEAK_ALERT", "LPG LEAK DETECTED!");
    }
}

void updateLedBar(int sensorValue) {
    int activeLEDs = min((int)(sensorValue / 409.5), LED_COUNT);
    
    // Cascading light effect
    if (sensorValue < LPG_THRESHOLD) {
        for (int i = 0; i < LED_COUNT; i++) {
            if (i < activeLEDs) {
                digitalWrite(LED_PINS[i], HIGH);
                delay(50);  // Dramatic sequential light-up
            } else {
                digitalWrite(LED_PINS[i], LOW);
            }
        }

    } else {
        // Pulsing effect for high levels
        for (int pulse = 0; pulse < 3; pulse++) {
            for (int i = 0; i < LED_COUNT; i++) {
                digitalWrite(LED_PINS[i], HIGH);
            }
            delay(100);
            for (int i = 0; i < LED_COUNT; i++) {
                digitalWrite(LED_PINS[i], LOW);
            }
            delay(100);
        }
    }
}

void updateOled(int sensorValue) {
    display.clearDisplay();
    
    // Dynamic status display
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("LPG: ");
    display.println(sensorValue);

    // Enhanced bar graph with more visual feedback
    int barLength = map(sensorValue, 0, 4095, 0, 64);
    display.fillRect(0, 55 - barLength, 10, barLength, SSD1306_WHITE);

    // Status text with color-coded intensity
    display.setTextSize(1);
    display.setCursor(20, 20);
    if (sensorValue > LPG_THRESHOLD) {
        display.setTextColor(SSD1306_WHITE);
        display.println("STATUS: ALERT!");
        
        // Dramatic flashing for alert
        for (int i = 0; i < 3; i++) {
            display.fillScreen(SSD1306_BLACK);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(0, 40);
            display.setTextSize(2);
            display.println("DANGER!");
            display.display();
            delay(200);
            
            display.clearDisplay();
            display.display();
            delay(200);
        }
    } else {
        display.setTextColor(SSD1306_WHITE);
        display.println("STATUS: NORMAL");
    }

    display.display();
}

void initializeOled() {
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    
    // Animated startup sequence
    for (int i = 1; i <= 3; i++) {
        display.clearDisplay();
        display.setTextSize(i);
        display.setCursor(0, 0);
        display.println("LPG");
        display.setTextSize(i);
        display.println("DETECTOR");
        display.display();
        delay(500);
    }
    
    // Scanning effect
    for (int y = 0; y < SCREEN_HEIGHT; y += 5) {
        display.drawFastHLine(0, y, SCREEN_WIDTH, SSD1306_WHITE);
        display.display();
        delay(50);
    }
    
    // Final startup message
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.println("SYSTEM");
    display.println("READY!");
    display.display();
    delay(1500);
}
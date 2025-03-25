
#define BLYNK_TEMPLATE_ID "TMPL2enzJ42fm"
#define BLYNK_TEMPLATE_NAME "microprocessor project"
#define BLYNK_AUTH_TOKEN "pxh_V61fhj-Pz815KkLGldVoSCVDYCE5"
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Define ESP32 pin connections for Nokia LCD
#define CLK 18
#define DIN 19
#define DC  21
#define CE  22
#define RST 23

// Initialize Nokia LCD with defined pins
Adafruit_PCD8544 lcd = Adafruit_PCD8544(CLK, DIN, DC, CE, RST);

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// Pins and variables
#define MQ2pin 32    // MQ2 sensor analog output pin
#define LedPin 26    // LED PIN
#define BuzzerPin 27 // BUZZER PIN
const int LPG_THRESHOLD = 1000;
/* Functions */

BlynkTimer timer;
void checkLPGLevel();
void setup() {
    pinMode(LedPin, OUTPUT);
    pinMode(BuzzerPin, OUTPUT);
    
    // Start serial
    Serial.begin(115200);
    
    // LCD SETUP
    lcd.begin();
    lcd.clearDisplay();
    lcd.setContrast(60);
    lcd.setTextSize(1);
    lcd.setTextColor(BLACK);
    lcd.display();
    
    // Connect to Blynk
    Blynk.begin(auth, ssid, pass);
    
    // Check LPG every 3 seconds
    timer.setInterval(3000L, checkLPGLevel);
}

void loop() {
    Blynk.run();
    timer.run();
}

void checkLPGLevel() {
    int sensorValue = analogRead(MQ2pin);
    Blynk.virtualWrite(V0, sensorValue);
    
    bool isAlert = (sensorValue > LPG_THRESHOLD);
    
    // Control alarm
    digitalWrite(LedPin, isAlert ? HIGH : LOW);
    digitalWrite(BuzzerPin, isAlert ? HIGH : LOW);
    
    // Update Blynk
    Blynk.virtualWrite(V1, isAlert ? 1 : 0);
    if (isAlert) {
        Blynk.logEvent("LPG_LEAK_ALERT", "LPG LEAK DETECTED!");
    }
    
    //  update LCD 
    lcd.clearDisplay();
    lcd.setCursor(5, 0);
    lcd.print("LPG MONITOR");
    
    lcd.setCursor(0, 15);
    lcd.print("Level: ");
    lcd.print(sensorValue);
    
    lcd.setCursor(0, 30);
    if (isAlert) {
        lcd.print("ALERT: LPG LEAK!");
    } else {
        lcd.print("Status: Normal");
    }
    
    lcd.display();
}
#define BLYNK_TEMPLATE_ID "TMPL3Dkypls3P"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "km3MLS9VlqaUjY0w5DbuoVx3yQdW_iV6"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

char ssid[] = "sumithere";
char pass[] = "yeshu400";

#define DHTPIN 2
#define DHTTYPE DHT11
#define SOIL_PIN 4
#define PIR_PIN 13

// CHANGED: Using Pin 25 to rule out a faulty Pin 23
#define RELAY_PIN 25 

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x3F, 16, 2); 
BlynkTimer timer;

// This function controls the water pump via Virtual Pin V14
BLYNK_WRITE(V14) {
  int relayState = param.asInt(); 
  
  // LOGIC FIX: Reversing the state (!relayState) for Active Low relays
  digitalWrite(RELAY_PIN, !relayState); 
  
  Serial.print("V14 App Switch is: ");
  Serial.print(relayState);
  Serial.print(" | Sending Signal to Pin 25: ");
  Serial.println(!relayState);
}

void sendData() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int soilVal = analogRead(SOIL_PIN);
  int soilPer = map(soilVal, 0, 4095, 100, 0);

  Blynk.virtualWrite(V5, t);       
  Blynk.virtualWrite(V6, h);       
  Blynk.virtualWrite(V8, soilPer); 

  lcd.setCursor(0, 0);
  lcd.print("T:"); lcd.print((int)t); lcd.print("C H:"); lcd.print((int)h); lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Soil: "); lcd.print(soilPer); lcd.print("%   ");
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  lcd.init();
  lcd.backlight();

  pinMode(PIR_PIN, INPUT);
  
  // Initialize Relay
  pinMode(RELAY_PIN, OUTPUT);     
  digitalWrite(RELAY_PIN, HIGH); // For Active Low relays, HIGH usually keeps it OFF

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, sendData);
  
  Serial.println("System Ready. Waiting for V14 command...");
}

void loop() {
  Blynk.run();
  timer.run();

  if (digitalRead(PIR_PIN) == HIGH) {
    Blynk.logEvent("pirmotion", "Motion Detected!");
    delay(500); 
  }
}
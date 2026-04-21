#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pins
const int alcoholSensorPin = A0;
const int wearSensorPin = A1;
const int sleepSensorPin = A2;
const int buzzerPin = 7;

// Variables
int helmetStatus = 0;
int alcoholLevel = 0;
int sleepStatus = 0;

// Timing
unsigned long lastPageSwitch = 0;
const unsigned long pageInterval = 3000;
int page = 0;

void setup() {
  Serial.begin(9600);

  pinMode(wearSensorPin, INPUT);
  pinMode(alcoholSensorPin, INPUT);
  pinMode(sleepSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smart Helmet");
  delay(1000);
  lcd.clear();
}

void loop() {
  // Read sensors
  alcoholLevel = !digitalRead(alcoholSensorPin);
  sleepStatus  = !digitalRead(sleepSensorPin);
  helmetStatus = !digitalRead(wearSensorPin);

  // Buzzer logic
  if (sleepStatus || alcoholLevel) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  // Page switching
  if (millis() - lastPageSwitch > pageInterval) {
    lastPageSwitch = millis();
    page = (page + 1) % 2;
    lcd.clear();
  }

  // Display
  if (page == 0) {
    lcd.setCursor(0, 0);
    lcd.print("Helmet: ");
    lcd.print(helmetStatus ? "Yes" : "No ");

    lcd.setCursor(0, 1);
    lcd.print("Alcohol: ");
    lcd.print(alcoholLevel ? "Yes" : "No ");
  } 
  else {
    lcd.setCursor(0, 0);
    lcd.print("Sleep: ");
    lcd.print(sleepStatus ? "Yes" : "No ");

    lcd.setCursor(0, 1);
    lcd.print("Status: ");
    if (alcoholLevel) lcd.print("DRUNK ");
    else if (sleepStatus) lcd.print("SLEEP ");
    else lcd.print("SAFE  ");
  }

  delay(200);
}

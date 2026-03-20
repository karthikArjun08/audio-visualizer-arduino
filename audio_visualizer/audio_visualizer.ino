#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pins
#define MIC_PIN A0
#define LED_PIN 6

// Variables
int soundValue = 0;
int brightness = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(9600);

  // OLED Init
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while(true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, 20);
  display.println("Audio System");
  display.display();
  delay(2000);
}

void loop() {

  // Read sound
  soundValue = analogRead(MIC_PIN);

  // Convert to brightness
  brightness = map(soundValue, 0, 1023, 0, 255);

  // Control LED (PWM)
  analogWrite(LED_PIN, brightness);

  // Serial Monitor (optional)
  Serial.print("Sound: ");
  Serial.print(soundValue);
  Serial.print("  Brightness: ");
  Serial.println(brightness);

  // OLED Display
  display.clearDisplay();

  display.setCursor(0, 10);
  display.print("Sound Level:");

  display.setCursor(0, 30);
  display.print(soundValue);

  display.setCursor(0, 50);
  display.print("LED:");
  display.print(brightness);

  display.display();

  delay(50);
}
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define r   27
#define g 26
#define b  25

#define buzz 33

#define BTN1 32
#define BTN2 35
#define BTN3 34
#define BTN4 39

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10, 25);
  display.println("❤️ Hello");
  display.display();

  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);

  pinMode(BUZZERbuzz_PIN, OUTPUT);

  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(BTN3, INPUT);
  pinMode(BTN4, INPUT);

  digitalWrite(r, HIGH);
  delay(300);
  digitalWrite(g, HIGH);
  delay(300);
  digitalWrite(b, HIGH);
  delay(300);
  digitalWrite(r, LOW);
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);

  tone(buzz, 1000, 200);
}

void loop() {
  if (digitalRead(BTN1) == HIGH) Serial.println("Button 1 pressed");
  if (digitalRead(BTN2) == HIGH) Serial.println("Button 2 pressed");
  if (digitalRead(BTN3) == HIGH) Serial.println("Button 3 pressed");
  if (digitalRead(BTN4) == HIGH) Serial.println("Button 4 pressed");

  delay(100);
}

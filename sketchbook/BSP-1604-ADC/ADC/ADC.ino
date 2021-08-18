
#include <Tiny4kOLED.h>

int adc1 = 0;
int adc2 = 0;
int adc3 = 0;
#define LED 1

void setup() {
  pinMode(LED, OUTPUT);
  
  oled.begin(128, 64, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);
}

void loop() {
  delay(500);
  
  digitalWrite(LED, LOW);
  adc1 = analogRead(8);
  adc2 = analogRead(9);
  adc3 = analogRead(10);
  oled.clear();
  normalSize();
  oled.on();
  digitalWrite(LED, HIGH);
}

void normalSize() {
  oled.setFont(FONT6X8P);
  oled.setCursor(0, 1);
  oled.print("ADC1-button");
  oled.setCursor(0, 2);
  oled.print("ADC2-current");
  oled.setCursor(0, 3);
  oled.print("ADC3-VOLT");

  oled.setCursor(90, 1);
  oled.print(adc1);

  oled.setCursor(90, 2);
  oled.print(adc2);

  oled.setCursor(90, 3);
  oled.print(adc3);
  
}

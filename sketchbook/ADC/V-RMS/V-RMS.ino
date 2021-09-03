#include <Tiny4kOLED.h>

const byte inPin = 9;

int k = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(inPin, INPUT);
  oled.begin(128, 64, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);

}


void loop() {
  loop_100();
  Serial.print("max set to : ");
  Serial.println(k);
  oled.clear();
  // 6X 16P
  oled.setFont(FONT8X16P);
  oled.setCursor(0, 1);
  oled.println("ADC9-VAC");
  oled.setCursor(90, 1);
  oled.print(k - 525);
  oled.on();
}




void loop_100() {
  int max = 0;
  for ( int i = 0; i < 200; i++ ) {
    int temp = analogRead(inPin);
    if (temp > max)
    {
      max = temp;
    }
    delay(5);
  }
  k = max;

}

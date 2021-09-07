
#include <Tiny4kOLED.h>

int adc1 = 0;
int ctrl_flag = 0;

#define BTN 8
#define LED 0

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  oled.begin(128, 64, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);


}

void loop() {

  adc1 = analogRead(BTN);
  if (adc1 < 100 && adc1 > 50) {
    ctrl_flag = 0;
  }
  if (adc1 > 100 ) {
    ctrl_flag = 1;
  }
  if (adc1 < 20 ) {
    ctrl_flag = 2;
  }


  oled.clear();
  OLED_Write();
  oled.on();

  if ( ctrl_flag == 2) {
    digitalWrite( LED, LOW);
    delay(20);
  } else {
    digitalWrite( LED, HIGH);
    delay(3000);
  }


}

void OLED_Write() {

  // FONT6X8P FONT8X16P
  oled.setFont(FONT8X16P);
  oled.setCursor(0, 2);
  oled.print("BTN");
  oled.setCursor(0, 4);
  oled.print("OUT");

  if (ctrl_flag == 0) {
    oled.setCursor(40, 2);
    oled.print(" LEFT !");
    oled.setCursor(40, 4);
    oled.print(" = 1");
  }

  if (ctrl_flag == 1) {
    oled.setCursor(40, 2);
    oled.print(" RIGHT !");
    oled.setCursor(40, 4);
    oled.print(" = 1");
  }

  if (ctrl_flag == 2) {
    oled.setCursor(40, 2);
    oled.print(" = N/A !");
    oled.setCursor(40, 4);
    oled.print(" = 0");
  }

}

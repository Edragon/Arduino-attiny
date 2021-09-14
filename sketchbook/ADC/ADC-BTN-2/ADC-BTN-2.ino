
#include <Tiny4kOLED.h>

int adc1 = 0;
int ctrl_flag = 0;

int AOP = 0;

#define BTN 8
#define OP 9
#define IP 0

void setup() {
  pinMode(OP, OUTPUT);
  //digitalWrite(LED, LOW);
  
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
  if (adc1 < 20 ) { // no button
    ctrl_flag = 2;
  }

  oled.clear();
  OLED_Write();
  oled.on();

  if ( ctrl_flag == 0) {
    AOP +=10;
    delay(20);
  }
  if ( ctrl_flag == 1) {
    AOP -=10;
    delay(20);
  }
  
  analogWrite(OP, AOP);
  
}

void OLED_Write() {

  // FONT6X8P FONT8X16P
  oled.setFont(FONT8X16P);
  oled.setCursor(0, 2);
  oled.print("BTN");
  oled.setCursor(0, 4);
  oled.print("D9:");

  if (ctrl_flag == 0) {
    oled.setCursor(40, 2);
    oled.print(" LEFT BTN DN!");
    oled.setCursor(40, 4);
    oled.print(AOP);
  }

  if (ctrl_flag == 1) {
    oled.setCursor(40, 2);
    oled.print(" RIGHT BTN DN!");
    oled.setCursor(40, 4);
    oled.print(AOP);
  }

  if (ctrl_flag == 2) {
    oled.setCursor(40, 2);
    oled.print(" = N/A !");
    oled.setCursor(40, 4);
    oled.print(AOP);
  }

}

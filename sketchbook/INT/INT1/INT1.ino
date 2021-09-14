
#include <Tiny4kOLED.h>

void setup()
{
  oled.begin(128, 64, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);
  attachInterrupt(2, trigger, FALLING);
  attachInterrupt(0, trigger, FALLING);
  attachInterrupt(1, trigger, FALLING);
  attachInterrupt(3, trigger, FALLING);  
  //attachInterrupt(9, trigger, RISING);  
}

void trigger()  // function to be fired at the zero crossing to dim the light
{
  oled.clear();
  OLED_Write_1();
  oled.on();
  delay(200);
}

void loop()
{
//  oled.clear();
//  OLED_Write_2();
//  oled.on();
//  delay(200);

}



void OLED_Write_1() {
  // FONT6X8P FONT8X16P
  oled.setFont(FONT8X16P);
  oled.setCursor(0, 2);
  oled.print("BTN");
  oled.setCursor(40, 2);
  oled.print(" Trigger !!");
}

void OLED_Write_2() {
  // FONT6X8P FONT8X16P
  oled.setFont(FONT8X16P);
  oled.setCursor(0, 2);
  oled.print("INT ");
  oled.setCursor(40, 2);
  oled.print(" no ...");

}

#include <Button.h>

int LED = 4; // LED
int BTN = 1; // press button

Button button1(1); // Connect your button between pin 2 and GND

void setup() {
  pinMode(LED, OUTPUT);
  button1.begin();

  while (!Serial) { }; // for Leos
  Serial.begin(9600);
}

void loop() {
  if (button1.toggled()) {
    if (button1.read() == Button::PRESSED)
      digitalWrite(LED, HIGH);
    else
      digitalWrite(LED, LOW);
  }
}

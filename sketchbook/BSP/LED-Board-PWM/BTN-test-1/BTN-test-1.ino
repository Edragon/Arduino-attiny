int LED = 4; // LED
int BTN = 1; // press button

//int value = 0;
bool flag = false;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);

}


void loop() {
  int buttonState = digitalRead(BTN);

  if (buttonState == LOW) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }

}

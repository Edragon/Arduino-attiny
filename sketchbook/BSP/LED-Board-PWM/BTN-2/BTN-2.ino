int LED = 4; // LED
int BTN = 1; // press button

//int value = 0;
bool flag = false;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
  
  analogWrite(LED, 0); // close LED output
}

void loop() {
  int buttonState = digitalRead(BTN);

  if (buttonState == LOW) {
    flag = true;
    //delay(500);
  }
  
  if (flag == true) {
  
    analogWrite(LED, 255);
    delay(3000);
    flag = false;
  }

  
  //delay(500);
}

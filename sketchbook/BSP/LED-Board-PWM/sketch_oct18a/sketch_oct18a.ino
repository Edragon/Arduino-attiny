int ledPin = 4;
int buttonPin = 1;

int value = 0;
int reading = 0;
//int lastButtonState = LOW;
int buttonState;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  analogWrite(ledPin, 255);
}


void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    value = 255;
    //delay(500);
  }

//  if ( value > 255) {
//    value = 0;
//  }

  analogWrite(ledPin, value);
  //delay(500);
}

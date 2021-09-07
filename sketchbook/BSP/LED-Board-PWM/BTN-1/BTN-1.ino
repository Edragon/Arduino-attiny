int ledPin = 4;
int buttonPin = 1;

int value = 0;
int reading = 0;
int lastButtonState = LOW;
int buttonState;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  analogWrite(ledPin, 0);
}



void loop() {
  BTN_read();

  if (buttonState == LOW) {
    value += 50;
  }

  if ( value > 255) {
    value = 0;
  }

  analogWrite(ledPin, value);
  delay(10);
}



void BTN_read() {
  reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
    }
  }
}

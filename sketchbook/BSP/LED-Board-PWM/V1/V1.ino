#define LED 4
#define IR 0
#define GND_detect 3
#define BTN 1

// attiny 202
// use internal clock 8MHZ

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(IR, INPUT);
  pinMode(GND_detect, INPUT);
}


void loop() {
  
  if (digitalRead (GND_detect) == 0 ) {
    digitalWrite(LED, HIGH);
    delay(2000);

    digitalWrite(LED, LOW);
    delay(2000);
  }
  
}

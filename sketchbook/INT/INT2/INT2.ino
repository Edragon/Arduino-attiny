unsigned long previousMillis;
byte ledState;
volatile byte interrupt1 = 0; // changed in ISR, so must be volatile or compiker will optimize it away.
volatile byte interrupt2 = 0;
volatile byte interrupt3 = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12,INPUT_PULLUP); //PC2
  pinMode(14,INPUT_PULLUP); //PA1
  pinMode(15,INPUT_PULLUP); //PA2
  pinMode(9,INPUT_PULLUP); //PB0
  PORTC.PIN2CTRL=0b00001101; //PULLUPEN=1, ISC=5 trigger low level
  PORTA.PIN1CTRL=0b00001010; //PULLUPEN=1, ISC=2 trigger rising
  PORTA.PIN2CTRL|=0x02; //ISC=2 trigger rising - uses |= so current value of PULLUPEN is preserved
  PORTB.PIN0CTRL=0b00001001; //PULLUPEN=1, ISC=1 trigger both
  Serial.begin(115200);
  delay(10);
  Serial.println("Startup");

}

void loop() {
  if (interrupt1){
    interrupt1=0;
    Serial.println("I1 fired");
  }
  if (interrupt2){
    interrupt2=0;
    Serial.println("I2 fired");
  }
  if (interrupt3){
    interrupt3=0;
    Serial.println("I3 fired");
  }
  //BlinkWithoutDelay, just so you can confirm that the sketch continues to run.
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(LED_BUILTIN, ledState);
  }
}

ISR(PORTA_PORT_vect) {
  byte flags=PORTA.INTFLAGS;
  PORTA.INTFLAGS=flags; //clear flags
  if (flags&0x02) {
    interrupt1=1;
  }
  if (flags&0x04) {
    interrupt2=1;
  }
}

ISR(PORTB_PORT_vect) {
  PORTB.INTFLAGS=1; //we know only PB0 has an interrupt, so that's the only flag that could be set.
  interrupt3=1;
}

ISR(PORTC_PORT_vect) {
  _PROTECTED_WRITE(RSTCTRL.SWRR,1); //make this pin into an ersatz reset pin.
}

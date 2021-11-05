
void setup()
{
  Serial.begin(115200);

  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
}


void loop()
{
  Serial.println("\nI2C Scanner");
  delay(200);           // wait 5 seconds for next scan
}

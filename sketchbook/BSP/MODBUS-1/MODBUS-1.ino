#define IN1 0
#define IN2 1
#define OUT1 9
#define OUT2 10
#define OE 8

void setup() {
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  digitalWrite (OUT1, LOW);
  digitalWrite (OUT2, LOW);

  pinMode(OE, OUTPUT);
  digitalWrite (OE, HIGH);

  pinMode(IN1, INPUT);
  pinMode(IN2, INPUT);

  Serial.begin(9600);
}


void loop() {

  digitalWrite (OUT1, LOW);
  Serial.print(INP1);
  Serial.print("--");
  Serial.print(INP2);
  Serial.print("--TEST !");
  delay(500);

  digitalWrite (OUT1, HIGH);
  Serial.print(INP1);
  Serial.print("--");
  Serial.print(INP2);
  Serial.print("--TEST !");
  delay(500);  

}

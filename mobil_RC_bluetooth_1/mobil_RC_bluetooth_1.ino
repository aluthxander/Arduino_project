int in1 = 5;
int in2 = 4;
int in3 = 3;
int in4 = 2;


void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  delay(1000);
}

void loop() {

  if(Serial.available() > 0){
    char data = Serial.read();
    Serial.println(data);
    switch(data){
      case '0':
        maju();
        break;
      case '1':
        berhenti();
        break;
      case '2':
        mundur();
        break;
      case '3':
        belok_kanan();
        break;
      case '4':
        belok_kiri();
        break;
      default:
        break;
    }
  }

}

void maju() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.print("\n");
  Serial.println(digitalRead(in1));
  Serial.println(digitalRead(in2));
  Serial.println(digitalRead(in3));
  Serial.println(digitalRead(in4));
}
void berhenti() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.print("\n");
  Serial.println(digitalRead(in1));
  Serial.println(digitalRead(in2));
  Serial.println(digitalRead(in3));
  Serial.println(digitalRead(in4));
}
void mundur() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.print("\n");
  Serial.println(digitalRead(in1));
  Serial.println(digitalRead(in2));
  Serial.println(digitalRead(in3));
  Serial.println(digitalRead(in4));
}
void belok_kiri() {
//  digitalWrite(in1, LOW);
//  digitalWrite(in2, LOW);
//  digitalWrite(in3, LOW);
//  digitalWrite(in4, LOW);
//  delay(500);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.print("\n");
  Serial.println(digitalRead(in1));
  Serial.println(digitalRead(in2));
  Serial.println(digitalRead(in3));
  Serial.println(digitalRead(in4));
  delay(380);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(500);
}

void belok_kanan() {
//  digitalWrite(in1, LOW);
//  digitalWrite(in2, LOW);
//  digitalWrite(in3, LOW);
//  digitalWrite(in4, LOW);
//  delay(500);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.print("\n");
  Serial.println(digitalRead(in1));
  Serial.println(digitalRead(in2));
  Serial.println(digitalRead(in3));
  Serial.println(digitalRead(in4));
  delay(380);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(500);
}

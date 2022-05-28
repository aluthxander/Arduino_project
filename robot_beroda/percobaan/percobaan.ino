#include <Servo.h>
Servo servoku;

int in1 = 5;
int in2 = 4;
int in3 = 3;
int in4 = 2;

const int trig = 6;
const int echo = A0;
long durasi;
int jarak = 0;
int pos = 90;

void setup() {
  servoku.attach(9);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  delay(1000);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  durasi = pulseIn(echo, HIGH);
  jarak = durasi * 0.034 / 2;
  Serial.print("jarak :");
  Serial.print(jarak);
  Serial.println(" CM");

  if (jarak < 40 && jarak > 20) {
    belok_kiri();
  } else if (jarak <= 20) {
    belok_kanan();
  }
  else {
    maju();
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

void belok_kiri() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  mata_robot();
  delay(1000);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.print("\n");
  Serial.println(digitalRead(in1));
  Serial.println(digitalRead(in2));
  Serial.println(digitalRead(in3));
  Serial.println(digitalRead(in4));
  delay(500);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(1000);
}

void belok_kanan() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  mata_robot();
  delay(1000);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.print("\n");
  Serial.println(digitalRead(in1));
  Serial.println(digitalRead(in2));
  Serial.println(digitalRead(in3));
  Serial.println(digitalRead(in4));
  delay(500);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(1000);
}

int mata_robot(){
  for (pos = 90; pos <= 180; pos += 1)
  {
    servoku.write(pos);
    delay(5); 
  }
  delay(500);
  for (pos; pos >= 1; pos -= 1)
  {
    servoku.write(pos);
    delay(5);
  }
  delay(500);
  for (pos; pos <= 90; pos += 1)
  {
    servoku.write(pos);
    delay(5);
  }
  delay(500);
}

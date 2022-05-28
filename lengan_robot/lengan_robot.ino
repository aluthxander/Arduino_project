# include <Servo.h>
Servo servo1, servo2, servo3, servo4;
int pot1 = A0;
int pot2 = A1;
int pot3 = A2;
int pot4 = A3;
int nilai1, nilai2, nilai3, nilai4;

void setup() {
  servo1.attach(4);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(7);
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(pot3, INPUT);
  pinMode(pot4, INPUT);
  Serial.begin(9600);
}

void loop() {
  nilai1 = map(analogRead(pot1),0,1024,0,181);
  nilai2 = map(analogRead(pot2),0,1024,0,181);
  nilai3 = map(analogRead(pot3),0,1024,0,181);
  nilai4 = map(analogRead(pot4),0,1024,0,181);
  Serial.println(nilai1);
  Serial.println(nilai2);
  Serial.println(nilai3);
  Serial.println(nilai4);
  
  servo1.write(nilai1);
  servo2.write(nilai2);
  servo3.write(nilai3);
  servo4.write(nilai4);
  delay(15);
}

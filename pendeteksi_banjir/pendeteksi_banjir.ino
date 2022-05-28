#define NOTE_E4 330
const int trig = 5;
const int echo = 6;
int led[3]={10,11,12};
int drimer=9;
long durasi;
int jarak;
void setup() {
Serial.begin(9600);
pinMode(led[3], OUTPUT);
pinMode(drimer, OUTPUT);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
}

void loop() {
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
durasi=pulseIn(echo, HIGH);
jarak=durasi*0.034/2;
Serial.print("durasi : ");
Serial.println(durasi);
Serial.print("jarak : ");
Serial.print(jarak);
Serial.println(" CM");
delay(500);
if(jarak<=5){
  tone(drimer, NOTE_E4, 330);
  digitalWrite(led[2], HIGH);
}else{
  digitalWrite(led[2], LOW);
}
if(jarak<=12){
  digitalWrite(led[1], HIGH);
}else{
  digitalWrite(led[1], LOW);
}
if(jarak>1){
  digitalWrite(led[0], HIGH);
}else{
  digitalWrite(led[0], LOW);
}
}

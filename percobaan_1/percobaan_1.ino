#define NOTE_C4 262 //do
#define NOTE_D4 294 //re
#define NOTE_E4 330 //mi
#define NOTE_F4 349 //fa
#define NOTE_G4 392 //sol
int led[5]={8,9,10,11,12};
int ldr= A0;
int drimer=7;
int sensor;
void setup() {
pinMode(led[5], OUTPUT);
pinMode(drimer, OUTPUT);
pinMode(ldr, INPUT);
Serial.begin(9600);
}
void loop() {
sensor= analogRead(ldr);
Serial.println(sensor);
if(sensor>180){
  tone(drimer, NOTE_C4, 500);
  digitalWrite(led[0], HIGH);
}else{
  digitalWrite(led[0], LOW);
}
if(sensor>360){
  tone(drimer, NOTE_D4,500);
  digitalWrite(led[1], HIGH);
}else{
  digitalWrite(led[1], LOW);
}
if(sensor>540){
  tone(drimer, NOTE_E4,500);
  digitalWrite(led[2], HIGH);
}else{
  digitalWrite(led[2], LOW);
}
if(sensor>720){
  tone(drimer, NOTE_F4,500);
  digitalWrite(led[3], HIGH);
}else{
  digitalWrite(led[3], LOW);
}
if(sensor>900){
  tone(drimer, NOTE_G4,500);
  digitalWrite(led[4], HIGH);
}else{
  digitalWrite(led[4], LOW);
}
}

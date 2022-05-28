#include <LiquidCrystal.h>

//setying lcd RS,E,D4,D5,D6,D7
LiquidCrystal lcd(6,7,9,10,11,12);
int sensor= A0;
float suhu, data;

void setup() {
//memilih jenis LCD contoh LCD 16*2
analogReference(INTERNAL);
Serial.begin(9600);
pinMode(sensor, INPUT);
lcd.begin(16,2);
lcd.print("sensor suhu");

}

void loop() {
data = analogRead(sensor);
suhu = data*110/1024;
Serial.print("suhu :");  
Serial.println(suhu);
 
lcd.setCursor(0,1);
lcd.print("suhu :");
lcd.print(suhu);
lcd.print(" C");
delay(500);


}

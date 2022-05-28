#include <DS3231.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(6,7,9,10,11,12);
DS3231 rtc(SDA, SCL);
String hari, waktu, tanggal;
const int relay = 2;
bool nyala = LOW;
bool mati = HIGH;

void setup() {
  lcd.begin(16,2);
  rtc.begin();
  pinMode(relay, OUTPUT);
  digitalWrite(relay, mati);
  Serial.begin(9600);
  //rtc.setDOW(THURSDAY);
  rtc.setTime(07,55,0);
  //rtc.setDate(15,10,2020);
  //lcd.print("Project 1");
  delay(1000);
}

void loop() {
  hari = rtc.getDOWStr();
  waktu = rtc.getTimeStr();
  tanggal = rtc.getDateStr();
  Serial.print(hari);
  Serial.print(", ");
  Serial.print(waktu);
  Serial.print(", ");
  Serial.println(tanggal);
  lcd.setCursor(0,0);
  lcd.print(waktu);
  lcd.setCursor(0,1);
  if(waktu == "08:00:00"){
    digitalWrite(relay, nyala);
  }else if(waktu == "16:00:00"){
    digitalWrite(relay, mati);
  }
  delay(1000);
  lcd.clear();

}

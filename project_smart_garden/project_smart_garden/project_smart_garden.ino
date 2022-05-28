#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int bacakelembaban = A0; //sensor kelembapan dihubungkan dengan pin A0
int nilai;
int relay = D6;//relay untuk mengatur smartlock
int relay2 = D5;//relsy untuk pompa air
bool hidup = LOW, mati = HIGH;//kondisi relay

char auth[] = "TE5xGMRrsNjPFhA6eGKkpzF-m3o22Ivo";//kode authentifikasi
char ssid[] = "lutfan";//nama wifi
char pass[] = "dasarbangsat";//password wifi
BlynkTimer timer;

//smart lock
//membaca input dari aplikasi blynk pada pin virtual 0
BLYNK_WRITE(V0){
  int pinV0 = param.asInt();//untuk mengambil niali inputan dari blynk
  Serial.print("nilai V0 :");
  Serial.println(pinV0);
  if(pinV0 == 1){
    digitalWrite(relay, hidup);
  }else{
    digitalWrite(relay, mati);
  }
}

void setup() {
//  untuk mengatur mode pin
  pinMode(relay, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(bacakelembaban, INPUT);
  Serial.begin(9600);
  digitalWrite(relay, mati);
  digitalWrite(relay2, mati);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000, kelembapan);
}

void loop() {
  Blynk.run();
  timer.run();
}

void kelembapan(){
  nilai = 1024 - analogRead(bacakelembaban);
  Serial.print("Kelembaban tanah : ");
  Serial.println(nilai);
//  mengirim output sensor ke aplikasi blynk pada pin V1
  Blynk.virtualWrite(1, nilai);
  if(nilai <= 100){
    Blynk.notify("Tanah butuh air");
    digitalWrite(relay2, hidup);
  }else {
    digitalWrite(relay2, mati);
  }
}

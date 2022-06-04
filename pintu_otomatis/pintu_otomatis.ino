int sensor_pir = 2;
int led = 10;
int IN1 = 1;
int IN2 = 0;
int statusPir = 0;

void setup() {
  pinMode(sensor_pir, INPUT);
  pinMode(led, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  delay(1000);
}

void loop() {
  statusPir = digitalRead(sensor_pir);
  if(statusPir == HIGH){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(led, HIGH);
    delay(1000);
    }else{
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(led, LOW);
      delay(1000);
    }
}

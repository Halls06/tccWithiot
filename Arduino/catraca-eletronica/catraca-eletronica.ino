#define pinoTrig 2
#define pinoEcho 3
#define LED1 4
#define LED2 5
#define pinoServo 6
#define pinoBotao 7

#include <Servo.h>

Servo meuservo;


long tempo_us;
float distancia_m;
float distancia_cm;

void setup() {
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP);
  meuservo.attach(pinoServo);
  meuservo.write(0);
}

void loop() {
  digitalWrite(pinoTrig, LOW);
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);

  tempo_us = pulseIn(pinoEcho, HIGH);

  distancia_m = tempo_us / pow(10, 6) * 343 / 2;
  distancia_cm = distancia_m * 100;

  if(distancia_cm < 10) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  if(digitalRead(pinoBotao) == LOW) {
    meuservo.write(90);
  }

  }else {
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
    delay(2000);
    meuservo.write(0);
  }

  meuservo.write(0);
  delay(2000);
  meuservo.write(90);
  delay(2000);
  meuservo.write(180);
  delay(2000);

}

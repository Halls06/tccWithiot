#include <Servo.h>

int pinoBotao = 2;
int pinoServo = 3;

Servo meuservo;

int position = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinoBotao, INPUT_PULLUP);
  meuservo.attach(pinoServo);
}

void loop(){
  if (digitalRead(pinoBotao) == LOW){
    position = position + 10;
     if (position > 180){
      position = 0;
     }
     meuservo.write(position);
     delay(500);
  }
}


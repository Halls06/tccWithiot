#include <Servo.h>

#define pinoServo 7
Servo meuservo;

void setup() {
  Serial.begin(9600);
  meuservo.attach(pinoServo);

}

void loop() {
   
    if(Serial.available>0){
    char c = Serial.read();
    if(c == 'A'){
      meuservo.write(180);
    }
    else if(c == 'R'){
      meuservo.write(0);
    }
   }
}

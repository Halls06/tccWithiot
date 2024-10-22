#include <Servo.h>
 
#define pinoServo 3
 
Servo meuservo;
 
void setup() {
  meuservo.attach(pinoServo);
}
 
void loop() {
  meuservo.write(0);
  delay(2000);
  meuservo.write(90);
  delay(2000);
  meuservo.write(180);
  delay(2000);
}
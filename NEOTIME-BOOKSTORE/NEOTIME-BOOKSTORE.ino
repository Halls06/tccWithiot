//usando A Biblioteca Neotimer


/*#include <neotimer.h>


Neotimer bled4;
Neotimer gled5;
Neotimer rled6;


/*int bled = 4;
int gled = 5;
int rled = 6;


void setup(){
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  bled4.set(2000);
  gled5.set(2000);
  rled6.set(6000);

}

void loop(){
  static bool estado = LOW;

  /*if(bled4.repeat()){
    estado = !estado;
    digitalWrite(4, estado);
  }
  if(gled5.repeat()){
    digitalWrite(6, !digitalRead(6));
  }
  if(rled6.repeat()){
    digitalWrite(4, !digitalRead(4));
  }
  }
*/
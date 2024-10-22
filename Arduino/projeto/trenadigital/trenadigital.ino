// Curso Aprenda C/C++: Fundamentos de Programação para Arduino
// Autor: MakerHero
// Projeto 5 (parte 2) - Trena Digital
 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
#define pinoBotao 2
#define pinoEcho 3
#define pinoTrig 4

 
#define pinoBotao 2
#define pinoEcho 3
#define pinoTrig 4
 
LiquidCrystal_I2C meulcd(0x27,16,2);
 
long tempo_us; 
float distancia_m;
float distancia_cm; 
float distancia;
String unidade = "";
int unidadeSelecionada = 0;
int programa = 0;
 
void setup(){
  pinMode(pinoBotao, INPUT_PULLUP);
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT); 
  meulcd.init();
  meulcd.backlight();
}
  
void loop(){
  switch(programa){
     
    case 0:
      meulcd.setCursor(0, 0);
      meulcd.print("Selecione a ");
      meulcd.setCursor(0, 1);
      meulcd.print("unidade: ");
      meulcd.setCursor(13, 1);
      meulcd.print(unidade);
      meulcd.print(" ");
      delay(100);
      if (digitalRead(pinoBotao) == LOW) {
        if (unidadeSelecionada == 0) {
          unidade = "cm";
          unidadeSelecionada = 1;
        }
        else if (unidadeSelecionada == 1) {
          unidade = "m";
          unidadeSelecionada = 0;
        }
        delay(500);
        if (digitalRead(pinoBotao) == LOW) {
          programa = 1;
          meulcd.clear();
          delay(500);
        } 
      }
    break;
 
    case 1:
      digitalWrite(pinoTrig, LOW);
      digitalWrite(pinoTrig, HIGH);
      delayMicroseconds(10);
      digitalWrite(pinoTrig, LOW);
      tempo_us= pulseIn(pinoEcho, HIGH); 
   
      distancia_m = tempo_us / pow(10,6) * 343 / 2;
      distancia_cm = distancia_m * 100; 
   
      if (unidadeSelecionada == 0) {
        distancia = distancia_cm;
        unidade = "cm";
      }
      else if (unidadeSelecionada == 1) {
        distancia = distancia_m;
        unidade = "m";
      }
      meulcd.setCursor(0,0);
      meulcd.print("Distancia: ");
      meulcd.setCursor(4,1);
      meulcd.print(distancia);
      meulcd.print(" ");
      meulcd.print(unidade);
      delay(500);
      if (digitalRead(pinoBotao) == LOW) {
        programa = 0;
        meulcd.clear();
        delay(500);
      }
    break;
  }
}


  //meulcd.setCursor(3, 0);
  //meulcd.print("Ola maker!");
  //delay(3000);
  //meulcd.clear();

  //meulcd.setCursor(0, 0);
  //meulcd.print("Bem vindo ao projeto 5 do modulo 3");

  //for(int i=0; i <= 17; i++) {
    //meulcd.scrollDisplayLeft();
    //delay(5000);

    //meulcd.clear()
  

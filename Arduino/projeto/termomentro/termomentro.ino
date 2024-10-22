#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define pinoLED 2
#define pinoServo 3
#define pinoTermistor A0

LiquidCrystal_I2C meulcd(0x27,16,2);
Servo meuservo;

const float vcc =5;
const float r =20000;
const float r0 =10000;
const float beta =342;
const float t0 =273 + 25;


float temperatura;
float posicao = 0;


void setup() {
  pinMode(pinoLED, OUTPUT);
  digitalWrite(pinoLED, LOW);

  meulcd.init();
  meulcd.backlight();

  meuservo.attach(pinoServo);
  meuservo.write(posicao);

}

void loop() {
  int leitura = analogRead(pinoTermistor);
  float v= (vcc*leitura)/1024;
  float rt =r*(vcc-v/v);
  float rx =r0*exp(-beta/t0);
  float t = beta/log(rt/rx);
  float temperatura = t-273;

  posicao = map(temperatura, 10, 80, 0, 180);
  meuservo.write(posicao);

  if (temperatura > 45) {
    for (int i=0; i<5; i++){
      digitalWrite(pinoLED, HIGH);
      delay(100);
      digitalWrite(pinoLED, LOW);
      delay(100);
    }
    meulcd.clear();
    meulcd.setCursor(2,0);
    meulcd.print("Temperatura: ");
    meulcd.setCursor(5,1);
    meulcd.print(temperatura);
    meulcd.print(char(223));
    meulcd.print("c");
    delay(1000);
    meulcd.setCursor(1,0);
    meulcd.print("FOGO DETECTADO");
    delay(2000);
  
  }else {
    meulcd.clear();
    meulcd.setCursor(2,0);
    meulcd.print("Temperatura: ");
    meulcd.setCursor(5,1);
    meulcd.print(temperatura);
    meulcd.print(char(223));
    meulcd.print("c");
    delay(1000);
  }
}

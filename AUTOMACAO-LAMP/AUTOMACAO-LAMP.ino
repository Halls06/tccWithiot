//lampada com sensor HC-SR04 E RELE JQC3F-05VDC-C 

#define Rele 3
#define cm 60
#define pinEcho 7
#define pinTrig 6

long tempo_us;
float distancia_m;
float distancia_cm;

void setup() {
  pinMode(Rele, OUTPUT);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(pinTrig, LOW);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  tempo_us = pulseIn(pinEcho, HIGH);

  distancia_m = tempo_us / pow(10, 6) * 343 / 2;
  distancia_cm = distancia_m * 100;


  if (distancia_cm < cm) {
    digitalWrite(Rele, LOW);
  } else {
    digitalWrite(Rele, HIGH);
    delay(60000);
  }

  Serial.print("distancia cm");
  Serial.println(distancia_cm);
  delay(500);

}

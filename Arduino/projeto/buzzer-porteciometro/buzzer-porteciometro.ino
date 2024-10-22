int pot = A1;
int buzzer =6;
int time = 70;

void setup() {
  pinMode(pot,  INPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  
    int potValue = analogRead(pot); // Lê valores no potenciômetro
  int frequency = map(potValue, 0, 1023, 0, 1400); //define valores de frequência
  float volt = potValue * (5.00/1023.0); //Valores da tensão no cir
  
  tone(buzzer, frequency, time);
}

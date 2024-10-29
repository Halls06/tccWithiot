//ligando varios led com poteciometro

const int Pot = A0;

int ledCount =7;
int ledPins[] = {
  2, 3, 4, 5, 6, 7}; 

void setup(){
  Serial.begin(9600);
  for (int thisLed = 0; thisLed < ledCount; thisLed++){
    pinMode(ledPins [thisLed], OUTPUT);
  }
}

void loop(){
  int sensorReading = analogRead(Pot);
  int ledLevel = map(sensorReading, 0, 1023, 0, 10);

  for (int thisLed = 0; thisLed < ledCount; thisLed++){
   if (thisLed < ledLevel) {
    digitalWrite(ledPins [thisLed], HIGH);
   }else {
    digitalWrite(ledPins [thisLed], LOW);
   }
   Serial.print("VALOR POT");
   Serial.println(sensorReading);
  }

}
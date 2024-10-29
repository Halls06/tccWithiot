#define pot A0
#define Led 3 //Pino onde o Rele foi conectado 
#define valor_MAX 255

int valorPot = 0;
int valorSaida =  0;

void setup() {
  pinMode(Led, OUTPUT); 
  Serial.begin(9600);
  
  }

void loop() {
  

  valorPot = analogRead(pot); 

  valorSaida = map(valorPot, 0, 1023, 0, valor_MAX);
  
  analogWrite(Led, valorSaida);

  Serial.print("VALORSAIDA");
  Serial.println(valorSaida);
  Serial.println(valorPot);

  delay(100);
}

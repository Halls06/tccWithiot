#define Led 3 //Pino onde o Rele foi conectado 
#define valoLDR 480 // Valor do Sensor de iluminção LDR
#define lamp A0 // Pino de entrada analógica onde esta o LDR


void setup() {
  pinMode(Led, OUTPUT); // pin de saida OUTPUT
  Serial.begin(9600); // Serial parea monitoramento
}

void loop() {
  
  int luz = analogRead(lamp); // Variavel do sensor LDR

  if (luz < valoLDR) { //Se a variavel luz for menor que o valorLDR a luz fica apagada
    digitalWrite(Led, LOW); //se o valor for verdadeiro a luz Acende
  } else { //se a informacao de cima for falsa a luz acende
    digitalWrite(Led, HIGH);  // Rele for falso o rele fica Desligado
}
   Serial.println(luz);
   delay(100);
}

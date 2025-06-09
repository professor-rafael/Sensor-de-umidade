const int pinoSensorUmidade = A0;  // Sensor conectado ao A0
const int pinoLedAlerta = 13;      // LED interno da Arduino Uno (pino 13)
const int limiteUmidadeAlta = 600; // Acende o LED se > 600

void setup() {
  Serial.begin(9600);
  pinMode(pinoSensorUmidade, INPUT);
  pinMode(pinoLedAlerta, OUTPUT);
  digitalWrite(pinoLedAlerta, LOW);  // Inicia com LED apagado
}

void loop() {
  int valorUmidade = analogRead(pinoSensorUmidade);
  Serial.print("Umidade: ");
  Serial.println(valorUmidade);

  if (valorUmidade > limiteUmidadeAlta) {
    digitalWrite(pinoLedAlerta, HIGH);  // Acende o LED se umidade > 600
    Serial.println("Umidade ALTA! LED ligado.");
  } else {
    digitalWrite(pinoLedAlerta, LOW);   // Apaga o LED se umidade <= 600
  }

  delay(1000);  // Espera 1 segundo entre leituras
}
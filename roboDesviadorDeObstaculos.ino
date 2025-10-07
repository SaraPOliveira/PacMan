/**
Robô desviador de obstaculos (código 2)
  @author Anna Julia Arcanjo - Nicolas Matheus - João Felipe - Sara Oliveira
  @version 1.0
*/

#include <DistanceSensor.h>
constexpr int TrigPin = 2;
constexpr int EchoPin = 3;
DistanceSensor<TrigPin, EchoPin> sensor;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  sensor.begin();
}

void loop() {

  int distancia = sensor.tick();
  if (distancia == sensor.NREADY) {
    return;
  }
  Serial.println(distancia);

  if (distancia < 15 && distancia != -2) {
    parar();
    delay(1000);
    girarEsquerda();
    delay(630);   
  } else {
     moverFrente();
  }



// parar();
// moverRe();
// parar();
// girarEsquerda();
// parar();
// girarDireita();
// parar();
}


void moverFrente() {
  // Motor Esquerdo (azul)
  digitalWrite(5, LOW);  // Gira para frente
  analogWrite(6, 142);   // Velocidade

  // Motor Direito (verde)
  digitalWrite(9, LOW);  // Gira para frente
  analogWrite(10, 145);  // Velocidade
}

void parar() {
  digitalWrite(5, 0);  // Motor esquerdo
  digitalWrite(6, 0);
  digitalWrite(9, 0);  // Motor direito
  digitalWrite(10, 0);
}

void moverRe() {
  digitalWrite(5, HIGH);  // Inverte polaridade
  analogWrite(6, 130);    // Velocidade

  digitalWrite(9, HIGH);
  analogWrite(10, 130);
}

void girarEsquerda() {
  // Esquerda (azul) recua
  analogWrite(5, 130);  // Gira para trás
  digitalWrite(6, LOW);

  // Direita (verde) avança
  digitalWrite(9, LOW);  // Gira para frente
  analogWrite(10, 130);
}

void girarDireita() {
  // Esquerda (azul) avança
  digitalWrite(5, LOW);
  analogWrite(6, 130);

  // Direita (verde) recua
  analogWrite(9, 130);
  digitalWrite(10, LOW);
}
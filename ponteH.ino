// Distance sensor
 
#pragma once
 
//#include <Arduino.h>
 
// A very stateful non-blocking implementation for an HC-SR04

template <uint8_t TrigPin, uint8_t EchoPin>

class DistanceSensor

{

public:

  inline DistanceSensor() : nextTick(0), phase(1) {}
 
  inline void begin()

  {

    pinMode(TrigPin, OUTPUT);

    pinMode(EchoPin, INPUT);

  }
 
  constexpr static int NREADY = -1;

  constexpr static int ERR = -2;
 
  /**

  * Ticks the HC-SR04

  * Returns a value when ready, NREADY when not ready

  * or ERR on error

  * Call as fast as possible

  */

  int tick()

  {

    if (micros() < nextTick) return NREADY;
 
    switch(phase)

    {

    case 1:

      phase1();

      return NREADY;

    case 2:

      phase2();

      return NREADY;

    case 3:

      if (!phase3())

        return ERR;

      return NREADY;

    case 4:

      return phase4();

    default:

      // How?

      phase = 1;

      return ERR;

    }

  }

private:

  unsigned long nextTick;

  uint16_t phase;
 
  void phase1()

  {

    digitalWrite(TrigPin, HIGH);

    phase = 2;

    nextTick = micros() + 10;

  }
 
  void phase2()

  {

    digitalWrite(TrigPin, LOW);

    phase = 3;

    nextTick = micros();

  }
 
  bool phase3()

  {

    // Wait for pin to go high

    if (digitalRead(EchoPin) != HIGH)

    {

      // 1 second

      if (micros() - 1000000 > nextTick)

      {

        phase = 1;

        // timed out

        return false;

      }
 
      // true bc didn't error

      return true;

    }
 
    // Pin is high

    // Save time in nextTick
 
    nextTick = micros();

    phase = 4;
 
    return true;

  }
 
  int phase4()

  {

    // Wait for pin to go low

    if (digitalRead(EchoPin)) return NREADY;
 
    // Pin is low

    // Get time
 
    unsigned long time = micros() - nextTick;
 
    phase = 1;
 
    int cm = time/29/2;
 
    if (cm > 1900)

    {

      return ERR;

    }

    return cm;

  }

};
//Biblioteca - Sonar 



/**
  Controle de motores com Ponte H
  e Sensor ultrassônico HC-SR04
  @author Sara Oliveira
*/

/**
  Ligar pinos com PWN (~(Pulso Modular, controla a velocidade)) 
  Varia de 0 a 255 - 
  analogWrite(pino, valor); Escrita analógica
*/

//Uso da Biblioteca Distance-Sensor by Tin dao (Sensor HC-SR04)
//#include <DistanceSensor.h>
//constexpr int TrigPin = 2;
//constexpr int EchoPin = 3;
//DistanceSensor<TrigPin, EchoPin> sensor;
//-----------

void setup() {
  //Motor 1
  pinMode(5, OUTPUT);//Saída
  pinMode(6, OUTPUT);

  //Motor 2
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  //Inicialização do Sensor HC-SR04
  sensor.begin();
  Serial.begin(9600);
  
  //Função movimentação do robô
  //moverFrente();
  //moverRe();
  girarEsquerda();
  delay(2000);
  girarDireita();
  delay(2000);
}

void loop() {
  //Testar motor 1

  //Positivo
  // analogWrite(5, 255); //PWM (0,255) 
  // digitalWrite(6, 0);

  //Negativo
  // digitalWrite(5, 0); //digitalWrite(5, LOW); (equivale ao GND)
  // analogWrite(6, 255);//Acelerador/Velocidade

  //Negativo
  analogWrite(6, 255);//analogWrite(pino, valor); (PWM 0 a 255)//Acelerador/Velocidade
  digitalWrite(5, 0);

  //Negativo
  //Testar motor 2
  analogWrite(10, 255);
  digitalWrite(9, 0);
  
  //Testar Sensor
   int distancia = sensor.tick();
   if (distancia == sensor.NREADY){
    return;
  }
  //Teste do Sensor
  Serial.println(distancia);

  //Lógica Principal (programação do robô)
}

//Funções para movimentação do robô
void moverFrente(){

  analogWrite(10, 255); //motor1
  digitalWrite(9, 0); //motor1

  digitalWrite(9, 0); //motor2
  analogWrite(10, 255); //motor2
  
}

void parar(){

  digitalWrite(5, 0); //motor1
  digitalWrite(6, 0); //motor1
  digitalWrite(9, 0); //motor2
  digitalWrite(10, 0); //motor2

}

void moverRe(){

  digitalWrite(5, 0); //motor1
  digitalWrite(6, 255); //motor1
  digitalWrite(10, 0); //motor2
  digitalWrite(9, 255); //motor2

}

void girarEsquerda(){

  digitalWrite(5, 0); //motor1
  digitalWrite(6, 255); //motor1
  digitalWrite(10, 0); //motor2
  digitalWrite(9, 255); //motor2

}

void girarDireita(){

  digitalWrite(6, 0); //motor1
  digitalWrite(5, 255); //motor1
  digitalWrite(9, 0); //motor2
  digitalWrite(10, 255); //motor2

}
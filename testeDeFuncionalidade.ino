/**
Robô desviaador de obstaculos
  @author Anna Julia Arcanjo - Nicolas Matheus - João Felipe - Sara Oliveira
*/

 //A velocida do que for utilizada no código vária de acordo com o motor
 
void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  digitalWrite(5, LOW);
  analogWrite(6, 120);
  digitalWrite(9, LOW);
  analogWrite(10, 140);
  delay(1000);
  parar();
  moverRe();
  parar();
  girarEsquerda();
  parar();
  girarDireita();
  parar();
}
 
void moverFrente() {
  digitalWrite(5, LOW);  //motor 1
  analogWrite(6, 120);   //motor 1
  digitalWrite(9, LOW);  //motor 2
  analogWrite(10, 140);  //motor 2
  delay(1000);
}
 
void parar() {
  digitalWrite(5, LOW);   //motor 1
  digitalWrite(6, LOW);   //motor 1
  digitalWrite(9, LOW);   //motor 2
  digitalWrite(10, LOW);  //motor 2
  delay(1000);
}
 
void moverRe() {
  digitalWrite(6, LOW);   //motor 1
  analogWrite(5, 120);    //motor 1
  digitalWrite(10, LOW);  //motor 2
  analogWrite(9, 140);    //motor 2
  delay(1000);
 
}
 
void girarEsquerda() {
  digitalWrite(6, LOW);  //motor 1
  analogWrite(5, 120);   //motor 1
  digitalWrite(9, LOW);  //motor 2
  analogWrite(10, 140);  //motor 2
  delay(1000);
}
 
void girarDireita() {
  digitalWrite(5, LOW);   //motor 1
  analogWrite(6, 120);    //motor 1
  digitalWrite(10, LOW);  //motor 2
  analogWrite(9, 140);    //motor 2
  delay(1000);
}
 
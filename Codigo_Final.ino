//Pedro Macedo - UrbanTEC

//Incluindo a biblioteca do Sensor Ultrassonico/Modulo Bluetooth
#include "Ultrasonic.h"
#include <SoftwareSerial.h>

//Variaveis das conexões
const int echoPin=6;
const int trigPin=7;
const int pinoBuzzer=2;
const int vibracall=4;
const int pinoRX=8;
const int pinoTX=9;

//Conectando o sensor com os fios
Ultrasonic ultrasonic(trigPin, echoPin);
SoftwareSerial bluetooth(pinoRX, pinoTX);

//Definindo as distancias e os multiplicadores do sensor
#define multiplicador 7
#define distancia_cm 70

//Variaveis para o calculo 
int distancia;
String result;

//Código dos sensores/sinalizadores/modulo
void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(vibracall, OUTPUT);
} 
 //colocando em loop - Primeira Condição
void loop(){
 hcsr04();
  if (distancia<=distancia_cm){
    int val=distancia*multiplicador;
    tone(pinoBuzzer, 1500);
    digitalWrite(vibracall,HIGH);
    delay(val);
    noTone(pinoBuzzer);
    delay(val);
  }

  //Segunda Condição
  else {
    noTone(pinoBuzzer);
   
  }
}

//Configurando o sensor ultrassonico
void hcsr04(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  distancia= (ultrasonic.Ranging(CM));
  delay(15);
}

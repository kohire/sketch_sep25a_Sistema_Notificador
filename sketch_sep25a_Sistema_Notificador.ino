/*
  INSTITUTO TECNOLÓGICO DE LEÓN
  ALUMNO(A): ALVAREZ CASTRO CYNTHIA AIDEÉ
  PRÁCTICA: 2 - "SISTEMA NOTIFICADOR DE LLEGADA DE INDIVIDUOS"
  INSTRUCCIONES:
    - LA PUERTA DEBE LLEVAR UNA ALARMA AL MOMENTO DE ABRIRSE.
    REQUISITOS:
    - USAR BAJO CONSUMO DE ENERGIA CUANDO LA PUERTA ESTÉ CERRADA.
    - CUANDO SE CIERRE LA PUERTA, NO DEBE SONAR LA ALARMA Y EL CONSUMO
      DE ENERGÍA DEEBE SER EL MISMO.
*/

#include <LowPower.h> //La librería low-power nos ayudará a reducir al mínimo el consumo del circuito, así que la importaremos.

//Definimos que pines vamos a utilizar para los leds, el buzzer y el reedSw.
#define redOpen 11
#define greenClose 13
#define buzzer 8
#define reedSw 2 //Controlador del sleep. 

//Defino enteros para el sonido del buzzer.
const int tonos[] = {261, 277, 294, 311, 330, 349};
const int countTonos = 10;

void setup() {

  pinMode(redOpen, OUTPUT); // Los led estarán en modo salida.
  pinMode(greenClose, OUTPUT);
  pinMode(reedSw, INPUT_PULLUP); //Será input ya que necesitamos controlar lo que entre.
  pinMode(buzzer, OUTPUT);
  
}

void loop() {
  // De forma cíclica, el arduino deberá estar dormido, y la razón es que cuando esté en modo LOW
  // necesita tener un consumo de energía mayor ya que también utilizamos una alarma. Como quién dice, se activa.
  // Si fuese el caso contrario, sería lo mismo invertido.

  // El attachInterrupt funciona de la siguiente manera:
  // (_pin_,_que quieres que haga_, _parámetro_)
  // Los parámetros son distintos en el arduino, y en el caso de UNO solamente se utilizan: HIGH, LOW, RISING, FALLING y CHANGE.
  // Usaremos una forma de parar la interrupción con el detach. Este no devuelve nada.
  // Usando Low-Power, no debe llevar delay, Serial. Solo lo escencial.

  attachInterrupt(0, openDoor, LOW); //Digital pin 2. LOW - HIGH
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  detachInterrupt(0);
  delay(100);
  // En esta parte se pueden hacer comentarios u otras cosas.
  closeDoor();
}

void openDoor()
{
  digitalWrite(redOpen, HIGH);
  digitalWrite(greenClose, LOW);
  digitalWrite(buzzer, HIGH);
  //Recorremos el arreglo para que el buzzer haga diferentes sonidos.
  
}


void closeDoor()
{
  digitalWrite(redOpen, LOW);
  digitalWrite(greenClose, HIGH);
  digitalWrite(buzzer, LOW);
}



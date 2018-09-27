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
const int countTonos = 6;


void setup() {

  pinMode(redOpen, OUTPUT); // Los led estarán en modo salida.
  pinMode(greenClose, OUTPUT);
  pinMode(reedSw, INPUT_PULLUP); //Será input ya que necesitamos controlar lo que entre.
  //Serial.begin(9600);
}

void loop() {
  // Aquí se le notifica al arduino que si está en modo low, deberá encender.
  // Siempre estará dormido, y esto dependerá de la interrupción.
  attachInterrupt(0, doNothing, LOW); //Digital pin 2. LOW - HIGH
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  detachInterrupt(0); // Interrumpimos la interrupción.
  //Hago un while solamente para saber que siempre estará la puerta abierta solo si está en modo low.
  while (digitalRead(reedSw) == LOW)
  {
    openDoor();
  }
  closeDoor(); //Si no está abierta, entonces nunca sonará la alarma.
}


void doNothing() {
  //No recibe ningún parámetro, ya para una interrupción que siempre va a estar verificando
  //si hay o no algo que lo interrumpa. Lo hice de esta manera, ya que utilizo delay, y una interrupción
  //no hace uso de ellos.
}

void openDoor() //Se hace este método para cuando se abra la puerta, suene junto al buzzer.
{
  digitalWrite(redOpen, HIGH);
  digitalWrite(greenClose, LOW);
  //Recorremos el arreglo para que el buzzer haga diferentes sonidos.
  for (int iTonos = 0; iTonos < countTonos; iTonos++)
  {
    tone(buzzer, tonos[iTonos]); //Recorro el arreglo de tonos.
    delay(100); //Entre cada tono debe esperar 100.
  }

}

void closeDoor() // Apagamos todo e indicamos que la puerta está cerrada.
{
  digitalWrite(redOpen, LOW);
  digitalWrite(greenClose, HIGH);
  noTone(buzzer);
}




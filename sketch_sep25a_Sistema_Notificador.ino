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


//Definimos que pines vamos a utilizar para los leds, el buzzer y el reedSw.
#define redOpen 11
#define greenClose 13
#define buzzer 8 
#define reedSw 4


void setup() {
  // Cuando este enciende, le declaramos:
  pinMode(redOpen, OUTPUT); // Los led estarán en modo salida.
  pinMode(greenClose, OUTPUT);
  pinMode(reedSw, INPUT); //Será input ya que necesitamos controlar lo que entre.
  Serial.begin(9600); //La entrada serán de 9600 baudios.
}

void loop() {
  //Pasos a seguir:
 if(digitalRead(reedSw) == HIGH) //Si está en HIGH, los led estarán en su posición original.
 {
  digitalWrite(redOpen, LOW);
  digitalWrite(greenClose, HIGH);
  Serial.println("Tu puerta está cerrada");
 } else //Caso contrario...
 {
  digitalWrite(redOpen, HIGH);
  digitalWrite(greenClose, LOW);
  Serial.println("Tu puerta está abierta");
 }
 delay(1); //Por prueba, el delay estará en 1.
}

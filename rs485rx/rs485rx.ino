#include <Servo.h> 
 
Servo myservo;  // creamos el objeto servo 
 
void setup() 
{ 
  Serial.begin(9600);  
  myservo.attach(9);  // asignamos el pin 9 para el servo.
} 
 
void loop() 
{ 
  
  if (Serial.available()) {
    int angulo = Serial.read(); //Leemos el dato recibido 
    if(angulo<=180) //verificamos que sea un valor en el rango del servo
    {
      Serial.print(angulo); //valor del sensor
      myservo.write(angulo); //movemos el servomotor al ángulo correspondiente.
    }
  }
} 

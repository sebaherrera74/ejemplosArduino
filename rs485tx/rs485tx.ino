void setup() 
{ 
  Serial.begin(9600);
} 
 
void loop() 
{ 
  int lectura = analogRead(0);//leemos el valor del potenciómetro (de 0 a 1023) 
  byte angulo= map(lectura, 0, 1023, 0, 180);     // escalamos la lectura a un valor de ángulo (entre 0 y 180) 
  Serial.write(angulo); //enviamos el ángulo correspondiente
  delay(50);                           
} 

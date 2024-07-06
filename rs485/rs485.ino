
 
 
void setup() 
{ 
  Serial.begin(9600);  
 
} 
 
void loop() 
{ 
  
  if (Serial.available()) {
    int angulo = Serial.read();
    Serial.print(angulo);
    }
} 

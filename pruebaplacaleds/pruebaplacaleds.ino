
// the setup function runs once when you press reset or power the board

# define  A 2    //defino pines de salida nro 2 
# define  B 3    //defino pines de salida nro 3 
# define  C 4    //defino pines de salida nro 4 
# define  D 5    //defino pines de salida nro 5 
# define  UN_SEG    1000  //defino tiempo 1 segundo 

void apagaleds();


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(B, 1);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(C, 0);      // wait for a second
  digitalWrite(D, 1);
  delay(500);
  apagaleds();
  /*digitalWrite(B, 0);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  digitalWrite(C, 1);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(C, 0);    // turn the LED off by making the voltage LOW
  delay(1000);  
  digitalWrite(D, 1);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
 digitalWrite(D, 0);   // turn the LED on (HIGH is the voltage level)
  delay(1000);*/

}

void apagaleds(){
  digitalWrite(B, 1);    // turn the LED off by making the voltage LOW
  digitalWrite(C, 1);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D, 1);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
}

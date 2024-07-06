

# define  A 2    //defino pines de salida nro 2 correpsondiente a la entrada A del 45111
# define  B 3    //defino pines de salida nro 3 correpsondiente a la entrada B del 45111
# define  C 4    //defino pines de salida nro 4 correpsondiente a la entrada C del 45111
# define  D 5    //defino pines de salida nro 5 correpsondiente a la entrada D del 45111
# define  UN_SEG    1000  //defino tiempo 1 segundo 

//# define display1 5
//# define display2 6
//# define display3 7
//# define display4 8


void setup() {
  // put your setup code here, to run once:

    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
   /* pinMode(display1 , OUTPUT);
    pinMode(display2 , OUTPUT);
    pinMode(display3 , OUTPUT);
    pinMode(display4 , OUTPUT);*/



}

void loop() {
  // put your main code here, to run repeatedly:
  
 
  escribe_cero();
  delay(UN_SEG );
  
  escribe_uno();
  delay(UN_SEG );
  
  escribe_dos();
  delay(UN_SEG );
  
  escribe_tres();
  delay(UN_SEG );

  escribe_cuatro();
  delay(UN_SEG );

  escribe_cinco();
  delay(UN_SEG );

  escribe_seis();
  delay(UN_SEG );

  escribe_siete();
  delay(UN_SEG );
  
  escribe_ocho();
  delay(UN_SEG );
  
  escribe_nueve();
  delay(UN_SEG );

     
}

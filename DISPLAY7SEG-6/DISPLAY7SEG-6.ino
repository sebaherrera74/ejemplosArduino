
# define  A 2    //defino pines de salida nro 2 correpsondiente a la entrada A del 45111
# define  B 3    //defino pines de salida nro 3 correpsondiente a la entrada B del 45111
# define  C 4    //defino pines de salida nro 4 correpsondiente a la entrada C del 45111
# define  D 5    //defino pines de salida nro 5 correpsondiente a la entrada D del 45111
# define  UN_SEG    1000  //defino tiempo 1 segundo 

# define display1 6
# define display2 7
# define display3 8
//# define display4 8
void disp1(void);
void disp2(void);
void disp3(void);
void disp4(void);
void disp5(void);
void disp6(void);

void number0(void);
void number1(void);
void number2(void);
void number3(void);
void number4(void);
void number5(void);
void number6(void);
void number7(void);
void number8(void);
void number9(void);
void blank(void);
void setup() {
  // put your setup code here, to run once:

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);

  pinMode(display1, OUTPUT);
  pinMode(display2, OUTPUT);
  pinMode(display3, OUTPUT);

  /* pinMode(display1 , OUTPUT);
    pinMode(display2 , OUTPUT);
    pinMode(display3 , OUTPUT);
    pinMode(display4 , OUTPUT);*/

  disp2();

}

void loop() {
  // put your main code here, to run repeatedly:
    delay(2);
    disp1();
    number1();
    delay(2);
    
    disp2();
    number2();
    delay(2);
    
    disp3();
    number3();
    delay(2);
    
    disp4();
    number4();
    delay(5);

    disp5();
    number5();
    delay(5);
   
    disp6();
    number6();
    delay(2);
    
    delay(2);
    

}

void disp1(void) {
  digitalWrite(display1, LOW);
  digitalWrite(display2, HIGH);
  digitalWrite(display3, HIGH);

}

void disp2(void) {
  digitalWrite(display1, LOW);
  digitalWrite(display2, HIGH);
  digitalWrite(display3, LOW);
}

void disp3(void) {
  digitalWrite(display1, HIGH);
  digitalWrite(display2, LOW);
  digitalWrite(display3, HIGH);
}

void disp4(void) {
  digitalWrite(display1, HIGH);
  digitalWrite(display2, LOW);
  digitalWrite(display3, LOW);
}

void disp5(void) {
  digitalWrite(display1, LOW);
  digitalWrite(display2, LOW);
  digitalWrite(display3, HIGH);
}

void disp6(void) {
  digitalWrite(display1, LOW);
  digitalWrite(display2, LOW);
  digitalWrite(display3, LOW);
}

void number0(void) {
  digitalWrite(A, LOW);
  digitalWrite(B,  LOW);
  digitalWrite(C, LOW);
  digitalWrite(D,  LOW);
}
void number1(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B,  LOW);
  digitalWrite(C, LOW);
  digitalWrite(D,  LOW);
}

void number2(void) {
  digitalWrite(A, LOW);
  digitalWrite(B,  HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D,  LOW);

}
void number3(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B,  HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D,  LOW);
}

void number4(void) {
  digitalWrite(A, LOW);
  digitalWrite(B,  LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D,  LOW);
}
void number5(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B,  LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D,  LOW);
}

void number6(void) {
  digitalWrite(A, LOW);
  digitalWrite(B,  HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D,  LOW);
}
void number7(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B,  HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D,  LOW);

}
void number8(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B,  HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D,  LOW);

}
void number9(void) {
  digitalWrite(A, HIGH);
  digitalWrite(B,  LOW);
  digitalWrite(C, LOW);
  digitalWrite(D,  HIGH);
}


void blank(void) {
  digitalWrite(A, LOW);
  digitalWrite(B,  HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D,  HIGH);
}

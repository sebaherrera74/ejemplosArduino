#include <Key.h>
#include <Keypad.h>

# define  sentidohorario     10   //defino pines de salida nro 10 correpsondiente a rele de activacion de sentido horario 
# define  sentidoAntihorario 11   //defino pines de salida nro 11 correpsondiente a rele de activacion de sentido Antihorario 
# define  velocidadlenta     12   //defino pines de salida nro 12 correpsondiente a rele de activacion de velocidad lenta 
# define  velocidadrapida     13   //defino pines de salida nro 12 correpsondiente a rele de activacion de velocidad rapida 
# define  UN_SEG    1000  //defino tiempo 1 segundo 
# define  POWER               4   //tecla entre 8 y 9 para encendido


const byte rowsCount = 2;
const byte columsCount = 3;

char keys[rowsCount][columsCount] = {
  { '1', '2', '3' },
  { '4', '5', '6' },

};

const byte rowPins[rowsCount] = { 8, 9 };
const byte columnPins[columsCount] = { 5, 6, 7 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);


typedef enum {
  Inicial,
  Encendido,
  Apagado
} states_t;


// funciones de la maquina de estados


void fsmError( void );
void fsmInit( void );
void End(void);

states_t estados;


const int timeThreshold = 400;
const int intPin = 3;
volatile int ISRCounter = 0;
uint8_t counter = 0;
long startTime = 0;
char key;      //Variable caracter  que me devuelve un la tecla de los motores


void setup() {
  Serial.begin(9600);
  fsmInit();
  attachInterrupt(digitalPinToInterrupt(intPin), debounceCount, FALLING);
}

void loop() {
  fsmUpdate(estados);
  delay(100);
};

void fsmError( void ) {
  End();
}

//Funcion de inciio me incia los puertos y la maquina de estados
void fsmInit( void ) {

  estados = Inicial;
  pinMode(sentidohorario, OUTPUT);
  pinMode(sentidoAntihorario, OUTPUT);
  pinMode(velocidadlenta, OUTPUT);
  pinMode(velocidadrapida, OUTPUT);
  
  pinMode(POWER,OUTPUT );
  digitalWrite(sentidohorario, HIGH);
  digitalWrite(sentidoAntihorario, HIGH);
  digitalWrite(velocidadlenta, HIGH);
  digitalWrite(velocidadrapida, HIGH);
  digitalWrite(POWER, HIGH);
  
}

void fsmUpdate(states_t states) {
  switch ( states ){
    case Inicial:
      Serial.println("Esta Inicio");
      digitalWrite(POWER, HIGH);
      break;
    case Encendido:
      ///Serial.println("Esta encendido");
      //Aqui iria todos los encendidos de los motores
      digitalWrite(POWER, LOW);
      key = keypad.getKey();
      if (key == '1') {
        Serial.println(key);
        digitalWrite(velocidadrapida, HIGH);
        delay(1000);
        digitalWrite(velocidadlenta, LOW);
      }
    
      if (key == '3') {
        Serial.println(key);
        digitalWrite(velocidadlenta, HIGH);
        delay(1000);
        digitalWrite(velocidadrapida, LOW);
      }
      if (key == '4') {
        
        Serial.println(key);
        digitalWrite(sentidohorario, HIGH);
        delay(1000);
        digitalWrite(sentidoAntihorario, LOW);
      }
      if (key == '6') {
        Serial.println(key);
        digitalWrite(sentidoAntihorario, HIGH);  //Apago primero el motor en un giro y espero 1 seg
        delay(1000);
        digitalWrite(sentidohorario, LOW);
     }
      break;
    case Apagado:
      //Serial.println("Esta Apagado");
      digitalWrite(POWER, HIGH);
      End(); //Aqui Apago los motores
      //Apagria Todos o solo los que etsna encendidos en alguna secuenci?
     break;
    default:
      fsmError();
      break;
  }
}


void Start(void) {
};
/*
   Funcion que me apaga os 4 reles
*/
void End(void) {
  digitalWrite(sentidohorario, HIGH);
  digitalWrite(sentidoAntihorario, HIGH);
  digitalWrite(velocidadlenta, HIGH);
  digitalWrite(velocidadrapida, HIGH);
};

//Funcion de la interrupcion para atender la tecla On-Off
void debounceCount()
{
  if (millis() - startTime > timeThreshold)
  {
    ISRCounter++;
    startTime = millis();
  }

   if (counter != ISRCounter)
  {
    counter = ISRCounter;
    counter=counter %3;
    
    Serial.println(counter);

    if(counter==0){
      estados=Inicial;
      
    }
    if(counter==1){
      estados=Encendido;
      
    }
    if(counter==2){
      estados=Apagado;
      
    }
  }
}

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
bool botonOnOff(uint8_t onoff); //funcion que me permite conocoer el estado de la tecla on-off

states_t estados;



static int value = 0; //Variable que me da el estado del power on-off
char key;      //Variable caracter  que me devuelve un la tecla de los motores
bool bateaEncendidaHorario = false; //No se si se llama batea o amasadora

void setup() {
  Serial.begin(9600);
  fsmInit();
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
  pinMode(POWER, INPUT);
  digitalWrite(sentidohorario, HIGH);
  digitalWrite(sentidoAntihorario, HIGH);
  digitalWrite(velocidadlenta, HIGH);
  digitalWrite(velocidadrapida, HIGH);
}

void fsmUpdate(states_t states) {

  //static bool flagFalling = false;
  //static bool flagRising = false;
  //static uint8_t contFalling = 0;
  //static uint8_t contRising = 0;

  value = botonOnOff(POWER);


  switch ( states ) {
    case Inicial:
      Serial.println("Esta Inicio");
      if (value != 1) {
        estados = Encendido;
      }
      break;
    case Encendido:
      Serial.println("Esta encendido");
      //Aqui iria todos los encendidos de los motores

      if (value != 1) {
        estados = Apagado;
      }

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
        bateaEncendidaHorario = false;
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
        bateaEncendidaHorario = true;
        Serial.println(bateaEncendidaHorario);
      }
      break;
    case Apagado:
      Serial.println("Esta Apagado");
      End(); //Aqui Apago los motores
      //Apagria Todos o solo los que etsna encendidos en alguna secuenci?
      if (value != 1) {
        estados = Encendido;
      }
      break;
    default:
      fsmError();
      break;
  }

}

bool botonOnOff(uint8_t onoff) {
  uint8_t aux;
  aux = digitalRead(onoff);
  delay(250);
  if (aux) {
    return true;
  }
  else {
    return false;
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

//Funcion que me devuelva el estado del rele que esta activo




/*


     }

    if (key=='1') {
    Serial.println(key);
    digitalWrite(velocidadlenta, LOW);
   }

  if (key=='2') {
    Serial.println(key);

   }
  if (key=='3') {
    Serial.println(key);
    digitalWrite(velocidarapida, LOW);
  }
  if (key=='6') {
    Serial.println(key);
    digitalWrite(sentidohorario, LOW);

   }
  if (key=='4') {
    Serial.println(key);
  digitalWrite(sentidoAntihorario, LOW);
  }
  if (value == LOW) {
    Serial.println("Encendido");
    digitalWrite(velocidadlenta, LOW);
  }

  char key = keypad.getKey();




  if (key=='1') {
    Serial.println(key);
    digitalWrite(velocidadlenta, LOW);


  }

  if (key=='2') {
    Serial.println(key);
    End();

  }
  if (key=='3') {
    Serial.println(key);
    digitalWrite(velocidarapida, LOW);


  }

  if (key=='6') {
    Serial.println(key);
   digitalWrite(sentidohorario, LOW);


  }
  if (key=='4') {
    Serial.println(key);
  digitalWrite(sentidoAntihorario, LOW);


  }*/

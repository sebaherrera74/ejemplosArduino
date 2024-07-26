#define __DEBUG__
#define rojo 9
#define azul 10
#define verde 11

#define subirvalorpwm 4
#define bajarvalorpwm 5

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definir constantes
#define ANCHO_PANTALLA 128 // ancho pantalla OLED
#define ALTO_PANTALLA 64 // alto pantalla OLED

// Objeto de la clase Adafruit_SSD1306
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);

typedef enum {
  Inicial,
  Rojo,
  Azul,
  Verde
} states_t;

//void fsmError( void );
void fsmInit( void );
//void End(void);
void fsmUpdate(states_t estados);

states_t estados;


int pwmRojo=0;
int pwmVerde=0;
int pwmAzul=0;

int aux=0;
int aux1=0;
const int cambiarColor = 3;
const int timeThreshold = 400;
uint8_t counter = 0;
long startTime = 0;
volatile int ISRCounter = 0;

void setup() {
  #ifdef __DEBUG__
  Serial.begin(9600);
  delay(100);
  Serial.println("Iniciando pantalla OLED");
   #endif

  // Iniciar pantalla OLED en la dirección 0x3C
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    #ifdef __DEBUG__
    Serial.println("No se encuentra la pantalla OLED");
    #endif
  }
  // Limpir buffer
    display.clearDisplay();

    // Dibujar línea horizontal
    display.drawLine(0, 18, display.width(), 18, SSD1306_WHITE);
    // Dibujar línea vertical
    display.drawLine(63, 0, 63, display.height(), SSD1306_WHITE);
    display.display();

 
    delay(2000);
    display.clearDisplay();
  fsmInit();
  attachInterrupt(digitalPinToInterrupt(cambiarColor), debounceCount, FALLING);

}
  


void loop() {
  
   fsmUpdate(estados);

  
  }

void fsmInit( void ){
  estados=Inicial;
  pinMode( subirvalorpwm, INPUT_PULLUP);
  pinMode( bajarvalorpwm, INPUT_PULLUP);  

}

void fsmUpdate(states_t estados){
  display.clearDisplay();
  switch ( estados ){
    
  case Inicial:
      Serial.println("Esta Inicio");
      
      break;
      
    case Rojo:
    Serial.println("Rojo");
    aux=digitalRead(subirvalorpwm);
    aux1=digitalRead(bajarvalorpwm);
    delay(200);
    if(aux==HIGH){
      pwmRojo=pwmRojo+10;
    }
    if(aux1==HIGH){
      pwmRojo=pwmRojo-10;
      }
 Serial.println(pwmRojo);
  
  analogWrite(rojo, pwmRojo);
  
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("ROJO");
  display.setCursor(70, 0);
  display.println(pwmRojo);
  display.setCursor(0, 20);
  display.println("aZUL");
   

  display.setCursor(0, 40);
  display.println("VERDE");
 
  // Enviar a pantalla
  display.display();

      
      
      break;
    case Azul:
    Serial.println("Azul");
    aux=digitalRead(subirvalorpwm);
    aux1=digitalRead(bajarvalorpwm);
    delay(200);
    if(aux==HIGH){
      pwmAzul=pwmAzul+10;
    }
    if(aux1==HIGH){
      pwmAzul=pwmAzul-10;
      }
 
  
  analogWrite(azul, pwmAzul);
  
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("ROJO");
  
  
  display.setCursor(0, 20);
  display.println("aZUL");
  display.setCursor(70, 20);
  display.println(pwmAzul);
   

  display.setCursor(0, 40);
  display.println("VERDE");
 
  // Enviar a pantalla
  display.display();

      
      
     break;

     case Verde:
    Serial.println("Verde");
      
     break;
    default:
      //fsmError();
      break;
  }
}

//Funcion de la interrupcion para atender la tecla On-Off
void debounceCount(){
if (millis() - startTime > timeThreshold){
  ISRCounter++;
  startTime = millis();
}

 if (counter != ISRCounter){
  counter = ISRCounter;
  counter=counter %4;
  
  Serial.println(counter);

  if(counter==0){
    estados=Inicial;
    
  }
  if(counter==1){
    estados=Rojo;
    
  }
  if(counter==2){
    estados=Azul;
    
  }
if(counter==3){
    estados=Verde;
    
  }
}
}

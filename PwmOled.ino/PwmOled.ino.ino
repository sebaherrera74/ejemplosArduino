#define __DEBUG__
#define rojo 9
#define subirvalorpwm 4
#define bajarvalorpwm 5
#define cambiarcolor  6

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

void fsmError( void );
void fsmInit( void );
void End(void);

states_t estados;


int pwmRojo=0;
int aux=0;
int aux1=0;



void setup() {
  fsmInit();
   
  }
  


void loop() {

  
  display.clearDisplay();
  delay(200);
  aux=digitalRead(subirvalorpwm);
  aux1=digitalRead(bajarvalorpwm);
  delay(200);
  Serial.println(aux);
  
  if(aux==HIGH){
    pwmRojo=pwmRojo+10;
    }
    else {
    
    
  }
    
  if(aux1==HIGH){
   pwmRojo=pwmRojo-10;
  }
else {
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
  
  }

void fsmInit( void ){
    pinMode( subirvalorpwm, INPUT_PULLUP);
pinMode( bajarvalorpwm, INPUT_PULLUP);  
pinMode( cambiarcolor, INPUT_PULLUP);
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
// Limpir buffer
  display.clearDisplay();

  // Dibujar línea horizontal
  display.drawLine(0, 18, display.width(), 18, SSD1306_WHITE);
  // Dibujar línea vertical
  display.drawLine(63, 0, 63, display.height(), SSD1306_WHITE);
  display.display();

 display.clearDisplay();
  delay(2000);
  
   
  }
}

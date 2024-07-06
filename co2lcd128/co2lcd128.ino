// Basic demo for readings from Adafruit SCD30
#include <Adafruit_SCD30.h>

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

Adafruit_SCD30  scd30;

U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* CS=*/ 10, /* reset=*/ 8);

int temperatura=0;
int dioxido=0;
void setup(void) {
  
  

  // Try to initialize!
  if (!scd30.begin()) {
  
    while (1) { delay(10); }
  }

 
  if (!scd30.setMeasurementInterval(2)){
    
    while(1) {delay(10);}
  }

 
   //Inicializacion de display
  // put your setup code here, to run once:
  u8g2.begin();
  u8g2.clearBuffer();

u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0,15,"Hello World!");
  } while ( u8g2.nextPage() );
  delay(1000);
  u8g2.clearDisplay();

}

void loop() {
  char C_str[6];
  u8g2.clearDisplay(); 
  u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0,20," CO2:");
  if (scd30.dataReady()){
      if (!scd30.read()){ return; }

    temperatura=scd30.temperature;
    dioxido=scd30.CO2;
    strcpy(C_str, u8x8_u16toa(dioxido, 4));
 }
do {
    //u8g2.setFont(u8g2_font_ncenB14_tr);
    //u8g2.drawStr(0,20," CO2:");
    u8g2.drawStr(55,20,C_str);
   
  } while ( u8g2.nextPage() );
  delay(2500);

    
 

  
}

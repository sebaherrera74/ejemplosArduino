#include <Wire.h>
#include <Adafruit_ADS1015.h>

 #include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

// Crear objeto de la clase
Adafruit_ADS1115 ads;
float Voltage=0;
 
U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* CS=*/ 10, /* reset=*/ 8);

void setup(void) 
{
  Serial.begin(9600);
  delay(200);
 // Cambiar factor de escala
  ads.setGain(GAIN_TWOTHIRDS);
  // Iniciar el ADS1115
  ads.begin();
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
 
void loop(void) 
{
  char lectura[6];
  
  // Obtener datos del A0 del ADS1115
  short adc0 = ads.readADC_SingleEnded(0);
  Voltage = (adc0 * 0.1875)/1000;
  Serial.print("A0: "); 
  Serial.println(Voltage,4);
  



do {
  strcpy(lectura, u8x8_u16toa(Voltage, 4)); 
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(10,15,lectura);
   
  } while ( u8g2.nextPage() );
  delay(1000);
  
u8g2.clearDisplay();
 
}

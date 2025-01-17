

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

// 'TheOffice', 128x64px
static const unsigned char myBitmap [] PROGMEM = {

   0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0x3f, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x06, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc7,
   0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0x9f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb8, 0x03, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xb0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0xb0,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x3f, 0x00,
   0x00, 0x00, 0x00, 0xb0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x08, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xb0, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x08, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xb0,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x80, 0x7f, 0x00,
   0x00, 0x00, 0x00, 0xb0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x08, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xb0, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xb0,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xc0, 0x7f, 0x00,
   0x00, 0x00, 0x00, 0xb0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x08, 0xf0, 0xff, 0x03, 0x00, 0x00, 0x00, 0xb0, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x08, 0xf8, 0xff, 0x07, 0x00, 0x00, 0x7c, 0xb0,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xf8, 0xff, 0x07,
   0x00, 0x00, 0xfe, 0xb0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x08, 0xf8, 0xff, 0x07, 0x00, 0x00, 0xfe, 0xb0, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x08, 0xf8, 0xff, 0x07, 0x00, 0x00, 0xfe, 0xb0,
   0x81, 0xff, 0x1d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xf8, 0xff, 0x0f,
   0x00, 0x00, 0xfe, 0xb0, 0x81, 0xff, 0x1d, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x08, 0xf8, 0xff, 0x0f, 0x00, 0x00, 0xfe, 0xb0, 0x81, 0xff, 0x1d, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x08, 0xfc, 0xff, 0x0f, 0x00, 0x00, 0xfe, 0xb0,
   0x01, 0x38, 0xdc, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x08, 0xfc, 0xff, 0x0f,
   0x00, 0x00, 0x7c, 0xb0, 0x01, 0x38, 0xfc, 0xf3, 0x03, 0x00, 0x00, 0x00,
   0x08, 0xfc, 0xff, 0x0f, 0x00, 0x00, 0x38, 0xb0, 0x01, 0x38, 0xfc, 0xfb,
   0x07, 0x00, 0x00, 0x00, 0x08, 0xfc, 0xff, 0x0f, 0x00, 0x00, 0xfc, 0xb0,
   0x01, 0x38, 0x9c, 0x3b, 0x07, 0x00, 0x00, 0x00, 0x08, 0xfc, 0xff, 0x07,
   0x00, 0x00, 0xfe, 0xb0, 0x01, 0x38, 0x9c, 0xfb, 0x07, 0x00, 0x00, 0x00,
   0x08, 0xfc, 0xff, 0x07, 0x00, 0x00, 0xfe, 0xb7, 0x01, 0x38, 0x9c, 0xfb,
   0x07, 0x00, 0x00, 0x00, 0x08, 0xfc, 0xff, 0x07, 0x00, 0x00, 0xfe, 0xb7,
   0x01, 0x38, 0x9c, 0x3b, 0x07, 0x00, 0x00, 0x00, 0x08, 0xfc, 0xff, 0x07,
   0x00, 0x00, 0xfe, 0xb7, 0x01, 0x38, 0x9c, 0xfb, 0x07, 0x00, 0x00, 0x00,
   0x08, 0xfe, 0xff, 0x07, 0x00, 0x00, 0xff, 0xb7, 0x01, 0x38, 0x9c, 0xf3,
   0x03, 0x00, 0x00, 0x00, 0x08, 0xfe, 0xff, 0x07, 0x00, 0x80, 0xff, 0xb7,
   0x01, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0xc8, 0xff, 0xff, 0x00,
   0x00, 0xc0, 0xff, 0xb6, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xc8, 0xff, 0xff, 0x00, 0x00, 0xe0, 0xff, 0xb6, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xc8, 0xff, 0xff, 0x00, 0x00, 0xfe, 0xff, 0xb6,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc8, 0xff, 0xff, 0x00,
   0xc0, 0xff, 0xff, 0xb6, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xc8, 0xff, 0xff, 0x00, 0xe0, 0xff, 0xff, 0xb6, 0x01, 0xf8, 0x07, 0xbe,
   0xff, 0x00, 0x00, 0x00, 0xc8, 0xff, 0xff, 0x00, 0xe0, 0x7f, 0xff, 0xb7,
   0x01, 0xfc, 0x1f, 0xbf, 0xff, 0x00, 0x00, 0x00, 0xc8, 0xff, 0xff, 0xfc,
   0xff, 0x0f, 0xff, 0xb7, 0x01, 0xfe, 0x1f, 0xbf, 0xff, 0x00, 0x00, 0x00,
   0xc8, 0xff, 0xff, 0xfc, 0xff, 0xef, 0xff, 0xb7, 0x01, 0x1f, 0x3e, 0x8f,
   0x03, 0x00, 0x00, 0x00, 0xc8, 0xff, 0xff, 0xc0, 0x01, 0xfe, 0xff, 0xb7,
   0x01, 0x0f, 0xbc, 0xff, 0xef, 0xf0, 0x87, 0x1f, 0xc8, 0xff, 0xff, 0xc0,
   0x01, 0xff, 0xff, 0xb7, 0x01, 0x0f, 0xbc, 0xff, 0xef, 0xf8, 0xcf, 0x3f,
   0xc8, 0xff, 0xff, 0xc0, 0x01, 0xff, 0xff, 0xb7, 0x01, 0x0f, 0xb8, 0xff,
   0xef, 0xfc, 0xef, 0x3f, 0xc8, 0xff, 0xff, 0xc0, 0x01, 0xff, 0x7f, 0xb7,
   0x01, 0x0f, 0x38, 0x8f, 0xe3, 0x3c, 0xef, 0x79, 0x08, 0xc0, 0x7f, 0xc0,
   0x81, 0xff, 0x1f, 0xb7, 0x01, 0x0f, 0x3c, 0x8f, 0xe3, 0x3c, 0xe0, 0x7f,
   0x08, 0xc0, 0x7f, 0xc0, 0x81, 0xef, 0xff, 0xb7, 0x01, 0x0f, 0x3c, 0x8f,
   0xe3, 0x1c, 0xe0, 0x7f, 0x08, 0xc0, 0x7f, 0xc0, 0x81, 0xef, 0xff, 0xb7,
   0x01, 0x1f, 0x3c, 0x8f, 0xe3, 0x3c, 0xe6, 0x7f, 0x08, 0xc0, 0x7f, 0xc0,
   0x81, 0xe7, 0xff, 0xb7, 0x01, 0x3e, 0x3e, 0x8f, 0xe3, 0x3c, 0xef, 0x79,
   0x08, 0x80, 0x7b, 0xc0, 0xc1, 0x67, 0x00, 0xb7, 0x01, 0xfe, 0x1f, 0x8f,
   0xe3, 0xfc, 0xef, 0x7f, 0x08, 0x80, 0x33, 0xc0, 0xc1, 0x67, 0x00, 0xb7,
   0x01, 0xfc, 0x0f, 0x8f, 0xe3, 0xf8, 0xcf, 0x3f, 0x08, 0x00, 0x00, 0xc0,
   0xc1, 0x67, 0x00, 0xb7, 0x01, 0xf8, 0x07, 0x8f, 0xe3, 0xf0, 0xc7, 0x1f,
   0x08, 0x00, 0x00, 0xc0, 0xe1, 0x63, 0x00, 0xb7, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0xc0, 0xe1, 0x63, 0x00, 0xb7,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0xc0,
   0xe1, 0x61, 0x00, 0xb7, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x08, 0x00, 0x00, 0xc0, 0xe1, 0x61, 0x00, 0xb7, 0x01, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0xc0, 0xe1, 0x61, 0x00, 0xb7,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0xc0,
   0xe1, 0x60, 0x00, 0xb2, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0, 0x03, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0,
   0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xbc, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0x06, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0,
   0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0x7f
};


static const unsigned char imagen1_bits[] PROGMEM= {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe5, 0x8f, 0x34, 0x00, 0x00,
   0x00, 0x00, 0x50, 0x00, 0x78, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x6c, 0x0a,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x4b, 0x0c, 0x00, 0x00, 0xdb, 0x08,
   0x20, 0x00, 0x00, 0xb1, 0x07, 0x00, 0x5c, 0x01, 0x90, 0x22, 0x80, 0x15,
   0x2c, 0x80, 0x41, 0x00, 0x00, 0x78, 0xc0, 0x03, 0x16, 0x80, 0xff, 0x13,
   0x00, 0x60, 0x00, 0x02, 0x14, 0x00, 0x00, 0x00, 0x00, 0x60, 0x40, 0x03,
   0x16, 0x80, 0xab, 0x01, 0x80, 0x50, 0x40, 0x02, 0x14, 0x00, 0x7a, 0x0c,
   0xff, 0xec, 0xe0, 0x06, 0x33, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x20, 0x05,
   0x33, 0x00, 0x00, 0x00, 0x00, 0xae, 0x69, 0xab, 0x2e, 0x00, 0x00, 0x00,
   0x00, 0x02, 0x16, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x1d, 0xe8,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x03, 0xb0, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x22, 0x0e, 0x70, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x50,
   0x00, 0x00, 0x5e, 0x04, 0x00, 0x00, 0x0e, 0x70, 0x00, 0x00, 0xa2, 0x00,
   0x20, 0x00, 0x04, 0x20, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x04, 0x20,
   0x20, 0x00, 0x00, 0x00, 0x00, 0x42, 0x10, 0x44, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x82, 0x10, 0x84, 0x41, 0x00, 0x00, 0x00, 0x00, 0x84, 0x20, 0x00,
   0x00, 0x00, 0x00, 0x00 };

U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* CS=*/ 10, /* reset=*/ 8);


void draw(void)
{
  u8g2.drawXBMP( 0, 0, 128, 64, myBitmap);
}

int Contador=0;
uint8_t m = 24;

void setup() 
{

  // put your setup code here, to run once:
  u8g2.begin();
  u8g2.clearBuffer();
}

void loop()
{
  // put your main code here, to run repeatedly:
  u8g2.firstPage();
  do
  {
    draw();
  }while(u8g2.nextPage());

  delay(1000);
   u8g2.clearDisplay();

u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0,15,"Hello World!");
  } while ( u8g2.nextPage() );
  delay(1000);

  char C_str[3];
  strcpy(C_str, u8x8_u8toa(Contador, 2));    /* convert m to a string with two digits */
  Contador=Contador+1;
  do {
    u8g2.setFont(u8g2_font_logisoso62_tn);
    u8g2.drawStr(0,63,C_str);
   
  } while ( u8g2.nextPage() );
  delay(1000);
  
  char m_str[3];
  strcpy(m_str, u8x8_u8toa(m, 2));    /* convert m to a string with two digits */
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_logisoso62_tn);
    u8g2.drawStr(0,63,"9");
    u8g2.drawStr(33,63,":");
    u8g2.drawStr(50,63,m_str);
  } while ( u8g2.nextPage() );
  delay(1000);
  m++;
  if ( m == 60 )
    m = 0;
delay(1000);
  u8g2.clearDisplay();
u8g2.firstPage();
  do
  {
    u8g2.drawXBMP( 0, 0, 128, 64, imagen1_bits);
  }while(u8g2.nextPage());
delay(4000);


}

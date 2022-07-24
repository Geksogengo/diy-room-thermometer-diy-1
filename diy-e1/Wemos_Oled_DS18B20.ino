#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <OneWire.h> 
#include <DallasTemperature.h>
int temperature = 0;

char strTemp[4]; 

//U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(5, 4, U8X8_PIN_NONE);
U8G2_SSD1306_64X32_1F_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

#define ONE_WIRE_BUS 0 
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
void setup(void)
{ 
  Serial.begin(9600);
  Wire.begin();
  u8g2.begin();
//  u8x8.begin();
//  u8x8.setPowerSave(0); 
}

void loop(void)
{
  sensors.begin(); 
  sensors.requestTemperatures();
  temperature = sensors.getTempCByIndex(0);
  Serial.print(temperature);
//  u8x8.begin();
//  u8x8.setPowerSave(0);
//  u8x8.setFont(u8x8_font_chroma48medium8_r);
 // u8x8.drawString(0,0,"Hello World 209!");
 // u8x8.drawString(temperature);
 // u8x8.drawString(3,4,( itoa(int(temperature), strTemp, 10 ))); // strTemp, 16)

  //u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_t0_11_tf);  // choose a suitable font
  //u8g2.drawStr(3,4,( itoa(int(temperature), strTemp, 10 ))); // strTemp, 16)
//  u8g2.drawStr(0, 20, sensors.getTempCByIndex(0));
//  u8g2.drawStr(0, 30, "I'm tiny…");
//  u8g2.sendBuffer();          // transfer internal memory to the display
 u8g2.setCursor(0,15);
 u8g2.print(temperature);
 //u8g2.drawGlyph(106,15,0X00b0);
 u8g2.drawStr(0, 15,"C");   
 // u8x8.drawString(0,7,"Hello World 209!");
 delay(5000);
}

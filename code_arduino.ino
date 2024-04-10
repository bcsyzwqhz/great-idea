
#include <U8g2lib.h>
#include <Wire.h>
#include <Adafruit_NeoPixel.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);
Adafruit_NeoPixel rgb_display_17= Adafruit_NeoPixel(3,17,NEO_GRB + NEO_KHZ800);

boolean judge() {
  int cnt = 0;
  for (int i = 1; i <= 5000; i = i + (1)) {
    if (analogRead(SOUND) >= 414) {
      cnt = cnt + 1;

    }
  }
  return cnt >= 3000;
}

void setup(){
  u8g2.setI2CAddress(0x3C*2);
  u8g2.begin();
  u8g2.enableUTF8Print();

  rgb_display_17.begin();
}

void loop(){
  u8g2.setFont(u8g2_font_wqy12_t_gb2312);
  u8g2.setFontPosTop();
  u8g2.firstPage();
  do
  {
    if (analogRead(SOUND) >= 414) {
      if (judge()) {
        u8g2.setCursor(0,20);
        u8g2.print("讲话");
        rgb_display_17.setPixelColor(0,0xff0000);
        rgb_display_17.setPixelColor(1,0xff0000);
        rgb_display_17.setPixelColor(2,0xff0000);

      }

    }
    rgb_display_17.show();
    rgb_display_17.setPixelColor(0,0x000000);
    rgb_display_17.setPixelColor(1,0x000000);
    rgb_display_17.setPixelColor(2,0x000000);
  }while(u8g2.nextPage());

}
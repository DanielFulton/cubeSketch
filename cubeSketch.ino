#include <Colorduino.h>

typedef struct
{
  unsigned char r;
  unsigned char g;
  unsigned char b;
} ColorRGB;

typedef struct
{
  unsigned char h;
  unsigned char s;
  unsigned char v;
} ColorHSV;

unsigned char plasma[ColorduinoScreenWidth]
                    [ColorduinoScreenHeight];
long paletteShift;

void ColorFill(unsigned char R, unsigned char G, unsigned char B) {
  PixelRGB *p = Colorduino.GetPixel(0,0);
  for (unsigned char y = 0; y < ColorduinoScreenWidth; y++) {
    for(unsigned char x = 0; x < ColorduinoScreenHeight; x++) {
      p -> r = R;
      p -> g = G;
      p -> b = B;
      p++;
    }
  }
  Colorduino.FlipPage();
}

void Walk(int waitTime) {
  for (unsigned char y = 0; y < ColorduinoScreenWidth; y++) {
    for(unsigned char x = 0; x < ColorduinoScreenHeight; x++) {
      ClearScreen();
      PixelRGB *p = Colorduino.GetPixel(x,y);
      p -> r = 255;
      p -> g = 255;
      p -> b = 255;
      Colorduino.FlipPage();
      delay(waitTime);
    }
  }
        ColorFill(0,0,0);
      Colorduino.FlipPage();
delay(waitTime);
}

void DisplayG() {
  DisplayPixelWhite(0,0);
  DisplayPixelWhite(0,1);
  DisplayPixelWhite(0,2);
  DisplayPixelWhite(0,3);
  DisplayPixelWhite(1,0);
  DisplayPixelWhite(2,0);
  DisplayPixelWhite(2,1);
  DisplayPixelWhite(3,1);
  DisplayPixelWhite(1,3);
  DisplayPixelWhite(2,3);
  Colorduino.FlipPage();
}

void DisplayI() {
  DisplayPixelWhite(1,0);
  DisplayPixelWhite(1,1);
  DisplayPixelWhite(1,2);
  DisplayPixelWhite(1,3);
  Colorduino.FlipPage();
}

void DisplayL() {
  DisplayPixelWhite(0,0);
  DisplayPixelWhite(0,1);
  DisplayPixelWhite(0,2);
  DisplayPixelWhite(0,3);
  DisplayPixelWhite(1,0);
  DisplayPixelWhite(2,0);
  Colorduino.FlipPage();
}

void DisplayT() {
  DisplayPixelWhite(1,0);
  DisplayPixelWhite(1,1);
  DisplayPixelWhite(1,2);
  DisplayPixelWhite(1,3);
  DisplayPixelWhite(0,3);
  DisplayPixelWhite(2,3);
  Colorduino.FlipPage();
}

void DisplayPixelWhite(char x, char y) {
    PixelRGB *p = Colorduino.GetPixel(x,y);
    p -> r = 255;
    p -> g = 255;
    p -> b = 255;
}

void ClearScreen() {
  ColorFill(0,0,0);
  Colorduino.FlipPage();
}

void setup() {  
  Colorduino.Init();
  unsigned char whiteBalVal[3] = {36,63,63};
  Colorduino.SetWhiteBal(whiteBalVal);
  paletteShift = 128000;
  unsigned char bcolor;
  ColorFill(0,0,0);
}

void loop() {
    ClearScreen();
    DisplayG();
    delay(2000);
    ClearScreen();
    DisplayI();
    delay(2000);
    ClearScreen();
    DisplayL();
    delay(2000);
    ClearScreen();
    DisplayT();
    delay(2000);
}

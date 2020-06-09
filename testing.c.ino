
#include <Adafruit_NeoPixel.h>
#define LED_PIN 5
#define LED_COUNT 150

#define CLICK_PIN 8

#define BRIGHT_PIN 3
#define COLOR_PIN 0
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ400);
int val = 1;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello World!");

  strip.begin();
  strip.clear();
  int inc = 0;
  while( inc < LED_COUNT ) {
    strip.setPixelColor(inc, 128, 128, 128);
    inc ++;
  }
  
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // set brightness
  
  int new_val = 1;
  int bright = 1;
  int test;
  new_val = analogRead(BRIGHT_PIN);
  if ( (abs( val - new_val ) > 7) && val != new_val ) {
 
    bright = round(new_val / 4);
    if( bright < 10 ) {
      bright = 1;
    }
    strip.setBrightness(bright);
    strip.show();
    val = new_val;    
  }
  


  //Serial.println(val,8);
  //Serial.println(new_val,8);
  //Serial.println(test,8);
  //Serial.println(bright,8);  
  //Serial.println(val,8);
  //Serial.println(' ');
  delay(24);
}

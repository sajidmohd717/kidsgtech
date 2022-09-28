#include <FastLED.h>
#define LED_PIN 0
#define NUM_LEDS 6

CRGB leds[NUM_LEDS];

int incomingByte = 0;

void setup() {
  Serial.begin(9600);
  
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();
  Serial.println("Enter data: (red, green, blue or rainbow");
}

void loop() {

  Serial.println("Enter data: (red, green, blue or rainbow");
  while (Serial.available() == 0) {}     //wait for data available
  String teststr = Serial.readString();  //read until timeout
  teststr.trim();                        // remove any \r \n whitespace at the end of the String
  if (teststr == "red") {
    Serial.println(teststr);
    for (int i=0; i<NUM_LEDS; i++) {
      leds[i] = CRGB(255, 0, 0 );
      FastLED.show();
      delay(50);
    }
  } else if (teststr == "green") {
    Serial.println(teststr);
    for (int i=0; i<NUM_LEDS; i++) {
      leds[i] = CRGB(0, 255, 0 );
      FastLED.show();
      delay(50);
    }
  } else if (teststr == "blue") {
    Serial.println(teststr);
    for (int i=0; i<NUM_LEDS; i++) {
      leds[i] = CRGB(0, 0, 255 );
      FastLED.show();
      delay(50);
    }
  } else {
    Serial.println("rainbow");
    leds[0] = CRGB(255, 0, 0 );
    FastLED.show();
    delay(50);
    leds[1] = CRGB(255, 69, 0 );
    FastLED.show();
    delay(50);
    leds[2] = CRGB(255, 255, 0 );
    FastLED.show();
    delay(50);
    leds[3] = CRGB(0, 255, 0 );
    FastLED.show();
    delay(50);
    leds[4] = CRGB(0, 0, 255 );
    FastLED.show();
    delay(50);
    leds[5] = CRGB(255, 0, 255 );
    FastLED.show();
    delay(50);
  }
}

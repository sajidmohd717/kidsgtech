#include <FastLED.h>

#define LED_PIN 0
#define NUM_LEDS 6
#define echoPin 4
#define trigPin 5

CRGB leds[NUM_LEDS];

long duration;
int distance;


void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
 
}

void loop() {

  
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");


  if (distance < 20) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(255,0,0);
      FastLED.show();
      delay(100);
    }
  }
  else if (distance < 40) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(0,255,0);
      FastLED.show();
      delay(100);
    }
  }
  else {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(0,0,255);
      FastLED.show();
      delay(100);
    }
  }
    
  
  
}

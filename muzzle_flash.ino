#include <Adafruit_NeoPixel.h>

#define PIN         A4   // Anschluss der Busleitung für die neopixel (ws2812b)
#define NUMPIXELS   6    // Anzahl der verbauten neopixel (ws2812b)
#define SCHUSSALARM 40   // Nach wieviel Schüssen wird ein optisches signal gegeben
#define ROT   255        //255
#define GRUEN 220        //220
#define BLAU  30         //30

int     sensorPin   = A5;// Anschluss des Fototransistors
int     alarmPin    = 13;// Pin der Alarm LED, hier die eingebaute LED auf dem Board

int     sensorValue = 0;
int     counter     = 0;
boolean trigger     = false;
boolean trigger2    = false;
boolean demoMode    = false;


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(alarmPin, OUTPUT);
  digitalWrite(alarmPin, LOW);
  pixels.begin();
  sensorValue = digitalRead(sensorPin);
  if (sensorValue == 0) {
    demoMode = true;
  }
  for (int i = 0; i < NUMPIXELS; i++)
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  pixels.show();
}

void loop() {
  if (demoMode) {
    if (sensorValue == 0)
      sensorValue = 1;
    else
      sensorValue = 0;
  } else {
    sensorValue = digitalRead(sensorPin);
  }
  if (sensorValue == 1 && trigger) {
    trigger = false;
  }

  if (trigger2) {
    trigger2 = false;
    for (int i = 0; i < NUMPIXELS; i++)
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  if (sensorValue == 0 && !trigger) {
    trigger = true;
    trigger2 = true;
    counter++;
    for (int i = 0; i < NUMPIXELS; i++)
      pixels.setPixelColor(i, pixels.Color(ROT, GRUEN, BLAU)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(40);
  }
  if (counter == SCHUSSALARM)
    digitalWrite(alarmPin, HIGH);
  if (demoMode && sensorValue == 1)
    delay(random(1, 20) * 50);
}

/*
  Adjust RGB
  
  A dimmer to choose exactly what colour you want!
  
  This sketch is a follow up to my last one 'AdjustBrightness'

  The code receives the analog sensor value of the potentiometer from analog pin 0, 
  maps it from a range of 0 - 511 and uses this value choose what colour to light up.

 created  26 Dec 2015
 by Muhammad Muhsin
*/
 
int potPin = 0;
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
  //intializing the pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  //reading value from pot
  int val = map(analogRead(potPin), 0, 1023, 0, 511);

  //setting colour accordin to reading from pot
  if(val < 256) {
    setLedColour(255 - val, val, 0);
    delay(5);
  }
  else if(val < 512) {
    setLedColour(0, 255 - val, val);
    delay(5);
  }
}
  
void setLedColour(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

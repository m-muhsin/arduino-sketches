/*
  Adjust Brightness

  Works just like the light dimmer at you home!
  
  A little sketch I came up with after going through a couple of examples.

  This code receives the analog sensor value of the potentiometer from analog pin 0 
  and uses this value to set the brightness of the output of pin 9.

  Based on the following example projects:
  Read Analog Voltage - https://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
  Fade - https://www.arduino.cc/en/Tutorial/Fade

 created  21 Dec 2015
 by Muhammad Muhsin

*/

const int ledPin = 9; //the pin that connects to the LED
int brightness; //stores the brightness level of the LED
int sensorValue; //stores the analog input from the potentiometer

void setup() {
  // initiliaze the PWM pin as an output
  pinMode(ledPin, OUTPUT);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

}

void loop() {

  // read the input on analog pin 0
  sensorValue = analogRead(A0);

  //brightness ranges from 0 - 255, so
  brightness = sensorValue / 4;

  //for monitoring purposes
  Serial.println(brightness);

  //light up the LED
  analogWrite(ledPin, brightness);

}

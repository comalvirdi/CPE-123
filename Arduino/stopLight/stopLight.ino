#include <CPutil.h>

// Define your pins

const int redLedPin = 12;
const int greenLedPin = 10;
const int yellowLedPin = 11;
const int buttonPin = 9;

Button myButton(buttonPin);

// Create your hardware

Led redLed(redLedPin);
Led greenLed(greenLedPin);
Led yellowLed(yellowLedPin);

void setup() 
{
  
  // Set up serial monitor and print out program info
  Serial.begin(9600);
  delay(500);
  
  // Initialize your hardware
  redLed.on();
  greenLed.off();
  yellowLed.off();
  
}

void loop() 
{
  // put your main code here, to run repeatedly:

   stopLight();
 
}

void stopLight()
{
  static MSTimer ledTimer;
  if (myButton.wasPushed() == true)
  {
    redLed.off();
    greenLed.on();

    ledTimer.set(3000);
    while(!ledTimer.done()) {
    }
   
    greenLed.off();
    yellowLed.on();

    ledTimer.set(1000);
    while(!ledTimer.done()){
    }
    
    yellowLed.off();
    redLed.on();
    
  }
}
  
    
   

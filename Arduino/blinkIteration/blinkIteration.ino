#include <CPutil.h>

// Define your pins

const int redLedPin = 12;
const int buttonPin = 9;

Button myButton(buttonPin);

// Create your hardware

Led redLed(redLedPin);


void setup() 
{
  
  // Set up serial monitor and print out program info
  Serial.begin(9600);
  delay(500);
  
  // Initialize your hardware
  redLed.off();
}

void loop() 
{
  // put your main code here, to run repeatedly:

   blinkIteration();
 
}

void blinkIteration()
{
  static int count = 0;
  int repeatCount = 0;
  MSTimer timer;
   
  if (myButton.wasPushed())
  {
    count ++;
    repeatCount = count;

    while (repeatCount > 0)
    {
      redLed.on();
      timer.set(500);
      while(!timer.done()) 
        { }
      redLed.off();
      timer.set(500);
      while(!timer.done()) 
        { }
      repeatCount -- ;
    }
  }
}
  

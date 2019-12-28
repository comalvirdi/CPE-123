#include <CPutil.h>

const int yellowLedPin = 4;
const int blueLedPin = 5;

// Create your hardware

Led yellowLed(yellowLedPin);
Led blueLed(blueLedPin);

void setup() 
{
  
  // Set up serial monitor and print out program info
  Serial.begin(9600);
  setupMessage(__FILE__, "Blinks an LED");
  delay(500);
 
  // Initialize your hardware
  yellowLed.off();
  blueLed.off();

}

void loop() 
{
  // put your main code here, to run repeatedly:

   drive();
 
}

void drive()
{
  static int printCount = 0;
  static MSTimer timer;
  static int counter = 0;

  if (timer.done())
  {
    if (counter == 0)
    {
      yellowLed.on();
      blueLed.on();
      timer.set(3000);
      if (printCount == 0)
      {
        Serial.println("Driving first segment");
        printCount ++;
      }
      counter ++;
    }
    
    else if (counter == 1)
    {
      yellowLed.off();
      timer.set(1000);
      if (printCount == 1)
      {
        Serial.println("Taking First Right turn");
        printCount ++;
      }
      counter ++;
    }
    
     else if (counter == 2)
    {
      yellowLed.on();
      timer.set(3000);
      if (printCount == 2)
      {
        Serial.println("Driving Second Segment");
        printCount ++;
      }
      counter ++;
    }
    
     else if (counter == 3)
    {
      blueLed.off();
      timer.set(1000);
      if (printCount == 3)
      {
        Serial.println("Taking First Right turn");
        printCount ++;
      }
      counter ++;
    }
    
     else if (counter == 4)
    {
      blueLed.on();
      timer.set(3000);
      if (printCount == 4)
      {
        Serial.println("Driving Third Segment");
        printCount ++;
      }
      counter ++;
    }
    
     else if (counter == 5)
    {
      blueLed.off();
      timer.set(1000);
      if (printCount == 5)
      {
        Serial.println("Taking First Right turn");
        printCount ++;
      }
      counter ++;
    }
    
     else if (counter == 6)
    {
      blueLed.on();
      timer.set(3000);
      if (printCount == 6)
      {
        Serial.println("Driving Fourth Segment");
        printCount ++;
      }
      counter ++;
    }
    
     else if (counter == 7)
    {
      yellowLed.off();
      timer.set(1000);
      if (printCount == 7)
      {
        Serial.println("Taking First Right turn");
        printCount ++;
      }
      counter ++;
    }
    
     else if (counter == 8)
    {
      yellowLed.on();
      timer.set(3000);
      if (printCount == 8)
      {
        Serial.println("Driving Fifth Segment");
        printCount ++;
      }
      counter ++;
    }
    
    else
    {
      yellowLed.off();
      blueLed.off();
    }
  }
  
}

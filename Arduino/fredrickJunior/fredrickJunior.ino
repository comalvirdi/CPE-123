#include <CPutil.h>

const int yellowLedPin = 4;
const int blueLedPin = 5;
const int buttonPin = 8;
const int buttonPin2 = 9;

// Create your hardware

Led led1 (yellowLedPin);
Led led2 (blueLedPin);
Button b1(buttonPin);
Button b2(buttonPin2);

void setup() 
{
  
  // Set up serial monitor and print out program info
  Serial.begin(9600);
  setupMessage(__FILE__, "Blinks an LED");
  delay(500);
 
  // Initialize your hardware
  led1.off();
  led2.off();

}

void loop() 
{
  // put your main code here, to run repeatedly:

   fredrickJunior();
 
}

void fredrickJunior()
{
  enum {BOTH_OFF, L1_ON_L2_OFF, BOTH_ON};

  static int state = BOTH_OFF;
  switch (state)
  {
    case BOTH_OFF:
      if (b1.wasPushed())
      {
        led1.on();
        led2.off();
        state = L1_ON_L2_OFF;
      }
    break;

    case L1_ON_L2_OFF:
    if (b2.wasPushed())
      {
        led1.on();
        led2.on();
        state = BOTH_ON;
      }
      if (b1.wasPushed())
      {
        led1.off();
        led2.off();
        state = BOTH_OFF;
      }
    break;

    case BOTH_ON:
    if(b1.wasPushed())
    {
      led1.off();
      led2.off();
    }
    if(b2.wasPushed())
    {
      led1.off();
      led2.off();
    }
    break;
  }
}

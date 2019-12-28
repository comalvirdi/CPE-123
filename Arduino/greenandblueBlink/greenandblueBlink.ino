#include <CPutil.h>

const int greenLedPin = 9;
const int blueLedPin = 11;
const int buttonPin = 12;


// Create your hardware

Led gLed (greenLedPin);
Led bLed (blueLedPin);
Button button(buttonPin);

void setup() 
{
  
  // Set up serial monitor and print out program info
  Serial.begin(9600);
  setupMessage(__FILE__, "Blinks an LED");
  delay(500);
 
  // Initialize your hardware
  gLed.off();
  bLed.off();

}

void loop() 
{
  // put your main code here, to run repeatedly:

   control();
 
}

void control()
{
  enum {BOTH_OFF, BLED_BLINK_GLED_OFF, BLED_OFF_GLED_BLINK};
  static int state = BOTH_OFF;

  switch (state)
  {
    case BOTH_OFF:
    
      bLed.off();
      gLed.off();

      if(button.wasPushed())
      {
        state = BLED_BLINK_GLED_OFF;
      }
    break;

    case BLED_BLINK_GLED_OFF:
    
       gLed.off();
       blueBlink();

       if(button.wasPushed())
       {
        state = BLED_OFF_GLED_BLINK;
       }
    break;

    case BLED_OFF_GLED_BLINK:
    
      bLed.off();
      greenBlink();
      
      if(button.wasPushed())
       {
        state = BOTH_OFF;
       }
    break;
    
  }
}

void blueBlink()
{
  static MSTimer timer;
  enum{ON,OFF};
  static int state = 0;

  switch (state)
  {
    case ON:
      if (timer.done())
      {
        bLed.off();
        timer.set(500);
        state = OFF;
      }
    break;

    case OFF:
      if (timer.done())
      {
        bLed.on();
        timer.set(500);
        state = ON;
      }
    break; 
  }
}

void greenBlink()
{
  static MSTimer timer;
  enum{ON,OFF};
  static int state = 0;

  switch (state)
  {
    case ON:
      if (timer.done())
      {
        gLed.off();
        timer.set(1000);
        state = OFF;
      }
    break;

    case OFF:
      if (timer.done())
      {
        gLed.on();
        timer.set(1000);
        state = ON;
      }
    break; 
  }
}

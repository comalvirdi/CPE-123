#include <CPutil.h>
// By Comal Virdi
// Define your pins

const int redLedPin = 4;
const int greenLedPin = 5;
const int yellowLedPin = 6;
const int redLedPin2 = 7;
const int greenLedPin2 = 8;
const int yellowLedPin2 = 9;
const int buttonPin = 10;


// Create your hardware

Led rLedBig(redLedPin);
Led gLedBig(greenLedPin);
Led yLedBig(yellowLedPin);
Led rLedSm(redLedPin2);
Led gLedSm(greenLedPin2);
Led yLedSm(yellowLedPin2);

Button button(buttonPin);

void setup() 
{
  
  // Set up serial monitor and print out program info
  Serial.begin(9600);
  delay(500);
  
  // Initialize your hardware
  rLedBig.off();
  gLedBig.on();
  yLedBig.off();
  rLedSm.on();
  gLedSm.off();
  yLedSm.off();
}

void loop() 
{
  // put your main code here, to run repeatedly:

   bigSt();
 
}

void bigSt()
{
  
  enum{START, GREEN, YELLOW, RED};
  static int state = 0;
  static MSTimer timer;
  switch (state)
  {
  
    case START:
      timer.set(4000);
      gLedBig.on();
      rLedBig.off();
      yLedBig.off();
      state = GREEN;
    break;

    case GREEN:
    if (button.wasPushed() && timer.done())
      {
        timer.set(1000);
        gLedBig.off();
        yLedBig.on();
        state = YELLOW;
      }
    break;

    case YELLOW:
    if(timer.done())
    {
      timer.set(1000);
      yLedBig.off();
      rLedBig.on();
      state = RED;
    }
    break;

    case RED:
    if(smallSt())
    {
      state = START;
    }

    break;
  }
}

int smallSt()
{
  enum {RED, YELLOW, GREEN};
  static int state = 0;
  static MSTimer timer;
  int returnVal = false;
  switch (state)
   {

  case RED:
    timer.set(2000);
    rLedSm.off();
    gLedSm.on();
    state = GREEN;
    returnVal = false;
  break;

   case YELLOW:
    if (timer.done())
    {
      yLedSm.off();
      rLedSm.on();
      timer.set(1000);
      returnVal = true;
      state = RED;
    }
    else
    {
      returnVal = false;
    }
  break;
  
  case GREEN:
    if (timer.done())
    {
      gLedSm.off();
      yLedSm.on();
      timer.set(1000);
      returnVal = false;
      state = YELLOW;
    }
    else
    {
      returnVal = false;
    }
  break;
  } 
  return returnVal;
}  
    
   

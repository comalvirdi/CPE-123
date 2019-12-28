#include <CPutil.h>

// Encoder State Machine testing


// Put your pins here 
const int encoderPin1 = 2;
const int encoderPin2 = 3;


void setup() {
  // put your setup code here, to run once:

  // Setup serial monitor
  Serial.begin(9600);
  setupMessage(__FILE__, "Encoder Count Test");
  
  // configure the encoder pin 
  pinMode(encoderPin1, INPUT);
  pinMode(encoderPin2, INPUT);
}

void loop() 
{
	processEncoder(); 
}

void processEncoder()
{
	static MSTimer aTimer(1500);
	unsigned long count = 0;
	
	count = encoderCount(false) + encoderCount2(false);
		
	if (aTimer.done())
	{
		aTimer.set(1500);
		print2("Current Count: ", count);
	}
}

unsigned long encoderCount(int resetFlag)
{ 
  int pinValue = 0;
 
  pinValue = digitalRead(encoderPin1);

  enum {START, HIGH_STATE, LOW_STATE};
  static int state = START;
  static int count = 0;
  
if (resetFlag == true)
{
  count = 0;
}

  // Put your encoder state machine here
  switch (state)
  {
    case START:
      if (pinValue == HIGH)
      {
        state = HIGH_STATE;
      }
    break;

    case HIGH_STATE:
      if(pinValue == LOW)
      {
        count++;
        state = LOW_STATE;
      }
    break;

    case LOW_STATE:
      if (pinValue == HIGH)
      {
        count++;
        state = HIGH_STATE;
      }
    break;
 

  // put your return here

  }
  return count;
}
unsigned long encoderCount2(int resetFlag)
{ 
  int pinValue = 0;
 
  pinValue = digitalRead(encoderPin2);

  enum {START, HIGH_STATE, LOW_STATE};
  static int state = START;
  static int count = 0;
  
if (resetFlag == true)
{
  count = 0;
}

  // Put your encoder state machine here
  switch (state)
  {
    case START:
      if (pinValue == HIGH)
      {
        state = HIGH_STATE;
      }
    break;

    case HIGH_STATE:
      if(pinValue == LOW)
      {
        count++;
        state = LOW_STATE;
      }
    break;

    case LOW_STATE:
      if (pinValue == HIGH)
      {
        count++;
        state = HIGH_STATE;
      }
    break;
 

  // put your return here

  }
  return count;
}

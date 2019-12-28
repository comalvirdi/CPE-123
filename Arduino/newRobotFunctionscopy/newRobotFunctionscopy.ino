//Comal Virdi
// Group 3
#include <CPutil.h>
#include <CPE123_EncoderLib.h>

// Simple sketch to just test a motor

// Define our pins
const int leftMotorPin1 = 7;
const int leftMotorPin2 = 6;
const int rightMotorPin1 = 5;
const int rightMotorPin2 = 4;
const int myButton = 10;

const int rightEncoderPin1 = 20;
const int rightEncoderPin2 = 21;
const int leftEncoderPin1 = 2;
const int leftEncoderPin2 = 3;

Button button(myButton);
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  setupMessage(__FILE__, "Simple Motor Test sketch");
  delay(500);

  encoderSetup(rightEncoderPin1, rightEncoderPin2, leftEncoderPin1, leftEncoderPin2);
  
}



void loop()
{
  
 
 
}


void motorTest()
{
   

  print2 ("count for 20 cm:" , calcDistance(20));
  print2 ("count for 480 cm:" , calcDistance(480));
  print2 ("count for 700 cm:" , calcDistance(700));
  print2 ("count for 20 degrees:" , calcAngle(20));
  print2 ("count for 48 degrees:" , calcAngle(48));
  print2 ("count for 70 degrees:" , calcAngle(70));

  delay(1000); 
}

void motorSetup()
{
  
   // Initalize the pins for output 
   pinMode(leftMotorPin1, OUTPUT);
   pinMode(leftMotorPin2, OUTPUT);
   pinMode(rightMotorPin1, OUTPUT);
   pinMode(rightMotorPin2, OUTPUT);

    // Stop the motor
   analogWrite(leftMotorPin1, 0);
   analogWrite(leftMotorPin2, 0);
   analogWrite(rightMotorPin1, 0);
   analogWrite(rightMotorPin2, 0);

   
   robotStop();
     
}


int robotForward(int aSpeed, int driveTime)
{
  enum {FORWARD, STOP};
  static int state = FORWARD;
  static MSTimer timer;
  int returnValue = false;

  switch(state)
  {
    case FORWARD:
      timer.set(driveTime);
      returnValue = false;
      state = STOP;
    break;

    case STOP:
    if (timer.done())
    {
      robotStop();
      returnValue = true;
      state = FORWARD;
    }
   else 
   {
    leftMotorForward(aSpeed);
    rightMotorForward(aSpeed);
   }
   break;
  }
  
  return returnValue;
}

int robotBackward(int aSpeed, int driveTime)
{
  enum {FORWARD, STOP};
  static int state = FORWARD;
  static MSTimer timer;
  int returnValue = false;

  switch(state)
  {
    case FORWARD:
      timer.set(driveTime);
      returnValue = false;
      state = STOP;
    break;

    case STOP:
    if (timer.done())
    {
      robotStop();
      returnValue = true;
      state = FORWARD;
    }
   else 
   {
    leftMotorBackward(aSpeed);
    rightMotorBackward(aSpeed);
   }
   break;
  }
  return returnValue;
}

int robotLeft(int turnAngle, int aSpeed)
{
  enum {TURN, STOP};
  static int state = TURN;
  int returnValue = false;
  static unsigned long expectedTransitions = calcAngle(turnAngle);
  
  switch(state)
  {
    case TURN:
      if (leftEncoderCount() < expectedTransitions)
      {
        leftTurn(250);
        state = STOP;
        returnValue = false
      }
    break;
    
     case STOP:
      if (leftEncoderCount() >= expectedTransitions)
      {
        robotStop();
        state = STOP;
        returnValue = true;
      }
    break;
  
  return returnValue;
}

int robotRight(int turnTime)
{
  enum {FORWARD, STOP};
  static int state = FORWARD;
  static MSTimer timer;
  int returnValue = false;

  switch(state)
  {
    case FORWARD:
      timer.set(turnTime);
      returnValue = false;
      state = STOP;
    break;

    case STOP:
    if (timer.done())
    {
      robotStop();
      returnValue = true;
      state = FORWARD;
    }
    else 
    {
     rightTurn(250);
    }
    break;
  }
  
  return returnValue;
}
int robotSpin(int spinTime)
{
  enum {FORWARD, STOP};
  static int state = FORWARD;
  static MSTimer timer;
  int returnValue = false;

  switch(state)
  {
    case FORWARD:
      timer.set(spinTime);
      returnValue = false;
      state = STOP;
    break;

    case STOP:
    if (timer.done())
    {
      robotStop();
      returnValue = true;
      state = FORWARD;
    }
    else 
    {
    rightMotorForward(250);
    leftMotorBackward(250);
    }
    break;
  }
  
  return returnValue;
}
void motorControl(int pin1, int pin2, int aSpeed)
{
   analogWrite(pin1, aSpeed);
   analogWrite(pin2, 0);
}

void leftMotorForward(int aSpeed)
{
  motorControl(leftMotorPin1, leftMotorPin2, aSpeed);
}

void rightMotorForward(int aSpeed)
{
  motorControl(rightMotorPin1, rightMotorPin2, aSpeed);
}

void leftMotorBackward(int aSpeed)
{
  motorControl(leftMotorPin2, leftMotorPin1, aSpeed);
}

void rightMotorBackward(int aSpeed)
{
  motorControl(rightMotorPin2, rightMotorPin1, aSpeed);
}

void leftMotorStop()
{
  motorControl(leftMotorPin1, leftMotorPin2, 0);
}

void rightMotorStop()
{
  motorControl(rightMotorPin1, rightMotorPin2, 0);
}

void leftTurn(int aSpeed) 
{
  rightMotorForward(aSpeed);
  leftMotorStop();
}

void rightTurn(int aSpeed) 
{
  leftMotorForward(aSpeed);
  rightMotorStop();
}

void robotStop()
{
  leftMotorStop();
  rightMotorStop();
}
unsigned long calcAngle(int aAngle)
{
 unsigned long angleTransitions = 0;
  if (aAngle <= 360 && aAngle >= 0)
  {
    angleTransitions = aAngle * 36;
  }
  
  return angleTransitions;
}
unsigned long calcDistance(int aDistance)
{
  unsigned long distanceTransitions = 0;

  distanceTransitions = aDistance * 112;

  return distanceTransitions;
}

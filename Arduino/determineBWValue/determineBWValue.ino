#include <Servo.h>

//  Code to test out the analog IR sensors - HMS Fall 17

#include <CPutil.h>

// Define your pins
int irSensorPins[] = {A15, A14, A13, A12, A11};
Led irSensorLeds[] = {53, 52, 51, 50, 49};

const int leftMotorPin1 = 7;
const int leftMotorPin2 = 6;
const int rightMotorPin1 = 5;
const int rightMotorPin2 = 4;
const int buttonPin = 8;

const int rightEncoderPin1 = 20;
const int rightEncoderPin2 = 21;
const int leftEncoderPin1 = 2;
const int leftEncoderPin2 = 3;
Button myButton(buttonPin);

void setup() 
{
   Serial.begin(9600);
   setupMessage(__FILE__, "IR Sensor testing");
   delay(500);
       
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



void loop() 
{
  followLine();
}

void control()
{
  determineBWValue();
  Serial.println(determineBWValue());
}

void followLine(){

  int BWValue = determineBWValue();
  switch(BWValue)
  {
    case 1:
    case 2:
    case 6:
    case 3:
      robotForward(0,130);
    break;

    case 4:
     robotForward(130,130);
    break;

    case 8:
    case 12:
    case 16:
    case 24:
      robotForward(130,0);
    break;
  }
}
int determineBWValue()
{
  int value = 0;
  int power2[] = {1,2,4,8,16};
  for (int i=0; i<5; i++)
    {
      if (analogRead(irSensorPins[i]) > 200)
        {
          irSensorLeds[i]. on();
          value += power2[i];
        }
      else
      {
        irSensorLeds[i]. off();
      }
    }
    return value;
} 

void motorControl(int pin1, int pin2, int aSpeed)
{
   analogWrite(pin1, aSpeed);
   analogWrite(pin2, 0);
}
void robotForward(int leftMotorSpeed, int rightMotorSpeed)
{
  leftMotorForward(leftMotorSpeed);
  rightMotorForward(rightMotorSpeed);
}
void leftMotorForward(int aSpeed)
{
  motorControl(leftMotorPin1, leftMotorPin2, aSpeed);
}

void rightMotorForward(int aSpeed)
{
  motorControl(rightMotorPin1, rightMotorPin2, aSpeed);
}
void leftMotorStop()
{
  motorControl(leftMotorPin1, leftMotorPin2, 0);
}

void rightMotorStop()
{
  motorControl(rightMotorPin1, rightMotorPin2, 0);
}
   
void robotStop()
{
  leftMotorStop();
  rightMotorStop();
}

// ir_sensors_control.ino

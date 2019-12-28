#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

void setup() {
  myservo.attach(12);  // attaches the servo on pin 9 to the servo object
}

void loop() {

  unlock();
  delay(1000);
  lock();
  delay(1000);
  
}

void closed()
{
  myservo.write(100);
 
}

void open()
{
  myservo.write(210);
 
}

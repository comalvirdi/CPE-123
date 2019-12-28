/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

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

void unlock()
{
  myservo.write(100);
 
}

void lock()
{
  myservo.write(10);
 
}

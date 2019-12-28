#include "CPutil.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setupMessage(__FILE__);
  delay(500);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  calcAngle(10);
  
}

unsigned long calcAngle(int aAngle)
{
 unsigned long angleTransitions = 0;
 aAngle = Serial.available();
  if (aAngle <= 360 && aAngle >= 0)
  {
    angleTransitions = aAngle * 36.2;
  }
  
  return angleTransitions;
  Serial.print(angleTransitions);
}
unsigned long calcDistance(int aDistance)
{
  unsigned long distanceTransitions = 0;

  distanceTransitions = aDistance * 112.11;

  return distanceTransitions;
  Serial.print(distanceTransitions);
}

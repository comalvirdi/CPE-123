#include "CPutil.h"

void setup() 
{
  
  // Set up serial monitor and print out program info
  Serial.begin(9600);
}

void loop() 
{
 
  // Control code to turn on/off LED based on button
   findMax();
 
}

void findMax()
{
  int count = 0;
  int maxNum = 0;
  int number = 0;

  while (count <= 5)
  {
    if (Serial.available())
    {
      number = Serial.parseInt();
      count = count +1;
    }
    if (number > maxNum)
    {
      maxNum = number;
    }
  }
  Serial.println(maxNum);
}

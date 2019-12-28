#include "CPutil.h"


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    findMax();
}

void findMax()
{
  int array1 [] = {7,6,8,9,10};
  int maxN = 0;
  int minN = 0;
  
  for (int i=0; i<6; i++){
    
      if (i==0)
      {
        minN = array1[i];
        maxN = array1[i];
      }
      else if (array1[i] > maxN)
      {
        maxN = array1[i];
      }
      else if (array1[i] < minN){
        
        minN = array1[i];
      }
  }
  
  Serial.print(maxN + minN);
}

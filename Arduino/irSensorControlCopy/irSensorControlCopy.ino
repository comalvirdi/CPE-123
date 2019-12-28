//  Code to test out the analog IR sensors - HMS Fall 17

#include <CPutil.h>

// Define your pins
int irSensorPins[] = {A15, A14, A13, A12, A11};


void setup() 
{
   Serial.begin(9600);
   setupMessage(__FILE__, "IR Sensor testing");
   delay(500);
       
}

void loop() 
{
  control();
}

void control()
{
  int sampleCount = 0;
  int irSensorMax[] = {0, 0, 0, 0, 0};
  int irSensorMin[] = {0, 0, 0, 0, 0};
  unsigned long irSensorTotal[] = {0, 0, 0, 0, 0};
  

  sampleCount = readIRSensors(irSensorMax, irSensorMin, irSensorTotal);
  printIRSensors(irSensorMax, irSensorMin, irSensorTotal, sampleCount);
}
       
int readIRSensors(int irSensorMax[], int irSensorMin[], unsigned long irSensorTotal[])
{
  static MSTimer timer = 0;
  static MSTimer timer2 = 0;
  int count = 0;
  
    delay(1000);
    timer.set(2000);
    int value = 0;
    
    while (!timer.done())
      {
      timer2.set(50);
      for (int i=0; i<5; i++)
        {
          value = analogRead(irSensorPins[i]);
          if (value < irSensorMin[i] || count==0)
            {
              irSensorMin[i] = value;
            }
          if (value > irSensorMax[i] || count==0)
            {
              irSensorMax[i] = value;
            }
          irSensorTotal[i] = value + irSensorTotal[i];
        }
        count++;
        while (!timer2.done())
        {}
      }
    
    return count;
}
 
     
void printIRSensors(int irSensorMax[], int irSensorMin[], unsigned long irSensorTotal[], int sampleCount) 
{
  for (int i=0; i<5;i++)
  {
    print4("min:", irSensorMin[i], "  max:", irSensorMax[i], false);
    print2 ("  average:", irSensorTotal[i] / sampleCount);
     
  }
   Serial.println ();
}    

// ir_sensors_control.ino

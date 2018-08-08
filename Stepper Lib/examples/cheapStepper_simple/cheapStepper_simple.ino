#include <CheapStepper.h>
CheapStepper stepper;
   boolean moveClockwise = true; 

void setup() {
   Serial.begin(9600);
   Serial.println("Ready to start moving!");
  }

void loop() {

  if (moveClockwise == true){
   for (int s=0; s<12288; s++){

    stepper.step(moveClockwise);
   
    int nStep = stepper.getStep();
 
   
  }
  moveClockwise = false; 
  delay(1000);
  
}
}


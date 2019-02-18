

 
#include <Stepper.h>
 

// Number of steps per output rotation
//hammer motor
const int STEPS_PER_REV = 200;
const int SPEED_CONTROL = 80;

Stepper stepper1(STEPS_PER_REV, 8, 9, 10, 11);

void setup() {
  // nothing   
}
 
void loop() {

    stepper1.setSpeed(SPEED_CONTROL);
    
    stepper1.step(STEPS_PER_REV);
//    delay(100);
  }
  

#include <Servo.h>

Servo servo_pan;  // create servo object to control a servo 
Servo servo_tilt;  // create servo object to control a servo 

int val;    // variable to read the value from the analog pin 

void setup() 
{ 
  servo_pan.attach(9);
  servo_tilt.attach(10);
} 

void loop() 
{ 
    servo_pan.write(90);          
    servo_tilt.write(135);
    
} 

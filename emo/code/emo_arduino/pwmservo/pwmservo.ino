#include <PWMServo.h>

PWMServo servo_pan;  // create servo object to control a servo 
PWMServo servo_tilt;  // create servo object to control a servo 

int val;    // variable to read the value from the analog pin 

void setup() 
{ 
  
  servo_pan.attach(SERVO_PIN_A);
  servo_tilt.attach(SERVO_PIN_B);

} 

void loop() 
{ 
    servo_pan.write(90);          
    servo_tilt.write(135);
    delay(10);
    
    for (int p=1; p++; p <=180) {
      servo_pan.write(p);     
    }
    Serial.println(servo_pan.read());
} 

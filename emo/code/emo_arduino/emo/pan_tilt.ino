// EMO Pan_Tilt
/**
 * Author : Michael Azzopardi
 * Date: 31 August 2014
 *
 * 
 *
 **/


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

const uint8_t tilt_servonum = 4;  
const uint8_t pan_servonum = 5;

const int panMidPosPulse = 380;
const int tiltMidPosPulse = 485;

const int panMinPosPulse = 150;
const int tiltMinPosPulse = 310;

const int panMaxPosPulse = 610;
const int tiltMaxPosPulse = 550;

uint8_t panPos = 90;
uint8_t tiltPos = 135;

void servoInit() 
{ 
  /*
  servo_pan.attach(servoPin_Pan);
   servo_tilt.attach(servoPin_Tilt);
   
   if (servo_pan.attached() == 1) {
   Serial.println("[PAN_TILT] Servo Pan is attached");
   } else {
   Serial.println("{PAN_TILT] Servo Pan is not attached");
   }
   
   if (servo_tilt.attached() == 1) {
   Serial.println("[PAN_TILT] Servo Tilt is attached");
   } else {
   Serial.println("[PAN_TILT] Servo Tilt is not attached");
   }
   
   servoReset();
   */

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  servoReset();

} 

void servoReset() {
  panPos = 90;
  tiltPos = 135;

  // Tilt
  pwm.setPWM(tilt_servonum, 0, tiltMidPosPulse);
  // Pan
  pwm.setPWM(pan_servonum, 0, panMidPosPulse);

  //pan(panPos);
  //tilt(tiltPos);
}

void panLeft() {
  if (panPos <= 170) {
    pan(panPos+10);
  }
}

void panRight() {
  if (panPos >= 10) {
    pan(panPos-10);
  }
}

void tiltUp(){
  if (tiltPos <= 170) {
    tiltPos = tiltPos+1;
  }
  tilt(tiltPos);
}

void tiltDown(){
  if (tiltPos >= 0) {
    tiltPos = tiltPos-1; 
  }
  tilt(tiltPos);
}

void pan(int deg) {
  //servo_pan.write(deg);
}

void tilt(int deg) {
  //servo_tilt.write(deg);
}


void servoPos() {
  //int tiltPos = servo_tilt.read();
  //Serial.println("tilt angle "+tiltPos);

  //int panPos = servo_pan.read();
  //Serial.println("pan angle "+panPos);
}




// EMO Rover
/**
 * Author : Michael Azzopardi
 * Date: 31 August 2014
 *
 * 
 *
 **/

int defaultSpeed = 100;

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *motor_FR = AFMS.getMotor(1);
Adafruit_DCMotor *motor_FL = AFMS.getMotor(2);
Adafruit_DCMotor *motor_RR = AFMS.getMotor(3);
Adafruit_DCMotor *motor_RL = AFMS.getMotor(4);

void roverInit() {
  AFMS.begin();

  roverAction = STOP;
  motor_FR->setSpeed(defaultSpeed);
  motor_FL->setSpeed(defaultSpeed);
  motor_RR->setSpeed(defaultSpeed);
  motor_RL->setSpeed(defaultSpeed);  
}

void roverDrive(int direction) {
  if (direction != STOP) {
    motor_FR->setSpeed(defaultSpeed);
    motor_FL->setSpeed(defaultSpeed);
    motor_RR->setSpeed(defaultSpeed);
    motor_RL->setSpeed(defaultSpeed);
  }

  switch (direction) {
  case STOP: 
    motor_FR->setSpeed(0);
    motor_FL->setSpeed(0);
    motor_RR->setSpeed(0);
    motor_RL->setSpeed(0);
    break;
  case MOVE_FORWARD:
    motor_FR->run(FORWARD);
    motor_FL->run(FORWARD);
    motor_RR->run(FORWARD);
    motor_RL->run(FORWARD);
    break;
  case MOVE_BACKWARD: 
    motor_FR->run(BACKWARD);
    motor_FL->run(BACKWARD);
    motor_RR->run(BACKWARD);
    motor_RL->run(BACKWARD);
    break;
  case MOVE_FORWARD_LEFT: 
    motor_FR->run(RELEASE);
    motor_FL->run(FORWARD);
    motor_RR->run(RELEASE);
    motor_RL->run(FORWARD);
    break;
  case MOVE_FORWARD_RIGHT: 
    motor_FR->run(FORWARD);
    motor_FL->run(RELEASE);
    motor_RR->run(FORWARD);
    motor_RL->run(RELEASE);
    break;
  case MOVE_BACKWARD_LEFT:  
    motor_FR->run(RELEASE);
    motor_FL->run(BACKWARD);
    motor_RR->run(RELEASE);
    motor_RL->run(BACKWARD);
    break;
  case MOVE_BACKWARD_RIGHT: 
    motor_FR->run(BACKWARD);
    motor_FL->run(RELEASE);
    motor_RR->run(BACKWARD);
    motor_RL->run(RELEASE);
    break;
  default: 
    motor_FR->run(RELEASE);
    motor_FL->run(RELEASE);
    motor_RR->run(RELEASE);
    motor_RL->run(RELEASE);
  }
}

// Forward
// Reverse
// Forward Turn
// Reverse Turn
// Stop
// Rotate
// Speed and acceleration




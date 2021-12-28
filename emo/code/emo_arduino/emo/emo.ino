// Emo Hardware Control Module
/** Author: Michael Azzopardi
 * Date: 31 August 2014
 * Version 0.2
 *
 * The EMO HCM is the software component that runs on the Arduino microcontroller board
 * It controls various hardware components of the EMO robot.
 * The modules of EMO HCM are:
 * - Neoring: Emotion and state display using NeoFruit Ring LEDs
 * - Ping: Detection of object proximity using HC-S04 Ping Sensors
 * - Pan_Tilt: Control of pan and tilt for cameras and neoring hardware module
 * - Rover: motion control using Adafruit MotorShielf v.2.0
 * - Pir - presence detection using a PIR motion sensor
 * - Lcd - display of status and other messages using a 16x2 LCD module
 * - Status - reports status of emo
 * - Commos - communication module with other electronic components
 **/

#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>
#include <Time.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <MemoryFree.h>
#include <NewPing.h>

// emo Arduino hardware configuration
// Here are attributes that are required by main program

// Sound
const int tonePin = 10;
const int ledPin = 13;

// Serial
byte incomingByte;

//Neoring
// Ring animation Mode
const int OFF = 0;
const int ON = 1;
const int SLEEP = 2;
const int SMILE = 3;
const int ANGRY = 4;
const int ARMED = 5;
const int ALARM = 6;
const int LOAD = 7;
const int DISTANCE = 8;
const int STANDBY = 9;
const int AWAKE = 10;

// Debugging and Logs
int debugLevel = 0;

// emo states
time_t currentTime;
int expression = OFF;

// proximity
int proximityFC = 0;
int proximityFL = 0;
int proximityFR = 0;
int proximityBC = 0;
int proximityBL = 0;
int proximityBR = 0;

int min_proximity = 20;
int max_proximity = 100;

boolean moving = true;
boolean turning = false;
int turn_duration = 1000;
// presence
boolean presence = false;

// Rover
// Ring animation Mode
const int STOP = 0;
const int MOVE_FORWARD = 1;
const int MOVE_BACKWARD = 2;
const int MOVE_FORWARD_LEFT = 3;
const int MOVE_FORWARD_RIGHT = 4;
const int MOVE_BACKWARD_LEFT = 5;
const int MOVE_BACKWARD_RIGHT = 6;
int roverAction = STOP;

// Timing
uint32_t currTime;
int turningTime = -1;
int turningElapseTime;

// Startup Arduino module
void setup() {
  startup();

}

// Continuous loop sequence
void loop() {
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  ringExpression();
  
  // Update status attributes
  updateStatus();
  printStatus();
  logStatus();
  // Check surrounding for object and calclate proximity
  ping();
  // pirDetect();
  
  serialAction() ;

  // Change expression based on proximity
  if (proximityFC <= max_proximity) {
    expression = DISTANCE;
  } 
  else {
    expression = AWAKE;
  }

  // **************** BEHAVIOR ********************
  /*
  if (moving == true) {
    if (turning == false) {
      // is currently not turning
      if (proximityFC > min_proximity)  {
        // keep on moving
        roverAction=MOVE_FORWARD;
      } 
      else {
        // start turning
        turning = true;
        turningTime = currTime;
        roverAction=MOVE_BACKWARD_LEFT;
      }
    } 
    else {
      // is currently turning
      turningElapseTime = currTime - turningTime;
      if (turningElapseTime < turn_duration) {
        // keep on turning
      } 
      else {
        // check if should move
        if (proximityFC > min_proximity)  {
          // start moving
          roverAction=MOVE_FORWARD;
          turning = false;
        } 
        else {
          // reset turn timer
          turningTime = currTime;
        }
      }
    }
  }
  */
  // **************** BEHAVIOR ********************
  
  
  if (moving == true) {
    if ((proximityFL >= max_proximity) && (proximityFC >= max_proximity) && (proximityFR >= max_proximity)) {
      roverAction=MOVE_FORWARD;
    } else {
      // Move towards empty space
      if (proximityFL >= max_proximity) {
        roverAction=MOVE_FORWARD_LEFT;
      } else
      if (proximityFR >= max_proximity) {
        roverAction=MOVE_FORWARD_RIGHT;
      } else
      // Start backing
      if (proximityBL >= max_proximity) {
        roverAction=MOVE_BACKWARD_LEFT;
      } else
      if (proximityBR >= max_proximity) {
        roverAction=MOVE_BACKWARD_RIGHT;
      }
      else
      if (proximityBC >= min_proximity) {
        roverAction=MOVE_BACKWARD;
      } else   
      {
        roverAction=STOP;
      }
    }
  }
  
  roverDrive(roverAction);


  String proximity[12] = {"FL",(String)proximityFL,"FC",(String)proximityFC,"FR",(String)proximityFR,"BL",(String)proximityBL,"BC",(String)proximityBC,"BR",(String)proximityBR};
  serialPrint(0, toJsonMsg("proximity", 6, proximity));
}






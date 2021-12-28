#include <NewPing.h>

//ultrasonic sensors
#define SONAR_NUM 2

#define L_TRIGPIN 6 //green
#define L_ECHOPIN 7 //blue

#define R_TRIGPIN 5 //purple
#define R_ECHOPIN 4 //orange

#define MAX_DISTANCE 200
#define LEFT 0
#define RIGHT 1

unsigned int ussInterval = 1000;
unsigned long lastUSSUpdate = 0;
NewPing sonar_left = NewPing(L_TRIGPIN, L_ECHOPIN, MAX_DISTANCE);
//NewPing sonar_right = NewPing(R_TRIGPIN, R_ECHOPIN, MAX_DISTANCE);
int dist_left = -1;
int dist_right = -1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  Serial.println("Nova Spot Micro");
  Serial.println("Arduino Nano");
  Serial.println("Sonar Test");
}

void loop() {
  // put your main code here, to run repeatedly:
  dist_left = sonar_left.ping_cm();
//  dist_right = sonar_right.ping_cm();
  Serial.print("distance: LEFT ");
  Serial.print(dist_left);    
  Serial.print("       RIGHT ");
  Serial.println(dist_right);
  
  
}

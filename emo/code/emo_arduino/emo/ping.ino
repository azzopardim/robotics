// Ping sensors
#define MAX_DISTANCE 400
#define pingFC_trig 22
#define pingFC_echo 23
#define pingFL_trig 24
#define pingFL_echo 25
#define pingFR_trig 32
#define pingFR_echo 33

#define pingBL_trig 34
#define pingBL_echo 35
#define pingBC_trig 28
#define pingBC_echo 29
#define pingBR_trig 30
#define pingBR_echo 31

NewPing pingFC(pingFC_trig, pingFC_echo, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing pingFL(pingFL_trig, pingFL_echo, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing pingFR(pingFR_trig, pingFR_echo, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

NewPing pingBC(pingBC_trig, pingBC_echo, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing pingBL(pingBL_trig, pingBL_echo, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing pingBR(pingBR_trig, pingBR_echo, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int reading[6];

void pingInit() {
  // Get a first value from the ping sensor
  ping();
}

void ping(){
  // Front Center
  reading[0] = microsecondsToCentimeters(pingFC.ping()); // Convert ping time to distance in cm 
  // ignore values out of range
  if ((reading[0] <= 0) || (reading[0] > MAX_DISTANCE)) {
    reading[0] = MAX_DISTANCE;
  }
  proximityFC = movingAverage(0, reading[0]);
   
  // Front Left
  reading[1] = microsecondsToCentimeters(pingFL.ping()); // Convert ping time to distance in cm 
  // ignore values out of range
  if ((reading[1] <= 0) || (reading[1] > MAX_DISTANCE)) {
    reading[1] = MAX_DISTANCE;
  }
  proximityFL = movingAverage(1, reading[1]);

  // Front Right
  reading[2] = microsecondsToCentimeters(pingFR.ping()); // Convert ping time to distance in cm 
  // ignore values out of range
  if ((reading[2] <= 0) || (reading[2] > MAX_DISTANCE)) {
    reading[2] = MAX_DISTANCE;
  }
  proximityFR = movingAverage(2, reading[2]);
   
  // Back Center
  reading[3] = microsecondsToCentimeters(pingBC.ping()); // Convert ping time to distance in cm 
  // ignore values out of range
  if ((reading[3] <= 0) || (reading[3] > MAX_DISTANCE)) {
    reading[3] = MAX_DISTANCE;
  }
  proximityBC = movingAverage(3, reading[3]);
   
  // Back Left
  reading[4] = microsecondsToCentimeters(pingBL.ping()); // Convert ping time to distance in cm 
  // ignore values out of range
  if ((reading[4] <= 0) || (reading[4] > MAX_DISTANCE)) {
    reading[4] = MAX_DISTANCE;
  }
  proximityBL = movingAverage(4, reading[4]);

  // Back Right
  reading[5] = microsecondsToCentimeters(pingBR.ping()); // Convert ping time to distance in cm 
  // ignore values out of range
  if ((reading[5] <= 0) || (reading[5] > MAX_DISTANCE)) {
    reading[5] = MAX_DISTANCE;
  }
  proximityBR = movingAverage(5, reading[5]);  
 
}

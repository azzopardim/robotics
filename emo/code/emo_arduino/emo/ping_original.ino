// EMO Ping 
/**
 * Author : Michael Azzopardi
 * Date: 31 August 2014
 *
 * Replaced with NewPing because of lag issue
 *
 **/


/*

void pingInit() {
  pinMode(pingPin1_trig, OUTPUT);
  pinMode(pingPin1_echo, INPUT);
  // Get a first value from the ping sensor
  ping();
  // Use this value to fill the buffer
  for (int i=0; i<bufferSize-1; i++) {
    buffer[i] = reading1;
  }
}





void ping() {
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(pingPin1_trig, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(pingPin1_trig, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(pingPin1_trig, LOW);
  duration = pulseIn(pingPin1_echo, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  reading1 = cm;
  if (reading1 < 0) {
    reading1 = max_proximity;
  }
  proximity = movingAverage(reading1);
}


*/

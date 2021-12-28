// EMO Pir
/**
 * Author : Michael Azzopardi
 * Date: 31 August 2014
 *
 * 
 *
 **/
//the time when the sensor outputs a low impulse
long unsigned int lowIn;         

//the amount of milliseconds the sensor has to be low 
//before we assume all motion has stopped
long unsigned int pause = 5000;  

boolean lockLow = true;
boolean takeLowTime;  

int pirPin = 10;    //the digital pin connected to the PIR sensor's output
int calibrationTime = 10;   

void pirSetup() {
  pinMode(pirPin, INPUT);
  digitalWrite(pirPin, LOW);
  expression = LOAD;

  //give the sensor some time to calibrate
  Serial.println("[PIR] Calibrating sensor ");
  for(int i = 0; i < calibrationTime*100; i++){
    ringExpression();
  }

  Serial.println("[PIR] Sensor active");
}

void pirDetect() {
  if(digitalRead(pirPin) == HIGH){

    if(lockLow){  
      presence = true;
      //makes sure we wait for a transition to LOW before any further output is made:
      lockLow = true;            

      Serial.print("[PIR] Motion detected at ");
      Serial.print(millis()/1000);
      Serial.println(" sec"); 
    }         
    takeLowTime = true;
  }

  if(digitalRead(pirPin) == LOW){       
    presence = false;
    if(takeLowTime){
      lowIn = millis();          //save the time of the transition from high to LOW
      takeLowTime = false;       //make sure this is only done at the start of a LOW phase
    }
    //if the sensor is low for more than the given pause, 
    //we assume that no more motion is going to happen
    if(!lockLow && millis() - lowIn > pause){  
      presence = false;
      //makes sure this block of code is only executed again after 
      //a new motion sequence has been detected
      lockLow = true;                        
      Serial.print("[PIR] Motion ended at ");      //output
      Serial.print((millis() - pause)/1000);
      Serial.println(" sec");
    }
  }
}




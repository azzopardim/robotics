// EMO Status
/**
 * Author : Michael Azzopardi
 * Date: 31 August 2014
 *
 * 
 *
 **/
void printStatus() {
  switch (debugLevel) {
  case 0:
    break;
  case 1:
    printTime();
    serialPrint(0, "[STATUS] emo status (debug level 1)");
    break;
  case 2:
    printTime();
    serialPrint(0, "[STATUS] emo status (debug level 2)");    
    break;
  case 3:
    printTime();
    serialPrint(0, "[STATUS] emo status (debug level 3)");
    break;
  case 4:
    printTime();
    serialPrint(0, "[STATUS] emo status (debug level 4)");
    printProximity();
    printExpression();
    printPresence();
    printMemory();
    break;
  default:
    Serial.println("Debug level not set");
  }
}

void updateStatus() {
  currentTime = now();
  currTime = millis();
}

void printMemory() {
  printTime();
  String message = "[MEMORY] "+String(freeMemory());
  serialPrint(0, message);
}

void printProximity() {
  // State: proximity level from Ping Sensor 
  printTime();
  String message = "[PROXIMITY] Front Center: "+String(proximityFC)+" cm";
  serialPrint(0, message);
  message = "[PROXIMITY] Front Left:   "+String(proximityFL)+" cm";
  serialPrint(0, message);
  message = "[PROXIMITY] Front Right:  "+String(proximityFR)+" cm";
  serialPrint(0, message);
  message = "[PROXIMITY] Back Center:  "+String(proximityBC)+" cm";
  serialPrint(0, message);
  message = "[PROXIMITY] Back Left:    "+String(proximityBL)+" cm";
  serialPrint(0, message);
  message = "[PROXIMITY] Back Right:   "+String(proximityBR)+" cm";
  serialPrint(0, message);
}

void printPresence() {
  printTime();
  String message = "";
  if (presence == true) {
    message = "[PRESENCE] detected";
  } 
  else {
    message = "[PRESENCE] not detected";
  }
  serialPrint(0, message);
}

// EXPRESSION
void printExpression() {
  // State: expression mode for NeoRing
  printTime();
  String message = "[EXPRESSION] "+String(expression)+" - ";
  switch (expression) {
  case OFF : 
    message = message + "OFF";
    break;
  case LOAD :
    message = message + "LOAD";
    break;
  case ALARM :
    message = message + "ALARM";
    break;
  case SLEEP :
    message = message + "SLEEP";
    break;
  case ON :
    message = message + "ON";
    break;    
  case SMILE : 
    message = message + "SMILE";
    break;
  case ANGRY :
    message = message + "ANGRY";
    break;
  case ARMED :  
    message = message + "ARMED";
    break;
  case DISTANCE :
    message = message + "DISTANCE";
    break;
  case AWAKE :
    message = message + "AWAKE";
    break;
  default :
    message = message + "UNKNOWN";
  } 
  serialPrint(0, message);
}

// TIME
void printTime() {
  printDigits(hour(currentTime));  
  Serial.print(":");
  printDigits(minute(currentTime));
  Serial.print(":");
  printDigits(second(currentTime));
  Serial.print(" ");
}

void time(long val){  
  int days = elapsedDays(val);
  int hours = numberOfHours(val);
  int minutes = numberOfMinutes(val);
  int seconds = numberOfSeconds(val);

  // digital clock display of current time
  Serial.print(days,DEC);  
  printDigits(hours);  
  printDigits(minutes);
  printDigits(seconds);
  Serial.println();   
}

void printDigits(byte digits){
  // utility function for digital clock display: prints colon and leading 0
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits,DEC);  
}



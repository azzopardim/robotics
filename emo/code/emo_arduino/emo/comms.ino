// EMO Comms
/**
 * Author : Michael Azzopardi
 * Date: 31 August 2014
 *
 * TODO: Develop communication protocol to send and recieve instructions from Raspberry Pi
 *
 **/

int const data_rate = 9600;

void serialInit() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void serialPrint(int port, String msg) {
  switch (port) {
  case 0:
    Serial.println(msg);
    break;
  case 1:
    Serial1.println(msg);
    break;
  default:
    break;  
  }
}

void serialAction() {
  // Get action from serial port and change arduino state for actions
  
  if (Serial1.available() > 0) {
   // read the incoming byte:
   incomingByte = Serial1.read();
   // say what you got:
   Serial.print("[SerialComm] Received: ");
   Serial.println(incomingByte);
   }
   
   /*
   // **************** BEHAVIOR ********************
   if (incomingByte == B1110101) {
   Serial.println("up");
   tiltUp();
   }
   
   if (incomingByte == B1100100) {
   Serial.println("down");
   tiltDown();
   }
   */

  //incomingByte == 0;

  /*
  switch (incomingByte) {
   case 117:
   
   break; 
   case 100:
   tiltDown();
   break;
   case 3:
   panLeft();
   break;
   case 4:
   panRight();
   break;
   default:
   break;
   }
   */
}

void serialState() {
}



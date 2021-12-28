// EMO Comms
/**
 * Author : Michael Azzopardi
 * Date: 31 August 2014
 *
 * 
 *
 **/

int const data_rate = 9600;
 
                /**
                if (incomingChar == 'u') {
                    command = 1;
                } 
                
                if (incomingChar == 'd') {
                    command = 2;
                } 
                  
                if (incomingChar == 'l') {
                    command = 3;
                } 
                
                if (incomingChar == 'r') {
                    command = 4;
                }
                
                incomingChar = 'x';
                
                Serial.print("Command: ");
                Serial.println(command);
                **/

void serialInit() {
  Serial.begin(9600);
}

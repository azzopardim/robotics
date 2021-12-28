#include <aJSON.h>
 
// how much serial data we expect before a newline
const unsigned int MAX_INPUT = 50;

aJsonStream serial_stream(&Serial1);
String message  = "";
char character = '\r';

aJsonObject *cmd;
aJsonObject *prms;
aJsonObject *prm;

void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
}

void processMessage(aJsonObject *msg){
  // Get the Command
  cmd = aJson.getObjectItem(msg, "Command");
  String command = cmd->valuestring;
  
  // Based on the command
  if (cmd != NULL) {
    Serial.println("[SerialComm] Command received is "+command);
    
    if (command == "MOVE") {
      // MOVE
      prms = aJson.getObjectItem(msg, "Parameters");
 
      if (prms != NULL) {
        // Parsing parameters
        Serial.println("[SerialComm] Parameters received");

        if (prms->type == aJson_Array) {
          int n = aJson.getArraySize(prms);
          Serial.println(n);
          for (int i = 0; i < n; i++) {
            Serial.println(i);
            prm = aJson.getArrayItem(prms, i);
            
          }
          Serial.println("exited loop");
        }
        // This is crashing after 3 times !!!!! looks like there is a problem with getArrayItem
      } 
      else {      
        Serial.println("[SerialComm] No parameters passed for this command");
      }
    } 
    else {
      // do nothing
    }
  }
}

void loop(){

  if (serial_stream.available()) {
    /* First, skip any accidental whitespace like newlines. */
    serial_stream.skip();
  }

  if (serial_stream.available()) {
    /* Something real on input, let's take a look. */
    aJsonObject *msg = aJson.parse(&serial_stream);
    processMessage(msg);
    aJson.deleteItem(msg);
  }

  /* 
   aJsonObject* jsonObject = aJson.parse(message);
   aJsonObject* command = aJson.getObjectItem(root, "Command");
   Serial.println(command->value.valuestring);
   
   }
   */

}


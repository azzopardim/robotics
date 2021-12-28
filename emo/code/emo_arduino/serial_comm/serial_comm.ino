#include <aJSON.h>

// how much serial data we expect before a newline
const unsigned int MAX_INPUT = 50;

String message  = "";
char character = '\r';
  
void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
}
  
void loop(){
  
  
  if (Serial1.available() > 0) {
      character = char(Serial1.read());
      //Serial.println(byte(character));
      message = message+character;
      // Serial.println(message);
    }
    if (character == '\n') {
      Serial.println("echo: "+message);
      character = '\r';
      message = " ";
      
      aJsonObject* jsonObject = aJson.parse(message);
      aJsonObject* command = aJson.getObjectItem(root, "Command");
      Serial.println(command->value.valuestring);
      
    }
}

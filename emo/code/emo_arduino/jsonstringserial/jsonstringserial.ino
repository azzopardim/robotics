/*
* Arduino JSON library - Parser Example
 * Benoit Blanchon 2014 - MIT License
 */

#include <JsonParser.h>
#define SERIAL_BUFFER_SIZE 256
using namespace ArduinoJson::Parser;

int i=0;
char commandbuffer[256];
char msg[256];
JsonParser<256> parser;

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600); 
}

void processMessage(String message) {
  char chars[128];
  message.toCharArray(chars, 128);

  JsonObject root = parser.parse(chars);

  if (!root.success())
  {
    Serial.println("JsonParser.parse() failed");
    return;
  }
  /*
  char*  sensor    = root["sensor"];
  long   time      = root["time"];
  double latitude  = root["data"][0];
  double longitude = root["data"][1];

  Serial.println(sensor);
  Serial.println(time);
  Serial.println(latitude, 6);
  Serial.println(longitude, 6);
  */
}

void loop()
{
 
  if(Serial1.available()){
        commandbuffer[i] = Serial1.read();
        if (i == 255) {
          Serial.println("Buffer full!");
        }
       
        
        if (commandbuffer[i] == '\n') {
          Serial.println("Terminating character found!");
          Serial.println((char*)commandbuffer);
          i=-1;
        }
        i++;
  }

  //if(i>0)
  //   Serial.println((char*)commandbuffer);
}


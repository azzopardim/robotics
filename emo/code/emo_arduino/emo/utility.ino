// Used for moving average
const int bufferSize = 5;
int buffer[6][bufferSize];
int count = 0;

String toJsonMsg(String attribute, int noOfValues, String value[]) {
  String jsonMsg = "{";
  jsonMsg = jsonMsg+toJsonString("STATUS");
  jsonMsg = jsonMsg+":";
  jsonMsg = jsonMsg+toJsonString(attribute);
  jsonMsg = jsonMsg+",[";
  for (int i = 0; i < (noOfValues*2); i++) {
    if (i != 0) {
        jsonMsg = jsonMsg+",";
    }
    jsonMsg = jsonMsg+toJsonString(value[i]);
    jsonMsg = jsonMsg+":";
    jsonMsg = jsonMsg+toJsonString(value[i+1]);
    ;
    i++;
  }
  jsonMsg = jsonMsg+"]";
  jsonMsg = jsonMsg+"}";
  jsonMsg = jsonMsg+"\n";
  return jsonMsg;
}

String toJsonString(String value){
  String jsonString = "\""+value+"\"";
  return jsonString;
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

int movingAverage(int n,int v) {
  buffer[n][count] = v;
  count++;
  if (count == bufferSize) {
    count = 0;
  }

  int sum = 0;
  for (int i=0; i<bufferSize-1; i++) {
    sum = sum + buffer[n][i];
  }
  int average = sum / bufferSize;
  return average;
}


// Log all status attributes in JSON to be processed by a client 
void logStatus() {
  logProximity();
  logFreeMemory();
}

// Log proximity value
void logProximity() {
  String values[4] = {
    "distance",String(proximityFC),"unit","cm"  };
  serialPrint(1, toJsonMsg("proximity", 2, values));
}

// log proximity of 6 sensors
/*
void logProximitySurround() {
  String values[14] = {
    "ping1",String(proximity1),"ping2",String(proximity2),"ping3",String(proximity3),"ping4",String(proximity4),"ping5",String(proximity5),"ping6",String(proximity6),"unit","cm"  };
  serialPrint(0, toJsonMsg("proximity", 7, values));
}
*/

// Log free memory value
void logFreeMemory() {
  String values[4] = {
    "memory",String(freeMemory()),"unit","bytes"  };
  serialPrint(1, toJsonMsg("proximity", 2, values));
}



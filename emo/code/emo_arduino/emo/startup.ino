// EMO Startup
/**
 * Author : Michael Azzopardi
 * Date: 31 August 2014
 *
 * 
 *
 **/

void startup() {
  serialInit();

  Serial.print("emo Arduino Module starting");
  Serial.print("===========================");
  Serial.print("\n");

  // Initialize LCD
  Serial.println("[STARTUP] Initializing LCD");
  lcdInit();
  lcd.clear();

  Serial.println("[STARTUP] Initializing sequence started");
  lcd.setCursor(0,0);
  lcd.print("emo loading...");

  // Initialize Rings
  Serial.println("[STARTUP] Initializing Rings");
  lcd.setCursor(0,1);
  lcd.print("Init Rings        ");
  ringInit();
  expression = AWAKE;

  // Initialize Ping sensors
  Serial.println("[STARTUP] Initializing Ping Sensors");
  lcd.setCursor(0,1);
  lcd.print("Init Ping Sensor");
  pingInit();

  // Initialize PIR sensor
  Serial.println("[STARTUP] Initializing PIR Sensor");
  lcd.setCursor(0,1);
  lcd.print("Init PIR Sensor ");
  //pirSetup();

  // Initialize PIR sensor
  Serial.println("[STARTUP] Initializing Pan Tilt ");
  lcd.setCursor(0,1);
  lcd.print("Init Pan Tilt ");
  servoInit();

  // Initialize Rover
  Serial.println("[STARTUP] Initializing Rover");
  lcd.setCursor(0,1);
  lcd.print("Init Rover      ");
  roverInit();

  // Initializetion sequence complete
  Serial.println("[STARTUP] Initializing done");
  lcd.setCursor(0,1);
  lcd.print("emo ready");
  lcd.clear();
  //tone(tonePin, 500, 300); 
}


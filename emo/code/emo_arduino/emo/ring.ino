// EMO Neoring
/**
 * Author : Michael Azzopardi
 * Date: 31 August 2014
 *
 * This library provides different light sequence patterns
 * that represent states and emotions for the emo robot.
 * It uses the NeoFruit Pixel Rings
 *
 **/

// NeoRing
const int ringPin_R = 52;
const int ringPin_L = 53;

// Declare NeoPixel Rings
Adafruit_NeoPixel pixelRingLeft = Adafruit_NeoPixel(16, ringPin_L);
Adafruit_NeoPixel pixelRingRight = Adafruit_NeoPixel(16, ringPin_R); 

// Ring colors
const uint32_t GREEN = 0x00FF00;
const uint32_t RED = 0xFF0000;
const uint32_t BLUE = 0x0000FF;
const uint32_t WHITE = 0xFFFFFF;
const uint32_t BLACK = 0x000000;
const uint32_t YELLOW = 0xFFFF00;

// Ring pixels 
// 1st dimension is Ring (0 : Left, 1: Right)
// 2nd dimension is Pixels (0 - 15)
// 3rd dimension is Attribute (0: State (HIGH/LOW), 1: Color)
uint32_t pixels[2][16][2];


// Color attribute TO REMOVE
// uint32_t color  = BLACK; 

// OTHER ######### CHECK IF BEING USED
int l_pixel;
int r_pixel;

uint32_t l_prevpixel;
uint32_t l_prevprevpixel;
uint32_t l_prevprevprevpixel;
uint32_t r_prevpixel;
uint32_t r_prevprevpixel;
uint32_t r_prevprevprevpixel;

// Timing
uint32_t ringStartTime;
uint32_t ringElapseTime;

// Blinking
int blinking = OFF;
boolean blinkOpen = true;
int blinkCount = 0;

// Ring aninmation speen
const uint32_t timing = 50;

// Ring animation direction of LEDs
const int CLOCKWISE= 0;
const int CCLOCKWISE= 1;

// Initializes the rings
void ringInit() {
  // Initializing NeoRing Pixels
  pixelRingLeft.begin();
  pixelRingRight.begin();

  // Set brightness of Neoring
  pixelRingLeft.setBrightness(50); 
  pixelRingRight.setBrightness(50); 

  // Initialize values of pixel state low and color to black
  for (int x=0; x<2; x++) {
    for (int y=0; y<16; y++) {
      pixels[x][y][1] = BLACK;
      pixels[x][y][0] = LOW;
    }
  } 

  // TODO: Decide if this should be here
  rotatingRingInit();
  ringShow();  
}

// Initializes rotating rings
void  rotatingRingInit() {
  r_pixel = 0;
  r_prevpixel = 15;

  l_pixel = 8;
  l_prevpixel = 7;

  // Initialize Timers
  currTime = millis();
  ringStartTime = millis(); 
  ringElapseTime = currTime - ringStartTime;

}

// Main function that sets up common variable values and invokes the corresponding sequence 
void ringExpression() {
  // Invoke function that sets the values of the pixels
  switch (expression) {
  case OFF : 
    ringOff();
    break;
  case ON :
    ringOn();
    break;
  case LOAD :
    //rotatingRing(GREEN, 50, CLOCKWISE);
    break;
  case ALARM :
    //rotatingRing(RED, 10, CCLOCKWISE);
    break;
  case SLEEP :
    ringSleep();
    break;          
  case SMILE : 
    ringSmile();
    break;
  case ANGRY :
    ringAngry();
    break;
  case ARMED :  
    //ringArmed();
    break;
  case DISTANCE :
    ringDistance(proximityFC,min_proximity,max_proximity);
    break;
  case STANDBY :  
    //blinkRing(BLUE,10000);
    break;
  case AWAKE:  
    ringAwake();
    break;
  default :
    ringOff();
  }         

  // Show the pixels on the physical NeoPixel ring
  ringShow();
}

void ringShow() {
  // Set pixel lights based on the defined values 
  for (int y=0; y<16; y++) { 
    pixelRingLeft.setPixelColor(y, pixels[0][y][1]);
    pixelRingRight.setPixelColor(y, pixels[1][y][1]);
  } 

  pixelRingRight.show();
  pixelRingLeft.show();
}

// IMPLEMENTATION OF RING EXPRESSIONS #####################################
// OFF : 
void ringOff() {
  for (int x=0; x<2; x++) {
    for (int y=0; y<16; y++) {
      pixels[x][y][0] = LOW;
      pixels[x][y][1] = BLACK;
    }
  }
}

// OFF : 
void ringOn() {
  // Make all ring white
  for (int x=0; x<2; x++) {
    for (int y=0; y<16; y++) {
      pixels[x][y][0] = HIGH;
      pixels[x][y][1] = WHITE;
    }
  }
}

// SLEEP :
void ringSleep() {
  // Blank all
  ringOff();

  // Make lower half of the ring blue
  for (int x=0; x<2; x++) {
    for (int y=0; y<8; y++) {
      pixels[x][y][0] = HIGH;
      pixels[x][y][1] = BLUE;
    }
  }
}

// SMILE :
void ringSmile() {
  // Blank all
  ringOff();

  // Make lower half of the ring yellow
  for (int x=0; x<2; x++) {
    for (int y=0; y<8; y++) {
      pixels[x][y][0] = HIGH;
      pixels[x][y][1] = YELLOW;
    }
  }
}

// ANGRY :
void ringAngry() {  
  // Blank all
  ringOff();

  // Make upper angle of the ring light red
  for (int x=0; x<2; x++) {
    for (int y=0; y<8; y++) {
      pixels[x][y][0] = HIGH;
      pixels[x][y][1] = RED;
    }
  }
}

// DISTANCE :
void ringDistance(float d, float min_d, float max_d) {
  // Blank all
  ringOff();

  // Calculate the level to show and scale to the level_max value
  int level_max = 16;
  float factor = level_max/(max_d - min_d);
  int level_d = (d-min_d)*factor;
  int level = 16-level_d; 

  // Color ring based on the level with a third of each segment in Green, Yellow and Red
  for (int x=0; x<2; x++) {
    for (int y=0; y<level_max; y++) {
      if ((y < 16/3) && (y < 16*2/3)) {
        pixels[x][y][1]  = GREEN;
      } 
      else if ((y >= level_max/3) && (y < level_max*2/3)) {
        pixels[x][y][1]  = YELLOW;
      } 
      else if  (y >= level_max*2/3) {
        pixels[x][y][1]  = RED;
      }
      if (level >= y) {
        pixels[x][y][0] = HIGH;
      } 
      else {
        pixels[x][y][0] = LOW;
        pixels[x][y][1] = BLACK;
      }
    }
  }
}

// AWAKE :
void ringAwake() {  
  // Blank all
  ringOff();

  // Make upper angle of the ring light red
  // Make lower half of the ring light blue
  for (int x=0; x<2; x++) {
    for (int y=8; y<16; y++) {
      pixels[x][y][0] = HIGH;
      pixels[x][y][1] = BLUE;
    }
  }
}


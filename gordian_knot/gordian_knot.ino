#define SKETCH "gordian_knot.ino"
/*
   Escape room game where the player has to untie a knot of wires.
   The wires are connected to a voltage divider ladder and labeled Red, Green, Blue and Yellow.
   The analog pins are connected to a contact which has an RGB LED next to it.
   When the game starts the target order is shuffled and indicated with the LEDs next to the contacts.
   The object is to move the wires by color to the contacts indicated by the LEDS.

   Future plans:
   There will be timeouts involved.
   No more than two contacts can be broken at any time or the game reshuffles.
   No contacts can be broken for more then x-seconds, or the game reshuffles.
*/

#define FASTLED_INTERNAL  // add this before including FastLED.h. Silences the Pragme message.
#include<FastLED.h>
#include <stdio.h>                      // for function sprintf
#include <EasyButton.h>                 // For debugging button

const uint8_t LED_PIN = 7;
const uint8_t NUM_LEDS = 6;             // There are six LEDs on my test board.

#define COLOR_ORDER RGB
#define BRIGHTNESS  20
#define LED_TYPE WS2811
CRGB leds[NUM_LEDS];                  // Array for the string of LEDS
CRGB colors[] = {CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Yellow, CRGB::Black, CRGB::Black};

static int colorPtr[] = {0, 1, 2, 3};
int targetValue[] = {0, 1, 2, 3};       // Dynamic array, target is the color we want at that position.
int wires[3];                         // Array of the wires connections

static char *colorStr[] = {"red", "grn", "blu", "yel", "low", "-x-"};
char *ledColor[4];                    //Array of the human readable LED colors.

#define BUTTON_PIN 2
EasyButton button(BUTTON_PIN);        // Instance of the button.
// Callback function to be called when the button is pressed.
void onPressed()
{
  Serial.println("Shuffle");
  shuffle_target();
}




//-------------------- Global Values --------------------
/*
  // low-high values. Need for calibration only
  int blueLow = 1023;
  int blueHigh = 0;
  int redLow = 1023;
  int redHigh = 0;
  int greenLow = 1023;
  int greenHigh = 0;
  int yellowLow = 1023;
  int yellowHigh = 0;
*/

int i = 0;

// Initialize the low-high ranges
int vRedLow = 200;
int vRedHigh = vRedLow + 99;
int vGreenLow = 400;
int vGreenHigh = vGreenLow + 99;
int vBlueLow = 600;
int vBlueHigh = vBlueLow + 99;
int vYellowLow = 800;
int vYellowHigh = vYellowLow + 99;


// Analog values
int a0Value;
int a1Value;
int a2Value;
int a3Value;

bool xFlag = false;

//----------------------------------------



//-------------------- setup --------------------
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("--------------------"));
  Serial.println(F(SKETCH));

  // Initialize the button.
  button.begin();
  // callback function to be called when the button is pressed.
  button.onPressed(onPressed);

  randomSeed(analogRead(5));

  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);

  delay(1000);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);



  //Initial colors
  colorBlack();
  shuffle_target();

  showAnalog();
  getWires();                       // Get the wire connections into an array
  showWires();                      // Show the wires array
  showTargetValue();
  mapLeds();
  Serial.println(F("\n--run----------------"));
  delay(2000);

}


//-------------------- loop --------------------
void loop() {
  // Read the status of the button.
  button.read();

  // Read the analog pins to determine which analog input is connected in the voltage divider ladder.
  getAnalog();

  /*
    //Calibration functions
    //showAnalog();
    //showLowHigh();            // Show low-highs
    //showAverage();            // Show the analog pin averages
    //showResult();             // Show which wires are plugged in.
  */


  getWires();                         // Get the wire connections into an array
  //showWires();                        // Show the wires array
  showAllN();                         // show all data



  if (array_cmp(targetValue, wires, 4, 4)) {
    Serial.print(F("MATCH"));
    showMatch();
    leds[5] = CRGB::Green;
    FastLED.show();
  } else {
    Serial.print(F("NO MATCH"));
    showMatch();
    leds[5] = CRGB::Black;
    FastLED.show();
  }


  delay(5);


}

//-------------------- getAnalog --------------------
void getAnalog() {                // Read the voltage divider value on the Analog pins.
  a0Value = analogRead(A0);
  a1Value = analogRead(A1);
  a2Value = analogRead(A2);
  a3Value = analogRead(A3);
}


//-------------------- getWires --------------------
void getWires() {
  // Get the wire connections into an array.
  // The analog pins are connected to the voltage ladder by colored contacts.

  // A0 is the blue wire.
  // When conected to a v contact, the value of the contact color is read.
  if (a0Value > vYellowHigh) wires[0] = 5;                          // Disconnected
  if (a0Value < vRedLow) wires[0] = 4;                              // Low- should never see this
  if (a0Value > vRedLow && a0Value < vRedHigh) wires[0] = 0;        //(Red)
  if (a0Value > vGreenLow && a0Value < vGreenHigh) wires[0] = 1;    //(Green)
  if (a0Value > vBlueLow && a0Value < vBlueHigh) wires[0] = 2;      //(Blue)
  if (a0Value > vYellowLow && a0Value < vYellowHigh) wires[0] = 3;  //(Yellow)

  if (a1Value > vYellowHigh) wires[1] = 5;
  if (a1Value < vRedLow) wires[1] = 4;
  if (a1Value > vRedLow && a1Value < vRedHigh) wires[1] = 0;
  if (a1Value > vGreenLow && a1Value < vGreenHigh) wires[1] = 1;
  if (a1Value > vBlueLow && a1Value < vBlueHigh) wires[1] = 2;
  if (a1Value > vYellowLow && a1Value < vYellowHigh) wires[1] = 3;

  if (a2Value > vYellowHigh) wires[2] = 5;
  if (a2Value < vRedLow) wires[2] = 4;
  if (a2Value > vRedLow && a2Value < vRedHigh) wires[2] = 0; //(Red)
  if (a2Value > vGreenLow && a2Value < vGreenHigh) wires[2] = 1; //(Green)
  if (a2Value > vBlueLow && a2Value < vBlueHigh) wires[2] = 2; //(Blue)
  if (a2Value > vYellowLow && a2Value < vYellowHigh) wires[2] = 3; //(Yellow)

  if (a3Value > vYellowHigh) wires[3] = 5;
  if (a3Value < vRedLow) wires[3] = 4;
  if (a3Value > vRedLow && a3Value < vRedHigh) wires[3] = 0; //(Red)
  if (a3Value > vGreenLow && a3Value < vGreenHigh) wires[3] = 1; //(Green)
  if (a3Value > vBlueLow && a3Value < vBlueHigh) wires[3] = 2; //(Blue)
  if (a3Value > vYellowLow && a3Value < vYellowHigh) wires[3] = 3; //(Yellow)
}


//-------------------- showAnalog --------------------
void showAnalog() {
  // Show the analog pin values
  //static int i = 0;
  char str[64];

  getAnalog();
  //Print every 100 loops
  //i = (i + 1) % 100;
  //if (i == 0) {
  sprintf(str, "Analog: A0:%4d,   A1:%4d,   A2:%4d,   A3:%4d", a0Value, a1Value, a2Value, a3Value);
  Serial.println(str);
  //}
}



//-------------------- showWires --------------------
void showWires() {
  // Show the wires array
  static int i = -1;
  char str[64];

  //Print every 100 loops
  i = (i + 1) % 100;
  if (i == 0) {
    sprintf(str, "Wires: A0:%2d,   A1:%2d,   A2:%2d,   A3:%2d", wires[0], wires[1], wires[2], wires[3]);
    Serial.println(str);
  }
}



/*
  //-------------------- showColorPtr --------------------
  void showColorPtr() {
  // Show the colorPtr array
  static int i = -1;
  char str[64];

  //Print every 1000 loops
  i = (i + 1) % 1000;
  if (i == 0) {
    sprintf(str, "colorPtr[]: %d:%s, %d:%s, %d:%s, %d:%s", colorPtr[0], colorStr[colorPtr[0]], colorPtr[1], colorStr[colorPtr[1]], colorPtr[2],  colorStr[colorPtr[2]], colorPtr[3], colorStr[colorPtr[3]]);
    Serial.println(str);
  }
  }
*/


//-------------------- showTargetValue --------------------
void showTargetValue() {
  // Show the targetValue array
  static int i = -1;
  char str[64];

  //Print every 1000 loops
  i = (i + 1) % 1000;
  if (i == 0) {
    sprintf(str, "targetValue[]: %d:%s, %d:%s, %d:%s, %d:%s", targetValue[0], colorStr[targetValue[0]], targetValue[1], colorStr[targetValue[1]], targetValue[2],  colorStr[targetValue[2]], targetValue[3], colorStr[targetValue[3]]);
    Serial.println(str);
  }
}


//-------------------- showAll --------------------
void showAll() {
  static int i = -1;
  char str1[64];
  char str2[64];
  char str3[64];
  char str4[64];
  char str5[64];

  //Print every 100 loops
  i = (i + 1) % 100;
  if (i == 0) {
    sprintf(str1, "targetValue[]: %d:%s, %d:%s, %d:%s, %d:%s", targetValue[0], colorStr[targetValue[0]], targetValue[1], colorStr[targetValue[1]], targetValue[2],  colorStr[targetValue[2]], targetValue[3], colorStr[targetValue[3]]);
    sprintf(str2, "Wires[]: %s, %s, %s, %s", colorStr[wires[0]], colorStr[wires[1]], colorStr[wires[2]], colorStr[wires[3]]);
    sprintf(str3, "Analog: %4d, %4d, %4d, %4d", a0Value, a1Value, a2Value, a3Value);
    sprintf(str4, "LedColor: %s, %s, %s, %s", ledColor[0], ledColor[1], ledColor[2], ledColor[3]);
    //Serial.print(str1);
    //Serial.print(F("   "));
    Serial.print(str1);             // targetValue
    Serial.print(F("   "));
    Serial.print(str2);           // wires
    Serial.print(F("   "));
    Serial.println(str4);           // LED Colors

  }

}

//-------------------- showAllN --------------------
void showAllN() {
  static int i = -1;
  char str1[64];
  char str2[64];
  char str3[64];

  //Print every 100 loops
  i = (i + 1) % 100;
  if (i == 0) {
    sprintf(str1, "targetValue[]: %d:%s, %d:%s, %d:%s, %d:%s", targetValue[0], colorStr[targetValue[0]], targetValue[1], colorStr[targetValue[1]], targetValue[2],  colorStr[targetValue[2]], targetValue[3], colorStr[targetValue[3]]);
    sprintf(str2, "Wires[]: %d %d %d %d", wires[0], wires[1], wires[2], wires[3]);
    sprintf(str3, "LedColor: %s, %s, %s, %s", ledColor[0], ledColor[1], ledColor[2], ledColor[3]);

    Serial.print(str1);
    Serial.print(F("   "));
    Serial.print(str2);
    Serial.print(F("   "));
    Serial.print(str3);
    Serial.println();
  }

}

//-------------------- showResult --------------------
void showResult() {
  // Function to show which wires are connected to the analog ports.
  // If the analog pin is floating, the reading is greater than 1000
  // due to the pullup in the analog pin init.

  static int i = 0;

  //Show the target ranges:
  if (!xFlag) {
    char str[120];
    sprintf(str, "vRedLow= %4d  vRedHigh= %4d\nvGreenLow= %4d  vGreenHigh= %4d\nvBlueLow= %4d  vBlueHigh= %4d\nvYellowLow= %4d  vYellowHigh= %4d\n", vRedLow, vRedHigh, vGreenLow, vGreenHigh, vBlueLow, vBlueHigh, vYellowLow, vYellowHigh);
    Serial.println(str);
    delay(5000);
    xFlag = true;
  }


  //Print every 100 loops
  i = (i + 1) % 100;
  if (i == 0) {
    if (a0Value > vYellowHigh) Serial.print ("->-, ");
    if (a0Value < vRedLow) Serial.print ("-<-, ");
    if (a0Value > vRedLow && a0Value < vRedHigh) Serial.print ("yel, ");
    if (a0Value > vGreenLow && a0Value < vGreenHigh) Serial.print ("grn, ");
    if (a0Value > vBlueLow && a0Value < vBlueHigh) Serial.print ("red, ");
    if (a0Value > vYellowLow && a0Value < vYellowHigh) Serial.print ("blu, ");

    if (a1Value > vYellowHigh) Serial.print ("->-, ");
    if (a1Value < vRedLow) Serial.print ("-<-, ");
    if (a1Value > vRedLow && a1Value < vRedHigh) Serial.print ("yel, ");
    if (a1Value > vGreenLow && a1Value < vGreenHigh) Serial.print ("grn, ");
    if (a1Value > vBlueLow && a1Value < vBlueHigh) Serial.print ("red, ");
    if (a1Value > vYellowLow && a1Value < vYellowHigh) Serial.print ("blu, ");

    if (a2Value > vYellowHigh) Serial.print ("->-, ");
    if (a2Value < vRedLow) Serial.print ("-<-, ");
    if (a2Value > vRedLow && a2Value < vRedHigh) Serial.print ("yel, ");
    if (a2Value > vGreenLow && a2Value < vGreenHigh) Serial.print ("grn, ");
    if (a2Value > vBlueLow && a2Value < vBlueHigh) Serial.print ("red, ");
    if (a2Value > vYellowLow && a2Value < vYellowHigh) Serial.print ("blu, ");

    if (a3Value > vYellowHigh) Serial.print ("->-, ");
    if (a3Value < vRedLow) Serial.print ("-<-, ");
    if (a3Value > vRedLow && a3Value < vRedHigh) Serial.print ("yel");
    if (a3Value > vGreenLow && a3Value < vGreenHigh) Serial.print ("grn");
    if (a3Value > vBlueLow && a3Value < vBlueHigh) Serial.print ("red");
    if (a3Value > vYellowLow && a3Value < vYellowHigh) Serial.print ("blu");

    Serial.println();
  }
}




//-------------------- colorBlack --------------------
void colorBlack() {
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  leds[5] = CRGB::Black;
  FastLED.show();
}


//------------------- bubbleUnsort --------------------
//Function to unsort an array.
//(Random with no duplicates)

void bubbleUnsort(int *list, int elem)
{
  for (int a = elem - 1; a > 0; a--)
  {
    int r = random(a + 1);
    if (r != a)
    {
      int temp = list[a];
      list[a] = list[r];
      list[r] = temp;
    }
  }
}




//------------------- shuffle_target --------------------
void shuffle_target() {
  //Shuffle the target colors
  for (int i = 0; i < 10; i++) {
    bubbleUnsort(targetValue, 3);
    leds[0] = colors[colorPtr[targetValue[0]]];
    leds[1] = colors[colorPtr[targetValue[1]]];
    leds[2] = colors[colorPtr[targetValue[2]]];
    leds[3] = colors[colorPtr[targetValue[3]]];
    FastLED.show();
    delay(100);
  }
}



//------------------- mapLeds --------------------
//Map the LEDS according to the target values
//The LEDs are co-located with the Analog pins.
//The wires are hard coded with the voltage ladder.

void mapLeds() {
  for (int i = 0; i < 4; i++) {
    if (targetValue[i] == 0) {
      leds[i] = colors[0];  // Red
      ledColor[i] = "Red";
    }
    if (targetValue[i] == 1) {
      leds[i] = colors[1];  // Green
      ledColor[i] = "Grn";
    }
    if (targetValue[i] == 2) {
      leds[i] = colors[2];  // Blue
      ledColor[i] = "Blu";
    }
    if (targetValue[i] == 3) {
      leds[i] = colors[3];  // Yellow
      ledColor[i] = "Yel";
    }
  }

  FastLED.show();

}


//------------------- array_cmp --------------------
//Function to compare two arrays.
boolean array_cmp(int *a, int *b, int len_a, int len_b) {
  int n;
  // if their lengths are different, return false
  if (len_a != len_b) return false;

  // test each element to be the same. if not, return false
  //for (n = 0; n < len_a; n++) if (a[n] != b[n]) return false;
  for (n = 0; n < len_a; n++){
    if (a[n] != b[n]) return false;
  }

  //ok, if we have not returned yet, they are equal :)
  return true;
}



//------------------- showMatch --------------------
// A debug routine to show the matching arrays.
//(Because memcmp doesn't appear to work).
void showMatch() {
  char str1[64];
  char str2[64];

  sprintf(str1, "  wires[]: %d, %d, %d, %d", wires[0], wires[1], wires[2], wires[3]);
  sprintf(str2, "targetValue[]: %d, %d, %d, %d", targetValue[0], targetValue[1], targetValue[2], targetValue[3]);
  Serial.print(str1);
  Serial.print(F("   "));
  Serial.println(str2);
}




/*
  //-------------------- showLowHigh --------------------
  // Used for calibration of the analog pin values.
  void showLowHigh() {
  static int i = 0;
  //Used for calibration.
  //This will show the range of what the analog pins read.

  if (a0Value < blueLow) blueLow = a0Value;
  if (a0Value > blueHigh) blueHigh = a0Value;

  if (a1Value < redLow) redLow = a1Value;
  if (a1Value > redHigh) redHigh = a1Value;

  if (a2Value < greenLow) greenLow = a2Value;
  if (a2Value > greenHigh) greenHigh = a2Value;

  if (a3Value < yellowLow) yellowLow = a3Value;
  if (a3Value > yellowHigh) yellowHigh = a3Value;


  //Print every 100 loops
  i = (i + 1) % 100;
  if (i == 0) {
    char str[120];
    sprintf(str, "A0:%4d-%4d,   A1:%4d-%4d,   A2:%4d-%4d,   A3:%4d-%4d", blueLow, blueHigh, redLow, redHigh, greenLow, greenHigh, yellowLow, yellowHigh);
    Serial.println(str);
  }
  }
*/

/*
  //-------------------- showAverage --------------------
  void showAverage() {
  //Used for calibration.
  //This will show the average of what the analog pins read.

  static int i = 0;

  //Print every 100 loops
  i = (i + 1) % 100;
  if (i == 0) {
    char str[80];
    sprintf(str, "A0= %4d     A1= %4d     A2= %4d     A3= %4d", a0Value, a1Value, a2Value, a3Value);
    Serial.println(str);
  }
  }

*/


/*
  //-------------------- Examples ------------------
  //leds[0] = colors[0];          //Array
  //leds[1] = CRGB( 0, 255, 0);   //RGB
  //leds[2] = 0xFF007F;           //Hex color code
  //leds[3] = CRGB::Yellow;       //HTML colors
  //#define redColor CRGB(Red)    //Define a color
  //leds[1] = redColor            //And use it.
*/

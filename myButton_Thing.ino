//***************************************************************************
//
//  written for the Sparkfun Thing Plus C (p/n SPX-18018)
//
//  In the Arduino IDE, use "ESP32 Dev Module" as the board definition.
//
//***************************************************************************
//
//  This sketch is used to show how to use the BOOT button after the
//  boot process as a general purpose button.
//
//  The blue STAT LED will illuminate after device boot and can be
//  toggled using the BOOT button.
//
//***************************************************************************

const int bootBTNpin  = 0;
const int blueLEDpin  = 13;

int btnState;
int lastButtonState = LOW;
int ledState        = LOW;

unsigned long lastDebounceTime = 0;  // in MS
unsigned long debounceDelay    = 50; // in MS
//****************************************************************************
void setup() {
    
    pinMode(bootBTNpin, INPUT);
    pinMode(blueLEDpin, OUTPUT);

    // Set initial LED state
    
    digitalWrite(blueLEDpin, HIGH);
    
} // END SETUP
//****************************************************************************
void loop() {
    
    // Read the state of the button.
    
    int reading = digitalRead(bootBTNpin);

    // Check to see if the button is pressed (HIGH).    
    
    if (reading != lastButtonState) {
        
        // reset the debouncing timer
        
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        // whatever the reading is at, it's been there for longer
        // than the debounce delay, so take it as the actual current state:

        // Check to see if button state has changed.
        if (reading != btnState) {
            btnState = reading;

            // Toggle the LED if the new button state is HIGH
            if (btnState == HIGH) 
                ledState = !ledState;
         }
  }

     // set the LED:
     digitalWrite(blueLEDpin, ledState);

     // save the reading.  Next time through the loop,
     // it'll be the lastButtonState:
     lastButtonState = reading;
    
}  // END LOOP


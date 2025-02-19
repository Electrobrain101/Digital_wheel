#include <Keyboard.h>

// Define the pins for the 5 reed switches
#define REED_PIN_1 2
#define REED_PIN_2 3
#define REED_PIN_3 4
#define REED_PIN_4 5
#define REED_PIN_5 6

// Debounce delay time (in milliseconds)
#define DEBOUNCE_DELAY 50

// Variables to hold the last state and last debounce time
int lastState1 = HIGH, lastState2 = HIGH, lastState3 = HIGH, lastState4 = HIGH, lastState5 = HIGH;
unsigned long lastDebounceTime1 = 0, lastDebounceTime2 = 0, lastDebounceTime3 = 0, lastDebounceTime4 = 0, lastDebounceTime5 = 0;

void setup() {
  // Initialize serial communication and keyboard
  Serial.begin(9600);
  Keyboard.begin();

  // Set reed switch pins as input with internal pull-up resistors enabled
  pinMode(REED_PIN_1, INPUT_PULLUP);
  pinMode(REED_PIN_2, INPUT_PULLUP);
  pinMode(REED_PIN_3, INPUT_PULLUP);
  pinMode(REED_PIN_4, INPUT_PULLUP);
  pinMode(REED_PIN_5, INPUT_PULLUP);
}

void loop() {
  // Read the reed switches and debounce them
  checkReedSwitch(REED_PIN_1, lastState1, lastDebounceTime1, 'a');  // Send key 'a' for reed switch 1
  checkReedSwitch(REED_PIN_2, lastState2, lastDebounceTime2, 'b');  // Send key 'b' for reed switch 2
  checkReedSwitch(REED_PIN_3, lastState3, lastDebounceTime3, 'c');  // Send key 'c' for reed switch 3
  checkReedSwitch(REED_PIN_4, lastState4, lastDebounceTime4, 'd');  // Send key 'd' for reed switch 4
  checkReedSwitch(REED_PIN_5, lastState5, lastDebounceTime5, 'e');  // Send key 'e' for reed switch 5
}

// Function to check each reed switch and send a keypress if activated
void checkReedSwitch(int reedPin, int &lastState, unsigned long &lastDebounceTime, char key) {
  int currentState = digitalRead(reedPin);

  // If the state has changed and the debounce delay has passed
  if (currentState != lastState) {
    lastDebounceTime = millis();  // Reset debounce timer
  }

  // If the reed switch is activated and debounce delay has passed
  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    // If reed switch is activated (LOW if using pull-up resistor)
    if (currentState == LOW && lastState == HIGH) {
      Serial.print("Reed switch on pin ");
      Serial.print(reedPin);
      Serial.println(" activated.");

      // Send the corresponding keypress
      Keyboard.press(key);
      delay(100);  // Short delay for keypress
      Keyboard.release(key);
    }
  }

  // Save the current state for next comparison
  lastState = currentState;
}
 
# Digital Wheel
This Arduino sketch uses reed switches and the `Keyboard` library to simulate keypresses when the reed switches are activated. The reed switches are connected to digital pins on the Arduino, and each reed switch is associated with a specific key on the keyboard. When a reed switch is triggered (when it changes from HIGH to LOW), the corresponding key is pressed and sent to the computer.

#### Key Features:
- **Reed Switches as Input**: The code monitors five reed switches, each connected to a separate digital pin (2-6).
- **Debouncing**: It includes a debounce mechanism to prevent false readings caused by mechanical noise when the reed switches are toggled.
- **Keyboard Simulation**: When a reed switch is activated, a key (such as 'a', 'b', 'c', etc.) is sent to the computer as if it were typed on a keyboard.
- **Pull-up Resistors**: The reed switches are configured with internal pull-up resistors, so they are normally HIGH and go LOW when activated.

#### How It Works:
1. The reed switches are continuously checked in the `loop()` function.
2. When the state of a reed switch changes (from HIGH to LOW), the debounce timer is reset to avoid multiple triggers.
3. Once the debounce delay passes, the reed switch state is verified and, if activated, the corresponding key is pressed and released.
4. Serial monitoring is enabled to track when a reed switch is activated.

#### Pin Assignments:
- Pin 2 -> Reed switch 1 (key 'a')
- Pin 3 -> Reed switch 2 (key 'b')
- Pin 4 -> Reed switch 3 (key 'c')
- Pin 5 -> Reed switch 4 (key 'd')
- Pin 6 -> Reed switch 5 (key 'e')

#### Technical Notes:
- The `Keyboard` library allows the Arduino to emulate a USB keyboard when connected to a computer.
- Debouncing helps to ensure that the switch triggers only once even if the reed switch is mechanically unstable.
- The sketch includes a `DEBOUNCE_DELAY` constant that can be adjusted to change the debounce time (in milliseconds).

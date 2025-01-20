// Include the DigiKeyboard library
#include "Keyboard.h"

void setup() {
  // Start keyboard emulation after a short delay to give time for the computer to recognize the device
  Keyboard.begin();
  delay(1000);

  // Open the Run window (Windows + R)
  Keyboard.press(KEY_RIGHT_GUI);
  delay(50);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(150);

  // Type
  Keyboard.print("microsoft-edge:https://i.ibb.co/GcnG2sd/hk.png");
  delay(500);

  // Press Enter to open the link, then maximize browser screen
  Keyboard.press(KEY_KP_ENTER);
  delay(250);
  Keyboard.releaseAll();
  delay(550);
  Keyboard.press(KEY_F11);

  delay(250);
  Keyboard.releaseAll();
  // Halt further execution to prevent looping
  while (true) {
    delay(1000); // Keep the device idle
  }
}
void loop() {
  // The loop doesn't need to do anything since the task is complete in setup()
}

void finish() {
  Keyboard.end();
}


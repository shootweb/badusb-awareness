# BadUSB Awareness Example

This repository contains an awareness demonstration of how a BadUSB device can exploit its keyboard emulation functionality to execute predefined commands on a target system. This script, written for Arduino-compatible devices using the DigiKeyboard library, showcases how a malicious USB device can open a URL in the default browser, in this case, displaying an image.

## ⚠️ Disclaimer

This project is strictly for **educational purposes** and to raise awareness about the potential risks of USB devices. Do not use this code for illegal or unethical activities. The misuse of this script is strictly prohibited and the responsibility lies solely with the user.

## How It Works

The script:
1. Simulates keyboard input to open the "Run" dialog (Windows key + R).
2. Enters a URL (`microsoft-edge:https://i.ibb.co/GcnG2sd/hk.png`) to open in Microsoft Edge.
3. Presses "Enter" to execute the command.
4. Maximizes the browser window for emphasis.

## Prerequisites

- An Arduino-compatible microcontroller that supports USB HID, such as:
  - Digispark Attiny85
  - Arduino Leonardo
  - Arduino Micro
- DigiKeyboard library for Arduino (included by default for Digispark devices).

## Code Overview

```cpp
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
  delay(350);
  Keyboard.releaseAll();
  delay(350);
  Keyboard.press(KEY_F11);

  delay(350);
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
```

## Setup Instructions

1. Install the Arduino IDE from [Arduino's official website](https://www.arduino.cc/).
2. Add support for your board (e.g., Digispark).
3. Open the code in the Arduino IDE and upload it to your device.
4. Plug the device into a computer to see the demonstration in action.

## Mitigation Tips

To protect against potential BadUSB attacks:

1. Avoid using untrusted USB devices.
2. Disable USB ports when not in use.
3. Use endpoint security software that monitors USB device activity.
4. Employ a USB condom to block data pins and allow only power delivery.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Acknowledgments

- Inspired by cybersecurity awareness campaigns.
- Uses the DigiKeyboard library to demonstrate USB HID exploits.

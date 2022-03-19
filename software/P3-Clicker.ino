#include "DigiComboKeyboard.h"

const int P0 = 0; // Vol-
const int P1 = 1; // Vol+
const int P2 = 2; // Sleep/Wakeup

bool lastSuspended = false;
unsigned long debounceDelay = 10;

int lastButtonStateP0 = HIGH;
int lastButtonStateP1 = HIGH;
int lastButtonStateP2 = HIGH;

//unsigned long lastDebounceTimeP0 = 0;
//unsigned long lastDebounceTimeP1 = 0;
//unsigned long lastDebounceTimeP2 = 0;

void clickKeyCode(uint16_t keyCode) {
  uint8_t section = keyCode >> 8;
  uint8_t key = keyCode & 0xFF;

  switch (section) {
    case 0xE2:
      DigiComboKeyboard.clickSystemCtrlKey(key);
      break;
    case 0xE4:
      DigiComboKeyboard.clickMultimediaKey(key);
      break;
    case 0xF0:
      DigiComboKeyboard.clickNormalKey(key);
      break;
    default:;
  }
}

void pressKeyCode(uint16_t keyCode) {
  uint8_t section = keyCode >> 8;
  uint8_t key = keyCode & 0xFF;

  switch (section) {
    case 0xE2:
      DigiComboKeyboard.keyDownSystemCtrlKey(key);
      break;
    case 0xE4:
      DigiComboKeyboard.keyDownMultimediaKey(key);
      break;
    case 0xF0:
      DigiComboKeyboard.keyDownNormalKey(key);
      break;
    default:;
  }
}

void releaseKeyCode(uint16_t keyCode) {
  uint8_t section = keyCode >> 8;

  switch (section) {
    case 0xE2:
      DigiComboKeyboard.keyUpSystemCtrlKey();
      break;
    case 0xE4:
      DigiComboKeyboard.keyUpMultimediaKey();
      break;
    case 0xF0:
      DigiComboKeyboard.keyUpNormalKey();
      break;
    default:;
  }
}

void pollUsbStatus() {
  static uint8_t lastSofCount = usbSofCount;
  static unsigned long lastUpdateTime = millis();
  static bool lastSuspended = false;

  uint8_t sofCount = usbSofCount;
  unsigned long currentTime = millis();
  if (sofCount != lastSofCount)
  {
    lastSofCount = sofCount;
    lastUpdateTime = currentTime;
    if (lastSuspended)
    {
      lastSuspended = false;
    }
  }
  else
  {
    if (!lastSuspended)
    {
      if (currentTime - lastUpdateTime >= 15) // USB suspend detected.
      {
        lastSuspended = true;
      }
    }
  }
}

void setup() {
  // init pins mode
  pinMode(P0, INPUT_PULLUP);
  pinMode(P1, INPUT_PULLUP);
  pinMode(P2, INPUT_PULLUP);
}

void loop() {
  pollUsbStatus();

  int reading0 = digitalRead(P0); 
  if (reading0 != lastButtonStateP0) {
    if (reading0 == LOW) {
      pressKeyCode(KEY_MEDIA_VOLUME_DEC);
    } else {
      releaseKeyCode(KEY_MEDIA_VOLUME_DEC);
    }
  }
  lastButtonStateP0 = reading0;

  int reading1 = digitalRead(P1);
  if (reading1 != lastButtonStateP1) {
    if (reading1 == LOW) {
      pressKeyCode(KEY_MEDIA_VOLUME_INC);
    } else {
      releaseKeyCode(KEY_MEDIA_VOLUME_INC);
    }
  }
  lastButtonStateP1 = reading1;

  int reading2 = digitalRead(P2);
  if (reading2 != lastButtonStateP2) {
    if (reading2 == LOW) {
      DigiComboKeyboard.usbRemoteWakeup();
      clickKeyCode(KEY_SYSTEM_SLEEP);
    } else {
    }
  }
  lastButtonStateP2 = reading2;

  DigiComboKeyboard.delay(debounceDelay);
}

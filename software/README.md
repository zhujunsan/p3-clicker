P3 Clicker Firmware
---

Develop using Arduino IDE

1. Install Arduino IDE
2. Follow the instruction in [ArminJo/DigistumpArduino](https://github.com/ArminJo/DigistumpArduino#installation) to add Digistump boards support in Arduino IDE
3. (For Windows user, install [Digispark driver](https://github.com/ArminJo/DigistumpArduino#driver-installation) before upload program)
4. Import Library, Choose DigisparkComboKeyboard.zip
5. Paste content of P3-Clicker.ino into IDE
6. Compile, Upload (plug in/push in device within 60s after compiled, as show in the Arduino IDE console)
7. Done

> Bootloader using config: t85_entry_on_powerOn_
activePullup_fastExit_noLED, which means you can program within the first 300ms after power up the device, so click upload first, wait compile complete, then push the device into position to power up. [more about bootloader config](https://github.com/ArminJo/micronucleus-firmware#configuration-overview)

---

[Click to see more](https://p3-clicker.wulige.com)
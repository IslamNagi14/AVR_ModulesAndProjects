### AVR Modules and Projects

A collection of reusable drivers and small example projects for AVR microcontrollers, mainly ATmega32.
This repository is designed to help beginners and intermediate learners understand how to interface common peripherals using clean and reusable embedded C modules.

📂 Repository Structure
AVR_ModulesAndProjects/
│
├── AVR_Modules/
│   ├── DIO/
│   ├── TIMER/
│   ├── EXTI/
│   ├── ADC/
│   ├── SPI/
│   ├── TWI/
│   ├── UART/
│   ├── blink_led/
│   ├── TWO_LED_usingButton/
│   ├── counter_with_7seg/
│   ├── counter_with2_7seg/
│   ├── snake_effect/
│   └── ... more modules
│
└── README.md


Each module includes:

Source code (.c & .h)

Documentation/comments

Hardware configuration details

Example usage where applicable

🔧 Modules and Their Functions

The repository includes drivers for the most important hardware blocks in AVR MCUs.

### 1️⃣ DIO – Digital Input / Output

Configure pins as INPUT or OUTPUT

Write HIGH/LOW to pins

Read digital signal from pins

Used for buttons, LEDs, relays, digital sensors

2️⃣ TIMER – Timers & PWM

Generate delays without blocking CPU

Output PWM signals (e.g., for motor speed control)

Create periodic interrupts

Measure events or pulses

3️⃣ EXTI – External Interrupt

Configure interrupt-on-change via INT0/INT1/INT2

Trigger functions on button press or sensor edge

No need for continuous polling

4️⃣ ADC – Analog Digital Converter

Converts analog signals (0–5V) into 10-bit digital values (0–1023)

Useful for:

Potentiometers

Light and temperature sensors

Analog modules

5️⃣ SPI – Serial Peripheral Interface

Fast synchronous data communication

Connects to:

EEPROM

Flash memory

Shift registers

Sensors

Another microcontroller

6️⃣ TWI (I²C) – Two-Wire Interface

Communicate with devices using only SDA/SCL

Supports multiple devices on same bus

Works with:

RTC (DS1307)

EEPROM

I²C sensors

I²C LCD modules

7️⃣ UART – Serial Communication

Asynchronous communication via TX/RX

Common uses:

PC serial terminal debugging

GSM, GPS, Bluetooth (HC-05), ESP8266 modules

Microcontroller-to-microcontroller communication

🚀 Example Projects Included
Example	Description
blink_led	Basic LED blinking using DIO
TWO_LED_usingButton	Toggle two LEDs using a button
counter_with_7seg	Counter output to a single 7-segment display
counter_with2_7seg	Tens & units counter displayed on two 7-segment displays
snake_effect	LED “running light/snake” animation
🛠 Getting Started
1️⃣ Clone the repository
git clone https://github.com/IslamNagi14/AVR_ModulesAndProjects.git

2️⃣ Navigate to a module
cd AVR_Modules/<module_name>

3️⃣ Build the project
make

4️⃣ Upload to ATmega32
avrdude -c <programmer> -p m32 -U flash:w:<file>.hex


Replace <programmer> with your programmer name, e.g.:

usbasp

avrisp2

usbisp

📌 Requirements

You should have:

avr-gcc toolchain

avrdude (or compatible programmer software)

ATmega32 or similar MCU

Breadboard, jumper wires, LEDs, resistors, sensors, etc.

USB programmer (e.g., USBasp)

🤝 Contributing

Contributions are welcome!

If adding a new module:

Create a new folder under AVR_Modules/

Include:

.c and .h driver files

Example usage

Hardware notes

Create a clear and descriptive pull request.

📜 License

This project is distributed under the MIT License.
You may use, modify, and distribute freely.

📧 Contact

Author: Islam Nagi
GitHub: https://github.com/IslamNagi14

Feel free to open issues or suggest improvements.
Happy embedded development! 🔌⚙️💡

If you want, I can also:

✔ Generate a version with shields/badges
✔ Auto-generate module lists based on folder contents
✔ Add images/diagrams if you provide them

Just tell me what you want next.

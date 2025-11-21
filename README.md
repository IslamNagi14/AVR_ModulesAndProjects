<!DOCTYPE html>

<h1>AVR Modules and Projects</h1>
<p>A collection of reusable drivers and small example projects for AVR microcontrollers, mainly ATmega32.<br>
This repository is designed to help beginners and intermediate learners understand how to interface common peripherals using clean and reusable embedded C modules.</p>

<h2 class="emoji">📂 Repository Structure</h2>
<pre>
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
</pre>

<p>Each module includes:</p>
<ul>
    <li>Source code (.c &amp; .h)</li>
    <li>Documentation/comments</li>
    <li>Hardware configuration details</li>
    <li>Example usage where applicable</li>
</ul>

<h2 class="emoji">🔧 Modules and Their Functions</h2>
<p>The repository includes drivers for the most important hardware blocks in AVR MCUs.</p>

<h3>1️⃣ DIO – Digital Input / Output</h3>
<ul>
    <li>Configure pins as INPUT or OUTPUT</li>
    <li>Write HIGH/LOW to pins</li>
    <li>Read digital signal from pins</li>
    <li>Used for buttons, LEDs, relays, digital sensors</li>
</ul>

<h3>2️⃣ TIMER – Timers &amp; PWM</h3>
<ul>
    <li>Generate delays without blocking CPU</li>
    <li>Output PWM signals (e.g., for motor speed control)</li>
    <li>Create periodic interrupts</li>
    <li>Measure events or pulses</li>
</ul>

<h3>3️⃣ EXTI – External Interrupt</h3>
<ul>
    <li>Configure interrupt-on-change via INT0/INT1/INT2</li>
    <li>Trigger functions on button press or sensor edge</li>
    <li>No need for continuous polling</li>
</ul>

<h3>4️⃣ ADC – Analog Digital Converter</h3>
<ul>
    <li>Converts analog signals (0–5V) into 10-bit digital values (0–1023)</li>
    <li>Useful for:
        <ul>
            <li>Potentiometers</li>
            <li>Light and temperature sensors</li>
            <li>Analog modules</li>
        </ul>
    </li>
</ul>

<h3>5️⃣ SPI – Serial Peripheral Interface</h3>
<ul>
    <li>Fast synchronous data communication</li>
    <li>Connects to:
        <ul>
            <li>EEPROM</li>
            <li>Flash memory</li>
            <li>Shift registers</li>
            <li>Sensors</li>
            <li>Another microcontroller</li>
        </ul>
    </li>
</ul>

<h3>6️⃣ TWI (I²C) – Two-Wire Interface</h3>
<ul>
    <li>Communicate with devices using only SDA/SCL</li>
    <li>Supports multiple devices on same bus</li>
    <li>Works with:
        <ul>
            <li>RTC (DS1307)</li>
            <li>EEPROM</li>
            <li>I²C sensors</li>
            <li>I²C LCD modules</li>
        </ul>
    </li>
</ul>

<h3>7️⃣ UART – Serial Communication</h3>
<ul>
    <li>Asynchronous communication via TX/RX</li>
    <li>Common uses:
        <ul>
            <li>PC serial terminal debugging</li>
            <li>GSM, GPS, Bluetooth (HC-05), ESP8266 modules</li>
            <li>Microcontroller-to-microcontroller communication</li>
        </ul>
    </li>
</ul>

<h2 class="emoji">🚀 Example Projects Included</h2>
<table>
    <thead>
        <tr>
            <th>Example</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>blink_led</td>
            <td>Basic LED blinking using DIO</td>
        </tr>
        <tr>
            <td>TWO_LED_usingButton</td>
            <td>Toggle two LEDs using a button</td>
        </tr>
        <tr>
            <td>counter_with_7seg</td>
            <td>Counter output to a single 7-segment display</td>
        </tr>
        <tr>
            <td>counter_with2_7seg</td>
            <td>Tens &amp; units counter displayed on two 7-segment displays</td>
        </tr>
        <tr>
            <td>snake_effect</td>
            <td>LED “running light/snake” animation</td>
        </tr>
    </tbody>
</table>

<h2 class="emoji">🛠 Getting Started</h2>
<ol>
    <li>Clone the repository
        <pre>git clone https://github.com/IslamNagi14/AVR_ModulesAndProjects.git</pre>
    </li>
    <li>Navigate to a module
        <pre>cd AVR_Modules/&lt;module_name&gt;</pre>
    </li>
    <li>Build the project
        <pre>make</pre>
    </li>
    <li>Upload to ATmega32
        <pre>avrdude -c &lt;programmer&gt; -p m32 -U flash:w:&lt;file&gt;.hex</pre>
        Replace <code>&lt;programmer&gt;</code> with your programmer name, e.g.: usbasp, avrisp2, usbisp
    </li>
</ol>

<h2 class="emoji">📌 Requirements</h2>
<ul>
    <li>avr-gcc toolchain</li>
    <li>avrdude (or compatible programmer software)</li>
    <li>ATmega32 or similar MCU</li>
    <li>Breadboard, jumper wires, LEDs, resistors, sensors, etc.</li>
    <li>USB programmer (e.g., USBasp)</li>
</ul>

<h2 class="emoji">🤝 Contributing</h2>
<p>Contributions are welcome!<br>
If adding a new module:
<ul>
    <li>Create a new folder under <code>AVR_Modules/</code></li>
    <li>Include: .c and .h driver files, example usage, hardware notes</li>
    <li>Create a clear and descriptive pull request</li>
</ul>
</p>

<h2 class="emoji">📜 License</h2>
<p>You may use, modify, and distribute freely.</p>

<h2 class="emoji">📧 Contact</h2>
<p>
    Author: Islam Nagi<br>
    GitHub: <a href="https://github.com/IslamNagi14">https://github.com/IslamNagi14</a><br>
    Feel free to open issues or suggest improvements.<br>
    Happy embedded development! 🔌⚙️💡
</p>

</body>
</html>

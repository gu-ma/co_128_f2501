# TouchDesigner-Firmata Interface

This repository contains files for interfacing TouchDesigner with Arduino using the Firmata protocol. This setup allows for bidirectional communication between TouchDesigner and Arduino, enabling physical computing projects that combine Arduino's sensor/actuator capabilities with TouchDesigner's powerful visual programming environment.

## Contents

- `Touchdesigner_firmata_base.toe` - Base TouchDesigner file with Firmata implementation
- `StandardFirmata.ino` - Arduino sketch to enable Firmata protocol communication

## Requirements

- [TouchDesigner](https://derivative.ca/) (tested with recent versions)
- [Arduino IDE](https://www.arduino.cc/en/software)
- Arduino-compatible board (e.g., Uno, Nano, Mega)
- USB (Data!) cable for Arduino connection

## Setup

### Installing Firmata Library

1. Open the Arduino IDE
2. Go to **Sketch > Include Library > Manage Libraries...**
3. In the Library Manager, search for "Firmata"
4. Find "Firmata by Firmata Developers" and click Install
5. Wait for the installation to complete

### Arduino Setup

1. Connect your Arduino board to your computer via USB
2. Open the Arduino IDE
3. Open the `StandardFirmata.ino` sketch 
   - If you don't have the sketch, you can find it in **File > Examples > Firmata > StandardFirmata**
4. Select your Arduino board type under Tools > Board
5. Select the correct port under Tools > Port
6. Upload the StandardFirmata sketch to your Arduino

### TouchDesigner Setup

1. Open TouchDesigner
2. Open the `Touchdesigner_firmata_base.toe` file
3. Locate the Firmata DAT component in the project
4. Update the serial port setting to match your Arduino's port
   - Common ports are:
     - Windows: COM3, COM4, etc.
     - macOS: /dev/cu.usbmodem1411 (or similar)
     - Linux: /dev/ttyACM0 (or similar)
5. After connecting, you should see successful communication status in the Firmata component

## Usage

### Reading Arduino Inputs in TouchDesigner

The base file is configured to read digital and analog inputs from the Arduino:

1. Digital inputs will appear as channels in the designated output DAT
2. Analog inputs (A0-A5 on most Arduinos) will be scaled to 0-1 range
3. Connect these values to parameters in your TouchDesigner network

### Controlling Arduino Outputs from TouchDesigner

You can control Arduino's pins from TouchDesigner:

1. Digital outputs: Set HIGH/LOW states for LEDs, relays, etc.
2. PWM outputs: Control brightness, motor speed, etc. with analog values
3. Servo motors: Control position of servo motors

### Example Use Cases

- Physical interfaces for interactive installations
- Sensor data visualization
- Light and motor control for kinetic sculptures
- DIY MIDI controllers or interfaces
- IoT projects with visual feedback

## Customization

### Adding More Sensors

To add additional sensors to your Arduino:

1. Connect the sensor to appropriate Arduino pins
2. In TouchDesigner, configure the Firmata component to read from those pins
3. Process and use the data in your TouchDesigner network

### Adding More Outputs

To control additional outputs:

1. Connect LEDs, motors, or other actuators to Arduino output pins
2. In TouchDesigner, send values to those pins using the Firmata protocol

## Troubleshooting

- **No communication**: Verify serial port settings and that Firmata is properly uploaded
- **No Serial received by TouchDesigner**: Close the Arduino Serial Monitor and try again (only one serial connection can be open at a time)
- **Incorrect readings**: Check sensor wiring and pin configurations
- **Delayed response**: Adjust the polling rate in TouchDesigner Firmata settings
- **TouchDesigner crashes**: Ensure all connections are stable and reduce data throughput if necessary

## Additional Resources

- [TouchDesigner Documentation](https://derivative.ca/UserGuide/Palette%3Afirmata)
- [Firmata Protocol Information](https://github.com/firmata/protocol)
- [Arduino Reference](https://www.arduino.cc/reference/en/)

## License

This project uses the GNU Lesser General Public License (LGPL 2.1) as included in the LICENSE.txt file.

## Contributing

Feel free to fork this repository and submit pull requests for improvements or additional features.

## Credits

The StandardFirmata sketch is part of the Firmata library developed by:
- Hans-Christoph Steiner
- Paul Stoffregen
- Shigeru Kobayashi
- Jeff Hoefs

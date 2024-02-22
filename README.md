# NPK-7-in-1
RS485 Soil NPK PH Sensor, 7-in-1 Multi‑Parameter Sensor with PH NPK Temperature and Humidity EC Sensor
# NPK 7-in-1 Soil Sensor Project

## Description
This project involves interfacing an Arduino Uno with the NPK 7-in-1 Soil Sensor to measure various soil parameters including moisture content, temperature, electrical conductivity, pH level, nitrogen, phosphorus, and potassium. The Arduino and soil sensor communication is established using the RS485 communication protocol.

## Circuit Diagram
![Circuit Diagram]([link_to_your_circuit_diagram_image](https://github.com/momar82/NPK-7-in-1/blob/main/aa.png))

## Components
- Arduino Uno
- NPK 7-in-1 Soil Sensor
- RS485 Module
- Power Supply (5V DC)

## Installation
1. Connect the Arduino Uno to the RS485 module according to the circuit diagram.
2. Connect the RS485 module to the NPK 7-in-1 Soil Sensor.
3. Power up the Arduino and the soil sensor.
4. Upload the provided Arduino code to the Arduino Uno.

## Usage
1. Open the Arduino IDE and upload the code to the Arduino Uno.
2. Open the serial monitor to view the sensor readings.
3. The sensor readings for moisture content, temperature, electrical conductivity, pH level, nitrogen, phosphorus, and potassium will be displayed on the serial monitor.

## Troubleshooting
- Double-check the wiring connections between the Arduino, RS485 module, and NPK 7-in-1 Soil Sensor if you encounter communication errors.
- Ensure that the Modbus settings (baud rate, parity, etc.) in the Arduino code match the soil sensor settings.
- Check for proper power supply to the components and ensure they receive sufficient power.

## Contributing
Contributions to improve the project are welcome! Feel free to open an issue or create a pull request if you have any suggestions, bug fixes, or enhancements.

## License
This project is licensed under the [MIT License](LICENSE).

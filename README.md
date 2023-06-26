# auto-irrigation
# Arduino Uno Autopowering System

The Arduino Uno Autopowering System is a project that utilizes an Arduino Uno microcontroller to automate the powering of a device based on soil moisture levels. This system can be used for applications such as automated plant watering, where the device (e.g., a water pump) is turned on or off based on the soil moisture readings.

## Features

- Monitors soil moisture levels using a moisture sensor.
- Supports automatic and manual modes of operation.
- Utilizes an MQTT (Message Queuing Telemetry Transport) protocol for communication with an MQTT broker.
- Publishes the soil moisture percentage to an MQTT topic.
- Listens to MQTT messages to control the operation mode and power state of the device.

## Getting Started

### Hardware Requirements

- Arduino Uno board.
- Moisture sensor.
- Water pump or any device to be powered.
- Ethernet shield or module (compatible with Arduino Uno).
- Ethernet cable and network connection.

### Software Requirements

- Arduino IDE (Integrated Development Environment).
- Libraries:
  - Arduino.h
  - SPI.h
  - Ethernet.h
  - PubSubClient.h

### Circuit Connection

1. Connect the moisture sensor to the Arduino Uno analog pin.
2. Connect the water pump or device to be powered to the specified digital pin (POMP) on the Arduino Uno.
3. Connect the Ethernet shield or module to the Arduino Uno.

### Installing Libraries

1. Open the Arduino IDE.
2. Go to "Sketch" -> "Include Library" -> "Manage Libraries".
3. Search for each library name mentioned in the code and click "Install" for each library.

### Uploading the Code

1. Open the Arduino IDE.
2. Connect the Arduino Uno to your computer via USB.
3. Open the provided code file (`autopowering_system.ino`) in the Arduino IDE.
4. Click on the "Upload" button to upload the code to the Arduino Uno.

### Configuring MQTT Broker

1. Replace the MQTT broker address, port, credentials, and other required details in the code with your own MQTT broker information.

### Running the System

1. Power up the Arduino Uno.
2. The system will connect to the MQTT broker and subscribe to the required topics.
3. The moisture sensor will continuously monitor the soil moisture level.
4. Based on the configured mode (automatic or manual) and the moisture level, the device will be powered on or off accordingly.
5. The system will publish the moisture percentage to the specified MQTT topic at regular intervals.

## Contributing

Contributions to the Arduino Uno Autopowering System project are welcome! If you have any ideas, suggestions, or improvements, please feel free to open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).


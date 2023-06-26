# Arduino Uno Autopowering System

🌱 This project utilizes an Arduino Uno microcontroller to automate the powering of a device based on soil moisture levels. The system can be used for applications such as automated plant watering, where the device (e.g., a water pump) is turned on or off based on the soil moisture readings.

![Schematic](schematic.png)

## Features

- ✅ Monitors soil moisture levels using a moisture sensor.
- ✅ Supports automatic and manual modes of operation.
- ✅ Utilizes the MQTT (Message Queuing Telemetry Transport) protocol for communication with an MQTT broker.
- ✅ Publishes the soil moisture percentage to an MQTT topic.
- ✅ Listens to MQTT messages to control the operation mode and power state of the device.

## Getting Started

### Hardware Requirements

- 🔌 Arduino Uno board.
- 🌧️ Moisture sensor.
- 💦 Water pump or any device to be powered.
- 🌐 Ethernet shield or module (compatible with Arduino Uno).
- 🔌 Ethernet cable and network connection.

### Software Requirements

- ⚙️ PlatformIO (open-source ecosystem for IoT development).
- 📂 [Ethernet library](https://www.arduino.cc/en/Reference/Ethernet) - Built-in library in PlatformIO.
- 📂 [PubSubClient library](https://pubsubclient.knolleary.net/) - Install via PlatformIO Library Manager.

### Circuit Connection

1. Connect the moisture sensor to the Arduino Uno analog pin.
2. Connect the water pump or device to be powered to the specified digital pin (POMP) on the Arduino Uno.
3. Connect the Ethernet shield or module to the Arduino Uno.

### Uploading the Code

1. Open the PlatformIO project for the Arduino Uno Autopowering System.
2. Place the `main.cpp` file provided in the `src` folder of the PlatformIO project.
3. Make sure the required libraries are mentioned in the `platformio.ini` file.
4. Connect the Arduino Uno to your computer via USB.
5. Build and upload the code to the Arduino Uno using the PlatformIO environment.

### Configuring MQTT Broker

1. Replace the MQTT broker address, port, credentials, and other required details in the code with your own MQTT broker information.

### Running the System

1. Power up the Arduino Uno.
2. The system will connect to the MQTT broker and subscribe to the required topics.
3. The moisture sensor will continuously monitor the soil moisture level.
4. Based on the configured mode (automatic or manual) and the moisture level, the device will be powered on or off accordingly.
5. The system will publish the moisture percentage to the specified MQTT topic at regular intervals.

## Contributing

🤝 Contributions to the Arduino Uno Autopowering System project are welcome! If you have any ideas, suggestions, or improvements, please feel free to open an issue or submit a pull request.

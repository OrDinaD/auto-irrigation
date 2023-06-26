// This code is for an Arduino Uno-based autopowering system.

#include <Arduino.h>

// Variable declarations
int soilMoistureValue = 0;
int percentage = 0;
int Level = 0;
bool Onf = true;
bool isAuto = true;
long int prevMillis = 0;
byte mac[] = {0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xE3};

// MQTT topics
const char Topic[] = "AutoPoliv";
const char Topic2[] = "wattered";
const char Topic3[] = "Automode";
const char Topic4[] = "WateState";

// MQTT callback for WateState topic
void callbackWateState(char *topic, byte *payload, unsigned int length)
{
  // Print received message
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Store the message in a variable
  String message = "";
  for (int i = 0; i < length; i++)
  {
    message += (char)payload[i];
  }

  // Check the topic and update the Level variable
  if (strcmp(topic, "WateState") == 0)
  {
    Level = message.toInt();
  }
}

// MQTT callback for Automode topic
void callbackAutomode(char *topic, byte *payload, unsigned int length)
{
  // Create a string from the payload
  String data_pay;
  for (int i = 0; i < length; i++)
  {
    data_pay += String((char)payload[i]);
  }

  // Print the received data
  Serial.println(data_pay);

  // Handle different modes based on the received data
  if (String(topic) == "Automode")
  {
    if (data_pay == "auto")
    {
      isAuto = true;
      Serial.println("Auto mqtt");
    }
    if (data_pay == "manual")
    {
      isAuto = false;
      Onf = true;
      Serial.println("manual mqtt");
    }
    if (data_pay == "off")
    {
      isAuto = false;
      Onf = false;
      Serial.println("OFF manual mqtt");
    }
  }
}

EthernetClient ethClient;
PubSubClient client("YOUR_SERVER", YOUURPORT, callbackWateState, ethClient); //writ SERVER and PORT

// MQTT connection function
void reconnect()
{
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266-texstjhghghg";
    if (client.connect("arduinoClient", "USER", "PASSWORD")) //write USER and PASSWORD
    {
      Serial.println("connected");

      // Subscribe to Automode topic
      client.subscribe("Automode");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup()
{
  // Initialize serial communication
  Serial.begin(9600);
  Serial.print("start");

  // Initialize Ethernet connection
  Ethernet.init(10);
  Ethernet.begin(mac);

  // Set POMP pin as output
  pinMode(POMP, OUTPUT);
}

void loop()
{
  if (!client.connected())
  {
    // Reconnect if not connected to MQTT broker
    reconnect();
  }

  // Publish percentage value to wattered topic at regular intervals
  if (millis() - prevMillis > 20000)
  {
    client.publish("wattered", ((String)percentage).c_str());
    prevMillis = millis();
  }

  // Process MQTT messages
  client.loop();

  // Read soil moisture value and calculate percentage
  soilMoistureValue = analogRead(What);
  percentage = map(soilMoistureValue, 0, 750, 0, 100);

  // Perform actions based on system mode and moisture level
  if (isAuto == true)
  {
    delay(1500);
    if (percentage < 20)
    {
      Serial.println("pump on");
      delay(500);
      digitalWrite(POMP, 0);
    }
    if (percentage > Level)
    {
      Serial.println("pump off");
      delay(500);
      digitalWrite(POMP, 1);
    }
  }
  if (isAuto == false && Onf == true)
  {
    Serial.println("pump manual on");
    delay(500);
    digitalWrite(POMP, 0);
  }
  if (isAuto == false && Onf == false)
  {
    Serial.println("pump manual off");
    delay(500);
    digitalWrite(POMP, 1);
  }
}

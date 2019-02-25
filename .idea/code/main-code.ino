/* This file is run on ESP32 board, with a soil moisture sensor connected to the pin 32, and a relay with water pump connected to pin 14.
   This file is a modified version from the "wifi-connection" file.
   Codes related to soil sensor and relay are added.
   There are three main parts in this file.
   Part 1 is in setup(), it is mainly about defining variables and connecting to wifi to build TCP between ESP32 and a smart phone.
   Part 2 is in first half of loop(), it is mainly about client(ESP32) sending messages from soil sensor to server(smart phone).
   Part 3 is in second half of loop(), it is mainly about server(smart phone) sending messages to client(ESP32) to control the water pump.
 */

/*
 * TCP/IP communication ESP8266WiFi
 * Copyright (C) 2017 http://www.projetsdiy.fr - https://www.diyprojects.io
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* ----------------------------------------------
    Part 1: Define variables and connect to wifi.
   ---------------------------------------------- */

#include <WiFi.h>
long sensor_value;                           // define a variable for soil sensor
int pinRelay = 14;                           // define pin 14 as the relay pin
int pinSensor = 32;                          // define pin 32 as the soil sensor pin
const char* ssid = "wifi_name";              // SSID, input the wifi name
const char* password = "wifi_password";      // Password, input the wifi password
const char* host = "server_ip_address";      // IP serveur - Server IP address
const int   port = 8080;                     // Port serveur - Server Port, a port that server and client agree on
const int   watchdog = 5000;                 // Fréquence du watchdog - Watchdog frequency
unsigned long previousMillis = millis(); 

void setup() {
  pinMode(pinRelay,OUTPUT);                  // define the relay pin as the output pin
  Serial.begin(115200);                      // set the baud rate
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);                // connect to wifi
  while (WiFi.status() != WL_CONNECTED) {    // keep connecting to wifi until it is connected
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");            // print the IP address of the wifi module(client)
  Serial.println(WiFi.localIP());
}

void loop() {

/* -------------------------------------------
    Part 2: Client sending messages to server.
   ------------------------------------------- */

  unsigned long currentMillis = millis();

  if ( currentMillis - previousMillis > watchdog ) {
    previousMillis = currentMillis;
    WiFiClient client;
  
    if (!client.connect(host, port)) {       // connect the client to the server
      Serial.println("connection failed");
      return;
    }

    sensor_value = analogRead(pinSensor);//collect the analog signal and pass the value

    // Envoi la requete au serveur - This will send the information to the server according to the value of the soil sensor
    // When the value of sensor is above 3500, it means the plant is lack of water.
    if (sensor_value > 3500){
      client.print(String("The dryness is (") + sensor_value + String("/4095), your plant needs some water. Send 'on' to turn on the water pump."));}
    else {
      client.print(String("The dryness is (") + sensor_value + String("/4095), your plant is in good condition."));}
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        return;
      }
    }

/* -------------------------------------------
    Part 3: Server sending messages to client.
   ------------------------------------------- */

    // Data that sent by server to give a command to control the water pump
    // When the server send an "on" to the client, the water pump will be turned on for 5 second.
    while(client.available()){
      String line = client.readStringUntil('\r');
      Serial.print(line);
      if (line=="on") {
        digitalWrite(pinRelay,HIGH);
        delay(5000);
        digitalWrite(pinRelay,LOW);
      }else{
        Serial.print("off");
      }
    }
  }
}

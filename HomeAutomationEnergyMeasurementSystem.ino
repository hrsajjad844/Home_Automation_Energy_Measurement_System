#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include "global.h"
#include "function.h"
#include "setup.h"

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients
  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();         
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // Device 1
            if (header.indexOf("GET /D1/on") >= 0) {
              Serial.println("Device 1 on");
              output1State = "on";
              digitalWrite(output1, HIGH);
            } else if (header.indexOf("GET /D1/off") >= 0) {
              Serial.println("Divice 1 off");
              output1State = "off";
              digitalWrite(output1, LOW);
            } 

            //Device 2
            else if (header.indexOf("GET /D2/on") >= 0) {
              Serial.println("Device 2 on");
              output2State = "on";
              digitalWrite(output2, HIGH);
            } else if (header.indexOf("GET /D2/off") >= 0) {
              Serial.println("Divice 2 off");
              output2State = "off";
              digitalWrite(output2, LOW);
            } 


            //Device 3

            else if (header.indexOf("GET /D3/on") >= 0) {
              Serial.println("Device 3 on");
              output3State = "on";
              digitalWrite(output3, HIGH);
            } else if (header.indexOf("GET /D3/off") >= 0) {
              Serial.println("Divice 3 off");
              output3State = "off";
              digitalWrite(output3, LOW);
            } 

            //Device 4

            else if (header.indexOf("GET /D4/on") >= 0) {
              Serial.println("Device 4 on");
              output4State = "on";
              digitalWrite(output4, HIGH);
            } else if (header.indexOf("GET /D4/off") >= 0) {
              Serial.println("Divice 4 off");
              output4State = "off";
              digitalWrite(output4, LOW);
            } 
            
            #include "htmlpage.h"
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
 
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}

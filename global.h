const char* ssid     = "SHAWON";
const char* password = "mehedi299";
int time1, time2, time3,time4;


// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output1State = "off";
String output2State = "off";
String output3State = "off";
String output4State = "off";

// Assign output variables to GPIO pins
const int output1 = 5;
const int output2 = 4;
const int output3 = 0;
const int output4 = 2;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

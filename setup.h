
void setup() {
  EEPROM.begin(512);  //Initialize EEPROM
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(output3, OUTPUT);
  pinMode(output4, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output1, LOW);
  digitalWrite(output2, LOW);
  digitalWrite(output3, LOW);
  digitalWrite(output4, LOW);


  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();

if(EEPROM.read(0)!=1){
  //Clean EEPROM
  for (int i = 0; i < 500; i++) {
    EEPROM.write(i, 0);
  }

  //Set EEPROM initial value
  EEPROM.write(1, '0');
  EEPROM.write(2, '*');

  EEPROM.write(101, '0');
  EEPROM.write(102, '*');
  
   EEPROM.write(201, '0');
  EEPROM.write(202, '*');

  EEPROM.write(301, '0');
  EEPROM.write(302, '*');

  EEPROM.write(0,1);
}

time1 = eepromValueRead(1);
time2 = eepromValueRead(101);
time3 = eepromValueRead(201);
time4 = eepromValueRead(301);

//Setup timer
  noInterrupts();                                // Switch off interrupts whilst they are set up
  timer0_isr_init();                             // Initialise Timer0
  timer0_attachInterrupt(ISR);                   // Goto the ISR function below when an interrupt occurs
  timer0_write(ESP.getCycleCount() + 80000000L); // Pre-load timer with a time value (1-second)
  interrupts();  

}

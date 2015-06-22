void initH() {
   dht.begin();
  }
  
  void displayH() {

   // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  
   #ifdef DEBUG;
      Serial.print("Humidity = ");
      Serial.println(h);
      Serial.print("TempH = ");
      Serial.println(t);
   #endif
   
  }

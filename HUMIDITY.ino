void initH() {
   dht.begin();
  }
  
  void displayH() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
   #ifdef DEBUG;
      Serial.print("Humidity = ");
      Serial.println(h);
      Serial.print("TempH = ");
      Serial.println(t);
   #endif
   
   setSeg(GAUCHE, h, 0, 100, TEAL);
   setSeg(DROITE, t, 15, 35, YELLOW); 

  }

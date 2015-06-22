void displayPT() {

 unsigned long pressure ;//= bmp.readPressure();
  int temp ;//= int(bmp.readTemperature() * 10);
//
 byte toLightP = map(pressure, 95000, 105000, 1, 32);

 #ifdef DEBUG;
 
      Serial.print("pressure = ");
      Serial.println(pressure);
      Serial.print("toLightP = ");
      Serial.println(toLightP);
      #endif
      
//  for (int i = 121; i <= (121 + toLightP); i++) {
//    strip.setLEDcolorPWM(i, 4, 10, 7);
//  }
//
//  for (int i = 121 + toLightP + 1; i <= 152; i++) {
//    strip.setLEDcolorPWM(i, 0, 0, 0);
//  }
//
 byte toLightT = map(temp, 0, 300, 1, 32);
 
 #ifdef DEBUG;
 Serial.print("temp = ");
      Serial.println(temp);
      Serial.print("toLightT = ") ;
      Serial.println(toLightT) ;
      
      #endif
      
      
//  for (int i = 305; i >= (305 - toLightT); i--) {
//    strip.setLEDcolorPWM(i, 4, 10, 7);
//  }
//
//  for (int i = 305 - toLightT - 1; i >= 273; i++) {
//    strip.setLEDcolorPWM(i, 0, 0, 0);
//  }

}

void initPT() {
  bmp.begin();
  }

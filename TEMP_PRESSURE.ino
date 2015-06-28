void displayPT() {

 unsigned long pressure ;//= bmp.readPressure();
  int temp ;//= int(bmp.readTemperature() * 10);

 byte toLightP = map(pressure, 95000, 105000, 1, 32);

// #ifdef DEBUG;
// 
//      Serial.print("pressure = ");
//      Serial.println(pressure);
//      Serial.print("toLightP = ");
//      Serial.println(toLightP);
//      #endif
     
// byte toLightT = map(temp, 0, 300, 1, 32);
// 
// #ifdef DEBUG;
// Serial.print("temp = ");
//      Serial.println(temp);
//      Serial.print("toLightT = ") ;
//      Serial.println(toLightT) ;
//      
//      #endif
      
     

}

void initPT() {
  //bmp.begin();
  }

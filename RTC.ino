void initRTC() {
  
  Wire.begin();
  rtc.begin();

  if (!rtc.isrunning()) {
    
    #ifdef DEBUG
    Serial.println("RTC is NOT running!");
    #endif
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    
  }
    
  

    #ifdef DEBUG
    Serial.println("RTC running!");
    #endif

  }
  
  

void displayTime() {

  updateTime();

setSeg(BAS, now.second(), 0, 59, BLUE);
setSeg(GAUCHE, now.hour(), 0, 31, GREEN);
setSeg(HAUT, now.minute(), 0, 59, TEAL);

  
}


void updateTime() {

  now = rtc.now();

    #ifdef DEBUG
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
    #endif

}

void initRTC() {
  
  //  Wire.begin();
//  rtc.begin();
//
//  if (!rtc.isrunning()) {
//    
//    #ifdef DEBUG
//    Serial.println("RTC is NOT running!");
//    #endif
//    
//    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
//
//  }



  }
  
  

void displayTime() {
//
//  updateTime();
//
//  for (int i = 1; i < 120; i++) {
//
//    if (i <= now.second()) strip.setLEDcolorPWM(i, 4, 10, 7);
//    else strip.setLEDcolorPWM(i, 0, 0, 0);
//
//  }
}


void updateTime() {

  now = rtc.now();

}

void initLED() {
  
  strip.setPWMbits(3);
  strip.setSPIdivider(64);
  strip.setCPUmax(90);
  strip.begin();


  }
  
  
 void colorSwirl() {
   
 static uint8_t j=0;
   
      for (uint8_t i=0; i< strip.numLEDs() ; i++) {
     uint16_t c = Wheel((i+j) % 96);
     // the 16 bit color we get from Wheel is actually made of 5 bits RGB, we can use bitwise notation to get it out and
     // convert it to 8 bit
     strip.setLEDcolorPWM(i, (c & 0x1F) << 3, ((c>>10) & 0x1F) << 3, ((c>>5) & 0x1F) << 3);
  }
  
  j++;
  // there's only 96 colors in the 'wheel' so wrap around
  if (j > 96) { j = 0; }
  delay(100);
  
   }
   
unsigned int Color(byte r, byte g, byte b)
{
  //Take the lowest 5 bits of each value and append them end to end
  return( ((unsigned int)g & 0x1F )<<10 | ((unsigned int)b & 0x1F)<<5 | (unsigned int)r & 0x1F);
}

   
unsigned int Wheel(byte WheelPos)
{
  
  byte r,g,b;
  switch(WheelPos >> 5)
  {
    case 0:
      r=31- WheelPos % 32;   //Red down
      g=WheelPos % 32;      // Green up
      b=0;                  //blue off
      break; 
    case 1:
      g=31- WheelPos % 32;  //green down
      b=WheelPos % 32;      //blue up
      r=0;                  //red off
      break; 
    case 2:
      b=31- WheelPos % 32;  //blue down 
      r=WheelPos % 32;      //red up
      g=0;                  //green off
      break; 
  }
  return(Color(r,g,b));
}

void setLEDOFF() {
  for (int i = 1; i <=LED_QUANTITY;i++) strip.setLEDcolorPWM(i, 0, 0, 0);
}

void setAllLED(int r, int g,int b) {
  for (int i = 1; i <=LED_QUANTITY;i++) strip.setLEDcolorPWM(i, r, g, b);
}

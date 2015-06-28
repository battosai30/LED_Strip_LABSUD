byte measureLight() {

  unsigned long measure = 0;

  analogRead(A7);

  for (int i = 0; i < 10; i++)    measure += analogRead(A7);
  
#ifdef DEBUG  
Serial.print(" Light = ");
Serial.println(measure / 10.0);
#endif

  return measure / 10.0 > LIGHT_LIMIT ;

}

void displayLight() {
  
unsigned long measure = 0;

analogRead(A7);

for (int i = 0; i < 10; i++)    measure += analogRead(A7);
  
setSeg(HAUT, measure/10.0, 150, 700, TEAL);
  
//   byte n=map(measure /10.0,150,700,92,151);
//    for(int i=92;i<=151;i++) {
//         if (i<=n) strip.setLEDcolor(i, TEAL);
//    else strip.setLEDcolor(i, 0);
//     }
//     
//   strip.writeStrip();
     
  }

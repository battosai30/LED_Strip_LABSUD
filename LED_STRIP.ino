
void setSeg(byte seg, int value, int low, int high, byte color) {

  char invert = 1;

  if (seg == BAS || seg == DROITE) invert = -1;

  byte ledl, ledh;

  switch (seg) {

    case BAS :
      ledl = 59;
      ledh = 0;
      break;

    case HAUT :
      ledl = 92;
      ledh = 151;
      break;

    case GAUCHE :
      ledl = 60;
      ledh = 91;
      break;

    case DROITE :
      ledl = 183;
      ledh = 152;
      break;

  }

  byte n = map(value, low, high, ledl, ledh);

  for (int i = ledl; (i * invert) <= (ledh * invert); i += invert) {
    
    if ((i * invert) < (n * invert)) strip.setLEDcolor(i, color);
    else strip.setLEDcolor(i, 0);
    
  }

  strip.writeStrip();

}



void setLEDOFF(byte mode) {
  for (int i = 0; i < LED_QUANTITY; i++)    strip.setLEDcolor(i, 0);
  if (mode) strip.writeStrip();
}

void setAllLED(byte r) {
  for (int i = 0; i < LED_QUANTITY; i++)     strip.setLEDcolor(i, r);
  strip.writeStrip();
}

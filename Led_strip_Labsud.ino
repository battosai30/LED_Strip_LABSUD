#include <DHT.h>
#include "HL1606stripPWM.h"
#include <Wire.h>
#include "RTClib.h"
#include <Adafruit_BMP085.h>

#define DEBUG

#define BOUTON 3
#define HUMIDITY 2
#define LED_QUANTITY 304
#define DHTTYPE DHT21

DHT dht(HUMIDITY, DHTTYPE);

RTC_DS1307 rtc;
DateTime now;

Adafruit_BMP085 bmp;

byte lightControl=1;

int latchPin = 10;

HL1606stripPWM strip = HL1606stripPWM(LED_QUANTITY, latchPin);

void setup() {

  #ifdef DEBUG
  Serial.begin(9600);
  Serial.println("hello!");
 #endif
 
 pinMode(BOUTON,INPUT_PULLUP);
 
initRTC();
initLED();
initPT();  
initH();

}

void loop() {
 
static byte k=0;
  
if(digitalRead(BOUTON)==0) {
  
  if(++k>2) k=0;
  while(digitalRead(BOUTON)==0);
  delay(100);
  
}

if((measureLight() && lightControl==1) || lightControl==0) {

switch (k) {
    
    case 0:
    
      #ifdef DEBUG;
      Serial.println("Mode = ColorSwirl");
      #endif
      
      colorSwirl();
    
    break;
    
    case 1:
    
    #ifdef DEBUG;
      Serial.println("Mode = Environnement Sensor");
      #endif
      
      displayPT();
      displayH();
      
    break;
    
    case 2:
    
    #ifdef DEBUG;
      Serial.println("Mode = Time");
      #endif
      
      displayTime();
      
    break;
    
    default:
    break;
    
    }
  }

}





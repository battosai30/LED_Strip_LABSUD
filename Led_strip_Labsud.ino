#include "DHT.h" // librairie capteur humidite/temperature
#include "HL1606strip.h" // librairie controle bandeaue led
#include <Wire.h> // librairie i2c necessaire pour horloge temps reel
#include "RTClib.h" // librairie horloge temps reel
//#include <Adafruit_BMP085.h> //librairie capteur de pression/temperature
#include "HL1606stripPWM.h"

#define DEBUG // def pour choisir si debug serie ou non

#define BOUTON 2 // pin bouton
#define SOUND A0 // pin bouton
#define HUMIDITY 3 // pin capteur humidité
#define LED_QUANTITY 184
#define DHTTYPE DHT21 // type capteur humidite/temperature

#define LIGHT_LIMIT 150 // limite luminosité avant extinction

DHT dht(HUMIDITY, DHTTYPE); // instanciation capteur d'humditie/temperature

enum led_segment{
  GAUCHE = 0,
  DROITE,
  HAUT,
  BAS
};

RTC_DS1307 rtc; //instanciation horloge temps réel DS1307
DateTime now; //variable pour stocker date

//Adafruit_BMP085 bmp; // instanciation capteur de pression

HL1606strip strip = HL1606strip(11, 10, 13, 184); // instanciation bandeau de led

int latchPin = 10;
HL1606stripPWM stripPWM = HL1606stripPWM(LED_QUANTITY, latchPin); 

byte k = 0;
byte lightControl = 1; // variable pour controle automatique allumage en fontion de la luminosité ambiante

void setup() {

#ifdef DEBUG
  Serial.begin(9600);
  Serial.println("hello!");
#endif

  pinMode(BOUTON, INPUT_PULLUP); // bouton facade


  initRTC(); // initialisation de l'horloge temps réel
  initPT(); // intialisation capteur pression/temperature BMP180
  initH(); // initialisation capteur humidite/temperature
  initPWM();


}

void loop() {

  bouton(); // bouton appuye ? 

  if (((measureLight() && lightControl == 1) || lightControl == 0)&& digitalRead(SOUND)==HIGH) { // control automoatique de la luminosite (pas assez de lumière ambiante = on eteint)

    static unsigned long timeref=millis();
    static int y=0;
    static int i=0;
    static int decalage=0;

    switch (k) { // en fonction de k, pilotee par bouton(), on affiche une fonction definie

    case 0: // mode horloge temps reel

      displayTime();

      break;

    case 1: // mode capteurs ambiants

      displayPT();
      displayH();

      break;

    case 2: // mode capteur de lumière

      displayLight();

      break;

    case 3 :

      if(millis()>=(timeref+50)) {

        timeref=millis();
        decalage++;
        if(decalage>=10) decalage=0;

        for(i=0;i<LED_QUANTITY;i++) {

          y=i%10;
          
          
          if (y<5) {
            strip.setLEDcolor(i+decalage, RED);
          } 
          else if (y<10) {

            strip.setLEDcolor(i+decalage,black);

          } else y=0;

        }
        
        strip.writeStrip();
        
      }

      break;

    case 4 :

      if(millis()>=(timeref+200)) {

        timeref=millis();

        for(i=0;i<LED_QUANTITY;i++) {
          strip.setLEDcolor(i,y?BLACK:RED);
        }

        y=!y;
        
        strip.writeStrip();     
      }

      break;

    case 5 :

      //rainbowParty(20);
      
      swirl();
      
      break;

    default:
      break;

    }

    //delay(100);

  } 
  else {
    setLEDOFF(1); // si pas assez de lumière on Eteint tout
    delay(100);
  }
}

void bouton() {

  if (digitalRead(BOUTON) == LOW) { // si bouton appuye
  
  if (++k > 5) k = 0; // on incremente k de 1, si elle depasse 2 on retourne à 0
  
if(k==5) stripPWM.begin();
else stripPWM.end();
    
    setLEDOFF(0); // on efface tout
    while (digitalRead(BOUTON) == LOW); // tant que le bouton est appuye, on attend
    delay(100); // permet d'eviter les effets de rebond
  }
}



#include "../Class/SoundsMusic.h"
#include "../Class/ConversionIllum.h"
#include "../Class/MeasureTime.h"
#include "../Class/Security.h"

float darknessCriterion = 0.05;
bool passwordAttention = false;
int passwordNumber = 5;
int button = 0;
int count = 0;
int flag = 0;
bool done = false;

ConversionIllum iilum = ConversionIllum(0);
SoundsMusic music = SoundsMusic(7);
Security security = Security(count);

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(13, INPUT);
}

void loop() {
  button = digitalRead(13);
  count = security.count;

  Serial.print("count:");
  Serial.println(count);
  flag = security.buttonFlag(flag, button);
  passwordAttention = security.password(count ,passwordNumber);

  iilum.convertVolt();
  iilum.convertResistance();
  iilum.convertIlluminance();
//   iilum.illumPrint();

  illuminationHandler(iilum.volt, darknessCriterion, passwordAttention);
//   Serial.println("-------------------------------------------");

}

void illuminationHandler (float illuminance, float criterion, bool flag) {
  if (illuminance < criterion) {
     Serial.println("Dark");
     done = false;
   } else if(flag == false && illuminance > criterion && done == true) {
     Serial.println("Success");
   } else if (illuminance > criterion && flag == false) {
     Serial.println("Light");
     music.falseBuzzer();
   } else if (illuminance > criterion && flag == true){
     Serial.println("Light");
     music.dragonQuest();
     done = true;
     passwordAttention = false;
     count = 0;
   }
}

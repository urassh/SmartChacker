#include "./Class/SoundsMusic.h"
#include "./Class/ConversionIllum.h"
#include "./Class/MeasureTime.h"

float darknessCriterion = 0.05;
bool passwordAttention = false;
int passwordNumber = 5;
int button = 0;
int count = 0;
int flag = 0;
bool done = false;

ConversionIllum iilum = ConversionIllum(0);
SoundsMusic music = SoundsMusic(7);

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(13, INPUT);
}

void loop() {
  button = digitalRead(13);
  Serial.print("count:");
  Serial.println(count);
  flag = buttonFlag();
  passwordAttention = password(count ,passwordNumber);

  iilum.convertVolt();
  iilum.convertResistance();
  iilum.convertIlluminance();
//   iilum.illumPrint();

  illuminationHandler(iilum.volt, darknessCriterion, passwordAttention);
//   Serial.println("-------------------------------------------");

}

void buttonFlag() {
  if(flag == 0 && button == 1){
    count++;
    return 1;
  } else if (flag == 1 && button == 0){
    return 0;
  }
}

void password(int input, int password) {
  if(input == password) {
    return true;
  } else {
    return false;
  }
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


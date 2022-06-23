#include "Arduino.h"
#include "../Class/MeasureTime.h"
#include "../Class/SoundsMusic.h"

MeasureTime::MeasureTime(int pin, int target, int time) {
    pinNumber = pin;
    targetTime = target;
    spendTime = time;
    bool ring = false;
    pinMode(pinNumber, OUTPUT);
}

void MeasureTime::complete(void) {
    SoundsMusic music = SoundsMusic(7);
    if (targetTime == spendTime) {
        ring = true;
        Serial.println("時間切れです。");
        Serial.println("お疲れ様でした。");
        if (ring == true) {
            music.dragonQuest();
            ring = false;
        }
        
    } else {
        spendTime -= 1;
        Serial.print("経過時間は : ");
        Serial.print(spendTime);
        Serial.println("です。");
        
    }
    delay(1000);
}

#include "Arduino.h"
#include "../Class/Security.h"

Security::Security(int number) {
    count = number;
}

Security::buttonFlag(int flag, int button) {
    if(flag == 0 && button == 1){b
        count++;
        return 1;
    } else if (flag == 1 && button == 0){
        return 0;
    }
}

Security::password(int input, int password){
    if(input == password) {
        return true;
    } else {
        return false;
    }
}
#include <stdio.h>
#include <string.h>

int DAS(const char* number) {
    int state = 0; // Stan reprezentują resztę z dzielenia przez 3
    for (int i = 0; i < strlen(number); ++i) {
        int bit = number[i] - '0'; // znak na cyfrę
        switch(state){
          case 0:
            if (bit == 1) state = 1;
            break;
          case 1:
            if (bit == 1) state = 0;
            else state = 2;
            break;
          case 2:
            if (bit == 0) state = 1;
            break;
        }
    }
    return state == 0;
}

int main() {
    char number[7][10] = {
      "1100",       //(12)+
      "11",         //(3)+
      "1011",       //(11)-
      "1001",       //(9)+
      "1010",       //(10)-
      "1110011",    //(115)-
      "100101100",  //(300)+

    };

    for (int i = 0; i < sizeof(number)/sizeof(number[0]); i++) {
        if (DAS(number[i])) {
            printf("+ | Liczba binarna '%s' jest podzielna przez 3.\n", number[i]);
        } else {
            printf("- | Liczba binarna '%s' nie jest podzielna przez 3.\n", number[i]);
        }
    }

    return 0;
}

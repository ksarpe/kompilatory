#include <stdio.h>
#include <string.h>

int DAS(const char* word) {
    int state = 0;
    for (int i = 0; i < strlen(word); i++) {
        switch(state) {
            case 0:
                if (word[i] == 'a') state = 1;
                break;
            case 1:
                if (word[i] == 'b') state = 2;
                break;
            case 2:
                if (word[i] == 'a') state = 1;
                break;
            default:
                break;
        }
    }
    return state == 2;
}

int main() {
    char words[6][20] = {
      "aaabbbbabbab", //+
      "bbaa",         //-
      "ababab",       //+
      "baba",         //-
      "bab",          //+
      "bbb",          //-
    };

    for (int i = 0; i < sizeof(words)/sizeof(words[0]); i++) {
        if (DAS(words[i])) {
            printf("+ | Slowo '%s' jest akceptowane.\n", words[i]);
        } else {
            printf("- | Slowo '%s' nie jest akceptowane.\n", words[i]);
        }
    }
    return 0;
}

/**
 * DATA ART
 */

#include "headfirst.h"
#include "data_art.h"

bool AskYesOrNo(char * msg){
    bool answer = false;

    return answer;
}

char * justifyCenter(char * str, int msgLength) {
    int length = msgLength * sizeof(char)+1;
    char * msg = malloc(length);

    char * format = malloc(length);
    sprintf(format, "%%%ds%s", (msgLength/2 + strlen(str)/2) + (msgLength%2), makeSpaceStr(msgLength/2 - strlen(str)/2));
    sprintf(msg,format,str);

    return msg;
}

char * intToStr(int Integer){
    char * str = malloc(digitCount(Integer) * sizeof(char) + 1);
    sprintf(str, "%d", Integer);
    return str;
}

int digitCount(int digit){

    int counter = 0;
    if(digit < 0){
        digit *= -1;
    }
    while(digit){
        digit /= 10;
        counter++;
    }

    return counter;
}

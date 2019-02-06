#include <stdio.h>
#include <ctype.h>

void main(){

    char ch;
    printf("enter text (a period to end) \n");
    while(ch = getchar(), ch !='.'){ // the , is similar to "and".
        if (islower(ch)){
            ch = toupper(ch);
        }else{
            ch = tolower(ch);
        }
        putchar(ch);
    }

}
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
char encrypt(char ch, int k);
//argc = argument count, argv = argument vector, argv[0] = program name
//Caesar Ciphers
void main(int argc, char* argv[]){
    int choice, key;
    char ch;
    FILE *fin, *fout;

    if(argc != 5){
        printf("you fucked up");
        exit(1);
    }

    choice = atoi(argv[1]);
    key = atoi(argv[2]);

    if(choice == 2){
        key = -key;
    }

    fin = fopen(argv[3], "r");
    fout = fopen(argv[4], "w");

    if(fin == NULL || fout == NULL){
        printf("Fucked up again");
        exit(1);
    }

    while(fscanf(fin, "%c", &ch) != EOF){
        fprintf(fout, "%c", encrypt(ch, key));
    }

    fclose(fin);
    fclose(fout);

    return 0;
}

char encrypt(char ch, int k){
    if(k > 0){
        k = k + 26;
    }

    if(isupper(ch)){
        return (ch - 'A' + k) % 26 + 'A';
    }

    if(islower(ch)){
        return (ch - 'a' + k) % 26 + 'a';
    }

    return ch;
}

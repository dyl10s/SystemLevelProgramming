#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// search the first n characters in array list for character target
// return true if it is found, and false otherwise
int found(char list[], int n, char target);

// initialize the encrypt array with appropriate cipher letters according to the given key
void initializeEncryptArray(char key[], char encrypt[]);

// initialize the decrypt array with appropriate substitute letters based on the encrypt array
void initializeDecryptArray(char encypt[], char decrypt[]);

// process text from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[]);

void main(int argc, char* argv[]){

    char encrypt[26];
    char decrypt[26];
    int option;
    //get option and key
    FILE *fin, *fout;

    if(argc != 5){
        printf("This program takes more arguements");
        exit(1);
    }
    
    option = atoi(argv[1]);
    char* key = argv[2];

    fin = fopen(argv[3], "r");
    fout = fopen(argv[4], "w");

    //open input and output files
    initializeEncryptArray(key, encrypt);
    initializeDecryptArray(encrypt, decrypt);
    
    //This is for encryption
    if(option == 1){
        processInput(fin, fout, encrypt);
    }else{ // This is for decryption
        initializeDecryptArray(encrypt, decrypt);
        processInput(fin, fout, decrypt);
    }
}

int found(char list[], int n, char target){

    int cur = 0;

    while(list[cur] != NULL){
        if(cur >= n){
            return 0;
        }

        if(list[cur] == target){
            return 1;
        }
        cur+=1;
    }
}

void initializeEncryptArray(char key[], char encrypt[]){

    //Copy key to encrypt array, and eliminate duplicates
    int keyLength = strlen(key);
    int size = 0;

    for(int i = 0; i < keyLength; i++){
        char nextInput = key[i];
        int hasFound = found(encrypt, size, nextInput);

        if(hasFound == 0){
            encrypt[size] = nextInput;
            size++;
        }
    }

    //Add rest of alphabet in reverse
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for(int i = 25; i >= 0; i--){
        char nextInput = alphabet[i];
        int hasFound = found(encrypt, size, nextInput);

        if(hasFound == 0){
            encrypt[size] = nextInput;
            size++;
        }
    }

}

void initializeDecryptArray(char encrypt[], char decrypt[]){

    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for(int i = 0; i < 26; i++){
        int location = encrypt[i] - 'a';
        decrypt[location] = alphabet[i];
    }

}

void processInput(FILE * inf, FILE * outf, char substitute[]){

    char ch;
    while(fscanf(inf, "%c", &ch) != EOF){
        if(isupper(ch)){
            fprintf(outf, "%c", substitute[ch - 'A']);
        }else if(islower(ch)){
            fprintf(outf, "%c", substitute[ch - 'a']);
        }else{
            fprintf(outf, "%c", ch);
        }
    }

}

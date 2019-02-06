#include <stdio.h>
#include <ctype.h>

void main()
{
    int x[5] = {0, 1, 2, 3, 4};
    int arraySize = sizeof(x) / sizeof(x[0]);

    for(int i = 0; i < arraySize; i++){
        printf("%d \n", x[i]);
    }

    printf("Calculated array size: %d \n", arraySize);
}
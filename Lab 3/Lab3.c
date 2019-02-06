#include <stdio.h>
#include <string.h>

int found (char list[], int n, char ch);

int main ()
{
	char key[20], list[26];
	int i, size;
    size = 0;
	// Part One (Required) - Prompt the user for a word and read  
	// the user input into array key as a string
    printf("Please enter a string: \n");
	scanf("%s", key);



	// Part Two (Required) - Copy each letter in array key into array
	// list if it is not found there 
	// Use variable size to keep track of the number of letters copied 
	 for(int i = 0; i < strlen(key); i++){
        if(found(list, size, key[i]) == 0) {
            list[size] = key[i];
            size++;
        }   
     }



	// Part Three (Optional) - Fill up the rest of array list with 
	// other letters in the alphabet in reverse order 
	
	


	// Display all letters in array list

	for ( i=0; i < size; i++ )
	   printf("%c", list[i]);
	printf("\n");

	return 0;
}

// search the first n characters in array list for character target
// return true if it is found, and false otherwise
 
int found(char list[], int n, char target) 
{
	int i;
	for (i=0; i<n; i++)
	   if (list[i] == target)
	      return 1;
	return 0;
}
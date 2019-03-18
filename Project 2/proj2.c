#include "list.h"
#include <stdio.h>

void moveFinder(char* finder, char next);

void main(int argc, char *argv[]) {
	FILE *input;
	LINK list = makeEmpty();

	if (argc != 2) {
		printf("This application takes 1 command line argument");
		exit(0);
	}

	input = fopen(argv[1], "r");

	char *c;
	c = malloc(1);

	char storage[1000] = "";
	char finder[3] = "";

	int commentedMultiline = FALSE;
	int commentedSingleLine = FALSE;
	int inQuotes = FALSE;
	int importName = FALSE;

	while (fgets(c, 2, input) != NULL) {
		
		moveFinder(&finder, c[0]);

		if (strcmp(finder, "/*") == 0) {
			commentedMultiline = TRUE;
		}

		if (strcmp(finder, "*/") == 0) {
			commentedMultiline = FALSE;
		}

		if (strcmp(finder, "//") == 0) {
			commentedSingleLine = TRUE;
		}

		if (finder[1] == '\n') {
			commentedSingleLine = FALSE;
		}

		if (finder[1] == '"') {
			if (inQuotes == FALSE) {
				inQuotes = TRUE;
			}
			else {
				inQuotes = FALSE;
			}
		}

		if (commentedSingleLine == FALSE && commentedMultiline == FALSE && inQuotes == FALSE && importName == FALSE) {
			//If the character is not a letter, underscore, or number
			if (isalpha(c[0]) == 0 && isdigit(c[0]) == 0 && c[0] != '_') {
				if (strlen(storage) > 0) {
					addValue(storage, 1, list);
					storage[0] = '\0';
				}
			}
			else {
				if (c[0] != '\t') {
					if (strlen(storage) == 0) {
						if (isalpha(c[0]) != 0) {
							strcat(storage, c);
						}
					}
					else {
						strcat(storage, c);
					}
				}	
			}
		}	

	}

	showList(list);
	system("pause");
}

void moveFinder(char* finder, char next) {
	if (strlen(finder) == 2) {
		finder[0] = finder[1];
		finder[1] = next;
	}
	else if (strlen(finder) == 1){
		finder[1] = next;
	}
	else if (strlen(finder) == 0) {
		finder[0] = next;
	}
}

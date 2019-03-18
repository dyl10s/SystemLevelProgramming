#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

typedef struct Node* LINK;
struct Node {
	char* word;
	int count;
	LINK next;
};

LINK makeEmpty();
int isEmpty(LINK head);
int isFull(LINK head);
int deleteFirst(LINK head);
int insertAsFirst(char* d, LINK head);
int insertAsFirstWithValue(char* d, int count, LINK head);
int removeValue(char* value, LINK head);
int search(char* value, LINK head);
int addValue(char* value, int add, LINK head);
void clear(LINK head);
void showList(LINK head);
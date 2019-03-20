#include "list.h"

LINK makeEmpty()
/* creates an empty list */
{
	LINK head = (LINK)malloc(sizeof(struct Node));
	head->next = NULL;
	head->word = '\0';
	return head;
}

int isEmpty(LINK head)
/* returns true if the list is empty */
{
	return (head->next == NULL);
}


int isFull(LINK head)
/* returns true if the list is full */
{
	return FALSE;
}

int deleteFirst(LINK head)
/* removes the first element from the list and
   returns true if the operation is done successfully */
{
	LINK temp;
	if (isEmpty(head))
		return FALSE;
	temp = head->next;
	head->next = temp->next;
	free(temp);
	return TRUE;
}

int removeValue(char* value, LINK head)
/* removes the first found from the list based off of the search and
   returns the value if the operation is done successfully */
{	
	while (!isEmpty(head)) {
		if (strcmp(head->next->word, value) == 0) {
			int tempValue = head->next->count;
			free(head->next);
			head->next = head->next->next;
			
			return tempValue;
		}
		else {
			head = head->next;
		}
	}

	return FALSE;
}

int search(char* value, LINK head)
/* returns the value of an item with the given search. Then moves it to the front. */
{
	int tempValue = removeValue(value, head);
	if (tempValue != FALSE) {
		insertAsFirstWithValue(value, tempValue, head);
		return tempValue;
	}
	else {
		return FALSE;
	}
}

int addValue(char* value, int add, LINK head) {
	if (search(value, head) != FALSE) {
		head->next->count+=1;
		return TRUE;
	}
	else {
		insertAsFirst(value, head);
		return TRUE;
	}

	return FALSE;
}

int insertAsFirst(char* value, LINK head)
/* inserts an element as the first of the list and
   returns true if the operation is done successfully */
{
	LINK temp = (LINK)malloc(sizeof(struct Node));
	temp->word = malloc(strlen(value));
	strcpy(temp->word, value);
	temp->count = 1;
	temp->next = head->next;
	head->next = temp;
	return TRUE;
}

int insertAsFirstWithValue(char* value, int count, LINK head)
/* inserts an element as the first of the list with a specific value and
   returns true if the operation is done successfully */
{
	LINK temp = (LINK)malloc(sizeof(struct Node));
	temp->word = malloc(strlen(value));
	strcpy(temp->word, value);
	temp->count = count;
	temp->next = head->next;
	head->next = temp;
	return TRUE;
}

void clear(LINK head)
/* makes the list empty */
{
	int temp;
	while (!isEmpty(head))
		deleteFirst(head);
}

void showList(LINK head)
/* displays all elements in the list */
{
	LINK curr = head->next;
	while (curr != NULL) {
		printf("%s : %d  \n", curr->word, curr->count);
		curr = curr->next;
	}
	printf("\n");
}

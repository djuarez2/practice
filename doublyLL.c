/*
 * Doubly linked list
 * Written by: Daniel Juarez
 *
 * Description: An implementation of a doubly linked
 * list done for practice.
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node *prev;
	struct node *next;
	int key;
} node_t;

node_t *createNode(int);
void insertNode(node_t **, int);
void insertNewHead(node_t **, int);
void deleteNode(node_t **, int);
void displayList(node_t *);

int main(void)
{
	node_t *list = NULL;

	insertNode(&list, 100);
	insertNode(&list, 5);
	insertNode(&list, 67);
	insertNode(&list, 1);
	displayList(list);

	insertNewHead(&list, 5);
	insertNewHead(&list, 6);
	insertNewHead(&list, 834);
	displayList(list);

	deleteNode(&list, 834);
	displayList(list);

	deleteNode(&list, 100);
	displayList(list);

	deleteNode(&list, 1);
	displayList(list);

	return 0;
}

node_t *createNode(int inputKey)
{
	node_t *newNode = (node_t *)malloc(sizeof(node_t));

	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->key =inputKey;

	return newNode;
}

void insertNode(node_t **inputList, int inputKey)
{
	node_t **tempNode = inputList;
	node_t *newNode = createNode(inputKey);
	node_t *previous = NULL;

	while (*tempNode != NULL) {
		previous = *tempNode;
		tempNode = &(*tempNode)->next;
	}

	newNode->prev = previous;
	*tempNode = newNode;
}

void insertNewHead(node_t **inputList, int inputKey)
{
	node_t **tempNode = inputList;
	node_t *newNode = createNode(inputKey);

	(*tempNode)->prev = newNode;
	newNode->next = *tempNode;
	*tempNode = newNode;
}

void deleteNode(node_t **inputList, int searchKey)
{
	node_t **tempNode = inputList;
	node_t *previous = NULL;
	node_t *temp;

	while (*tempNode != NULL && (*tempNode)->key != searchKey) {
		previous = *tempNode;
		tempNode = &(*tempNode)->next;
	}

	if (*tempNode == NULL) {
		puts("value not found");
	} else {
		temp = *tempNode;
		*tempNode = (*tempNode)->next;
		free(temp);
		temp = NULL;
		if (*tempNode != NULL)
			(*tempNode)->prev = previous;
	}
}

void displayList(node_t *inputList)
{
	printf("list: ");
	if (inputList == NULL)
		printf("empty");
	else
		while (inputList != NULL) {
			printf("%d ", inputList->key);
			inputList = inputList->next;
		}
	printf("\n");
}


// Linked List

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

void insert(int value);

void insertOnIndex(int value, int index);

void deleteNode(int index);

void print(void);

void release();

typedef struct node 
{
	int value;
	struct node* nextNodePtr; 
} NODE;

NODE* startNodePtr = NULL;



int main(void)
{
	int input = 0;
	int OnLoop = 1;
	int value = 0;
	int index = 0;
	while (OnLoop == 1)
	{
		printf("\n<Menu>\n");
		printf("1.insert node\n");
		printf("2.insert node at certain index\n");
		printf("3.delete node at certain index \n");
		printf("4.print\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("input int value : ");
			scanf(" %d", &value);
			insert(value);
			break;
		case 2:
			printf("input int value and index : ");
			scanf(" %d %d", &value, &index);
			insertOnIndex(value, index);
			break;
		case 3:
			printf("input index to delete node : ");
			scanf(" %d", &index);
			deleteNode(index);
			break;
		case 4:
			print();
			break;
		default:
			OnLoop = 0;
			break;
		}
	}
	release();
	
	_CrtDumpMemoryLeaks();

	return 0;
}

void insert(int value)
{
	NODE* currentNodePtr = NULL;
	NODE* newNodePtr = NULL;

	newNodePtr = (NODE*)malloc(sizeof(NODE));
	if (newNodePtr == NULL)
		return;
	newNodePtr->value = value;
	newNodePtr->nextNodePtr = NULL;

	if (startNodePtr == NULL)
	{
		startNodePtr = newNodePtr;
	}
	else if (startNodePtr->nextNodePtr)
	{
		currentNodePtr = startNodePtr->nextNodePtr;
		while (currentNodePtr->nextNodePtr != NULL)
		{
			currentNodePtr = currentNodePtr->nextNodePtr;
		}
		currentNodePtr->nextNodePtr = newNodePtr;
	} 
	else
	{
		startNodePtr->nextNodePtr = newNodePtr;
	}

}


void insertOnIndex(int value, int index)
{
	NODE* currentNodePtr = NULL;
	NODE* nextNodePtr = NULL;
	NODE* newNodePtr = NULL;
	int counter = 0;

	newNodePtr = (NODE*)malloc(sizeof(NODE));
	if (newNodePtr == NULL)
		return;
	newNodePtr->value = value;
	newNodePtr->nextNodePtr = NULL;

	currentNodePtr = startNodePtr;
	
	while (counter != index)
	{
		currentNodePtr = currentNodePtr->nextNodePtr;
		counter++;
	}
	nextNodePtr = currentNodePtr->nextNodePtr;
	currentNodePtr->nextNodePtr = newNodePtr;
	newNodePtr->nextNodePtr = nextNodePtr;
}

void deleteNode(int index)
{
	if (startNodePtr == NULL)
	{
		printf("\nNo data node found\n");
		return;
	}
	NODE* preNodePtr = NULL;
	NODE* currentNodePtr = NULL;
	NODE* nextNodePtr = NULL;
	int counter = 0;

	//Search node
	currentNodePtr = startNodePtr;
	while (counter != index)
	{
		preNodePtr = currentNodePtr;
		currentNodePtr = currentNodePtr->nextNodePtr;
		counter++;
	}
	nextNodePtr = currentNodePtr->nextNodePtr;

	//delete node
	free(currentNodePtr);

	//connect node
	if (preNodePtr == NULL)
		return;
	preNodePtr->nextNodePtr = nextNodePtr;
	
}

void print(void)
{
	int nodeIndex = 0;
	if (startNodePtr == NULL)
	{
		printf("\n Empty \n");
		return;
	}
	NODE* currentNodePtr = startNodePtr;
	while (currentNodePtr != NULL)
	{
		printf("\nNode index %d value : %d\n", nodeIndex++, currentNodePtr->value);
		currentNodePtr = currentNodePtr->nextNodePtr;
	}
}

void release()
{
	int nodeIndex = 0;
	NODE* currentNodePtr = startNodePtr;
	NODE* nextNodePtr = startNodePtr->nextNodePtr;
	while (nextNodePtr != NULL)
	{
		nextNodePtr = currentNodePtr->nextNodePtr;
		free(currentNodePtr);
		currentNodePtr = nextNodePtr;
	}
	free(currentNodePtr);
}
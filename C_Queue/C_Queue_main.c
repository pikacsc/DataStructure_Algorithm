#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define STR_MAX 20

struct _tagNode
{
	char data[STR_MAX];
	struct _tagNode* pNext;
};

typedef struct _tagNode NODE;
typedef NODE* PNODE;

struct _tagQueue
{
	PNODE pHead;
	PNODE pBack;
	int iSize;
};

typedef struct _tagQueue QUEUE;


void InitQueue(QUEUE* _pQueue);

//access the first element
char* front(QUEUE* _pQueue);

//access the last element
char* back(QUEUE* _pQueue);


//checks whether the underlying container is empty
bool empty(QUEUE* _pQueue);

//returns the number of elements
int size(QUEUE* _pQueue);

//inserts element at the end
void push(QUEUE* _pQueue,const char* _data);

//removes the first element
void pop(QUEUE* _pQueue, char* _pData);

//swaps the contents
void swap(QUEUE* _queue_1, QUEUE* _queue_2);



int main()
{
	QUEUE queue;
	InitQueue(&queue);

	QUEUE queue2; //for testing swap;
	InitQueue(&queue2);

	push(&queue2, "Cherry");
	push(&queue2, "Banana");
	push(&queue2, "Apple");
	swap(&queue, &queue2);

	int input = 0;
	bool IsValid = 0;
	while (1)
	{
		printf("\n");
		printf("1.front()\n");
		printf("2.back()\n");
		printf("3.empty()\n");
		printf("4.size()\n");
		printf("5.push(const char* _data)\n");
		printf("6.pop()\n");
		printf("0.Quit\n");
		printf("input>>");
		IsValid = scanf_s("%d", &input);
		if (!IsValid)
		{
			rewind(stdin);
			continue;
		}
		if (input == 0)
		{
			break;
		}
		else if (input == 1)
		{
			if (empty(&queue))
			{
				printf("\nNo Data found\n");
				continue;
			}
			printf("\nfirst element : %s\n", front(&queue));
		}
		else if (input == 2)
		{
			if (empty(&queue))
			{
				printf("\nNo Data found\n");
				continue;
			}
			printf("\nlast element : %s\n", back(&queue));
		}
		else if (input == 3)
		{
			const char* result = empty(&queue) ? "true" : "false";
			printf("\nIs Queue Empty? : %s\n", result);
		}
		else if (input == 4)
		{
			printf("\nsize : %d\n", size(&queue));
		}
		else if (input == 5)
		{
			rewind(stdin);
			printf("\ninput str data within 50\n>>");
			char strBuff[STR_MAX] = { 0 };
			scanf_s("%[^\n]%*c", strBuff, STR_MAX);
			push(&queue, strBuff);
		}
		else if (input == 6)
		{
			if (empty(&queue))
			{
				printf("\nNo Data found\n");
				continue;
			}
			char Data[STR_MAX] = { 0 };
			pop(&queue, Data);
			printf("\n%s removed\n", Data);
		}
	}
	

	return 0;
}

//initialize Queue
void InitQueue(QUEUE* _pQueue)
{
	_pQueue->iSize = 0;
	_pQueue->pHead = NULL;
	_pQueue->pBack = NULL;
}



//access the first element
char* front(QUEUE* _pQueue)
{
	return _pQueue->pHead->data;
}

//access the last element
char* back(QUEUE* _pQueue)
{
	return _pQueue->pBack->data;
}


//checks whether the underlying container is empty
bool empty(QUEUE* _pQueue)
{
	return _pQueue->iSize == 0;
}


//returns the number of elements
int size(QUEUE* _pQueue)
{
	return _pQueue->iSize;
}

//inserts element at the end
void push(QUEUE* _pQueue,const char* _data)
{
	PNODE newNode = (PNODE)calloc(1, sizeof(NODE));
	strcpy_s(newNode->data, STR_MAX, _data);
	newNode->pNext = NULL;
	if (empty(_pQueue))
	{
		_pQueue->pHead = newNode;
		_pQueue->pBack = _pQueue->pHead;
		_pQueue->iSize++;
	}
	else
	{
		PNODE pTempNode = _pQueue->pHead;
		//find last node
		while (pTempNode->pNext)
		{
			pTempNode = pTempNode->pNext;
		}
		pTempNode->pNext = newNode;
		_pQueue->pBack = newNode;
		_pQueue->iSize++;
	}
}

//removes the first element
void pop(QUEUE* _pQueue, char * _pData)
{
	PNODE pTempNode = NULL;
	
	strcpy_s(_pData, STR_MAX, _pQueue->pHead->data);
	pTempNode = _pQueue->pHead->pNext;
	free(_pQueue->pHead);

	_pQueue->iSize--;
	_pQueue->pHead = pTempNode;
}

//swaps the contents between _queue_1 and _queue_2
void swap(QUEUE* _queue_1, QUEUE* _queue_2)
{
	PNODE tempNode = _queue_1->pHead;
	_queue_1->pHead = _queue_2->pHead;
	_queue_2->pHead = tempNode;
	
	tempNode = _queue_1->pBack;
	_queue_1->pBack = _queue_2->pBack;
	_queue_2->pBack = tempNode;


	_queue_1->iSize ^= _queue_2->iSize ^= _queue_1->iSize ^= _queue_2->iSize;

}
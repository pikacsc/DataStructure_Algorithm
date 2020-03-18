// Stack
// push, pop, peek, del, isEmpty, getSize, print



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_STACK_SIZE 100

char stack[MAX_STACK_SIZE]; // construct stack

size_t currentSize = 0;

void push(char _element);

char pop();

char peek();

void del();

size_t getSize();

_Bool isEmpty();

void print();


int main(void)
{
	int input = 0;
	int OnLoop = 1;
	char element = 0;
	while (OnLoop == 1)
	{
		printf("\n<Menu>\n");
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.peek\n");
		printf("4.del\n");
		printf("5.isEmpty\n");
		printf("6.getSize\n");
		printf("7.print\n");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				printf("input char element : ");
				scanf(" %c", &element);
				push(element);
				break;
			case 2:
				printf("\npop %c \n", pop());
				printf("current size : %d \n", getSize());
				break;
			case 3:
				printf("peek : %c\n", peek());
				break;
			case 4:
				del();
				printf("after del \n");
				printf("current size : %d \n", getSize());
				break;
			case 5:
				if (isEmpty())
					printf("true\n");
				else
					printf("false\n");
				break;
			case 6:
				printf("get size : %d\n", getSize());
				break;
			case 7:
				print();
				break;
			default:
				OnLoop = 0;
				break;
		}
	}


	return 0;
}

void push(char _element)
{
	if (currentSize >= MAX_STACK_SIZE)
		return;
	stack[currentSize++] = _element;
}

char pop()
{
	return stack[--currentSize];
}

char peek()
{

	int lastIndex = currentSize - 1;
	return stack[lastIndex];
}

void del()
{
	while (currentSize != 0)
		stack[currentSize--] = 0;
}

size_t getSize()
{
	return currentSize;
}

_Bool isEmpty()
{
	return currentSize <= 0;
}

void print()
{
	for (size_t i = currentSize; i > 0;)
		printf("%c", stack[--i]);
	printf("\n");
}

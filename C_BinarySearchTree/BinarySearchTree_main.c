/*

Binary Search Tree

*/

#include <stdio.h>
#include "MyBST.h"

int main(void)
{
	Tree tree;
	InitTree(&tree);
	bool onLoop = true;
	size_t menuInput = 0;
	while (onLoop)
	{
		rewind(stdin);
		printf("\nBinary Search Tree\n");
		printf("1.Insert\n");
		printf("2.Search\n");
		printf("3.Display\n");
		printf("4.Delete\n");
		printf("0.Quit\n");
		printf(">>");
		scanf_s("%d", &menuInput);
		switch (menuInput)
		{
		case 1:
			Insert(&tree);
			break;
		case 2:
			Search(&tree);
			break;
		case 3:
			Display(&tree);
			break;
		case 4:
			Remove(&tree);
			break;
		case 0:
			onLoop = false;
			break;
		default:
			printf("\nWrong input, try again\n");
			break;
		}

	}

	DeleteAll(&tree);
	return 0;

}
#define COUNT 10
#include "MyBST.h"


static Node* MakeNode(size_t value);
static void print2DUtil(Node* root, int space);
static void InOrder(Node* root);
static void PostOrderFP(Node* root, void(*fp)(void* root));
static bool IsEmpty(Tree* tree);
static void IsInTree(Node* root, int value, bool* pFlag, Node** pTarget);

void InitTree(Tree* tree)
{
	tree->root = NULL;
	tree->size = 0;
}

void Insert(Tree* tree)
{
	size_t value = 0;

	rewind(stdin);
	printf("\nInput unsigned integer value\n>>");
	scanf_s("%d", &value);

	if (tree->root == NULL)
	{
		tree->root = MakeNode(value);
		printf("\nData inserted successfully\n");
		return;
	}
	
	Node** head = &(tree->root);

	while (1)
	{
		if (*head == NULL)
		{
			*head = MakeNode(value);
			break;
		}
		else if ((*head)->value > value)
		{
			head = &((*head)->pLeft);
			continue;
		}
		else if ((*head)->value < value)
		{
			head = &((*head)->pRight);
			continue;
		}
		else
		{
			printf("\nCan't insert duplicate value\n");
			return;
		}
	}
	printf("\nData inserted successfully\n");
}




void Display(Tree* tree)
{
	print2DUtil(tree->root, 0);
}

static Node* MakeNode(size_t value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("\nError not enough memory\n");
		return NULL;
	}
	newNode->pLeft = NULL;
	newNode->pRight = NULL;
	newNode->value = value;
	return newNode;
}



//https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
// Function to print binary tree in 2D  
// It does reverse inorder traversal 
static void print2DUtil(Node* root, int space)
{
	// Base case  
	if (root == NULL)
		return;

	// Increase distance between levels  
	space += COUNT;

	// Process right child first  
	print2DUtil(root->pRight, space);

	// Print current node after space  
	// count  
	printf("\n");
	for (int i = COUNT; i < space; i++)
		printf(" ");
	printf("%d\n", root->value);
	// Process left child  
	print2DUtil(root->pLeft, space);
}

void Traversal(Tree* tree)
{
	printf("\n");
	InOrder(tree->root);
}

static void InOrder(Node* root)
{
	if (root == NULL)
		return;

	InOrder(root->pLeft);
	printf("InOrder : %d\n", root->value);
	InOrder(root->pRight);
}

static void IsInTree(Node* root,int value, bool *pFlag, Node** pTarget)
{
	if (root == NULL)
		return;

	IsInTree(root->pLeft, value, pFlag, pTarget);
	if (root->value == value)
	{
		if(pFlag != NULL)
			*pFlag = true;
		if (pTarget != NULL)
			*pTarget = root;
	}
	IsInTree(root->pRight, value, pFlag, pTarget);
}

static void PostOrderFP(Node* root, void(*fp)(void* root))
{
	if (root == NULL)
		return;
	PostOrderFP(root->pLeft,free);
	PostOrderFP(root->pRight,free);
	fp(root);
}

void DeleteAll(Tree* tree)
{
	PostOrderFP(tree->root,free);
	printf("\nDelete all success fully");
}

void Search(Tree* tree)
{
	if (IsEmpty(tree) == true)
	{
		printf("\nNo data in tree\n");
		return;
	}

	rewind(stdin);
	size_t input = 0;
	bool found = false;
	printf("\nInput the value to search\n>>");
	scanf_s("%d", &input);
	
	IsInTree(tree->root, input, &found, NULL);

	if (found == true)
		printf("\nFound Value\n");
	else
		printf("\nNo value in tree\n");
}


//https://mattlee.tistory.com/30
void Remove(Tree* tree)
{
	rewind(stdin);
	size_t input = 0;
	printf("\nInput value to delete in tree\n>>");
	scanf_s("%d", &input);

	Node* parent, * child, * temp, *suc_p, *suc;

	parent = NULL;
	temp = tree->root;
	
	//searching
	while (temp != NULL && temp->value != input)
	{
		parent = temp;
		temp = (input < parent->value) ? parent->pLeft : parent->pRight;
	}

	if (!temp)
	{
		printf("\ncan't find value in tree\n");
		return;
	}

	//no subtree
	if (temp->pLeft == NULL && temp->pRight == NULL)
	{
		if (parent != NULL)
		{
			if (parent->pLeft == temp)
				parent->pLeft = NULL;
			else
				parent->pRight = NULL;
		}
		else
			tree->root = NULL;
	}

	//one subtree
	else if ((temp->pLeft == NULL) || (temp->pRight == NULL))
	{
		child = (temp->pLeft != NULL) ? temp->pLeft : temp->pRight;
		if (parent)
		{
			if (parent->pLeft == temp)
				parent->pLeft = child;
			else
				parent->pRight = child;
		}
		else
			tree->root = child;
	}
	
	//two subtrees
	else
	{
		suc_p = temp;
		suc = temp->pRight;
		while (suc->pLeft != NULL)
		{
			suc_p = suc;
			suc = suc->pLeft;
		}

		if (suc_p->pLeft == suc)
			suc_p->pLeft = suc->pRight;
		else
			suc_p->pRight = suc->pRight;

		temp->value = suc->value;
		temp = suc;
	}
	free(temp);
}

static bool IsEmpty(Tree* tree)
{
	return (tree->root == NULL);
}


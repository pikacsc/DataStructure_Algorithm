#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//No duplicate value allowed


//Tree Node struct
typedef struct _tagNode
{
	struct _tagNode* pLeft;
	struct _tagNode* pRight;
	size_t value;
} Node;

//Binary Search Tree struct
typedef struct _tagTree
{
	Node* root;
	size_t size;
} Tree;

void InitTree(Tree* tree);
void Insert(Tree* tree);
void Display(Tree* tree);
void Traversal(Tree* tree);
void DeleteAll(Tree* tree);
void Search(Tree* tree);
void Remove(Tree* tree);

//Update
#pragma once
#include <iostream>
#include <assert.h>
constexpr unsigned int TREEPRINT_SPACE = 10;
constexpr unsigned int TREEPRINT_COUNT = 10;



class TreeNode
{
	friend class MyBST;
	friend class BSTIterator;
private:
	int			m_iData;
	TreeNode*	m_pRootNode;
	TreeNode*	m_pLeftNode;
	TreeNode*	m_pRightNode;

private:
	TreeNode();
	~TreeNode();

	void PrintData();
	bool IsBiggerThen(const int& _iData);
};




class BSTIterator
{
	friend class MyBST;
public:
	BSTIterator();
	~BSTIterator();

private:
	TreeNode* m_pNode;

public:
	bool operator == (const BSTIterator& iter)
	{
		return m_pNode == iter.m_pNode;
	}

	bool operator != (const BSTIterator& iter)
	{
		return m_pNode != iter.m_pNode;
	}

	void operator ++ ()
	{
		assert(m_pNode != nullptr);

		if (m_pNode->m_pRightNode != nullptr)
		{
			m_pNode = m_pNode->m_pRightNode;
			while (m_pNode->m_pLeftNode != nullptr)
			{
				m_pNode = m_pNode->m_pLeftNode;
			}
			return;
		}
		else if (m_pNode->m_iData < m_pNode->m_pRootNode->m_iData)
		{
			m_pNode = m_pNode->m_pRootNode;
			return;
		}

		while (m_pNode->m_iData > m_pNode->m_pRootNode->m_iData)
		{
			m_pNode = m_pNode->m_pRootNode;
		}
		m_pNode = m_pNode->m_pRootNode;

	}

	void operator -- ()
	{
		assert(m_pNode != nullptr);
		
		if (m_pNode->m_pLeftNode != nullptr)
		{
			m_pNode = m_pNode->m_pLeftNode;
			while(m_pNode->m_pRightNode != nullptr)
			{
				m_pNode = m_pNode->m_pRightNode;
			}
			return;
		}
		else if (m_pNode->m_iData > m_pNode->m_pRootNode->m_iData)
		{
			m_pNode = m_pNode->m_pRootNode;
			return;
		}
		while (m_pNode->m_iData < m_pNode->m_pRootNode->m_iData)
		{
			m_pNode = m_pNode->m_pRootNode;
		}
		m_pNode = m_pNode->m_pRootNode;
		
	}

	int operator * ()
	{
		return m_pNode->m_iData;
	}
};


class MyBST
{
private:
	TreeNode*		m_pHead;
	unsigned int	m_uiSize;
public:
	typedef BSTIterator iterator;

public:
	MyBST();

	~MyBST();
	
	void Insert(const int& _iData);
	void Print2D();
	void DisplayAll();
	void Remove(const int& _iData);
	TreeNode* Begin() const;
	TreeNode* End() const;
	TreeNode* SearchNode(const int& _iData);
	void DeleteAll();

	//iterator
	iterator IterBegin() const;
	iterator IterEnd() const;
	
private:
	void Traversal(void (*_func_ptr)(TreeNode* _pRootNode));
	void Traversal_nonRecursive(void (*_func_ptr)(TreeNode* _pRootNode));

	void InOrder(TreeNode* _pRootNode, void (*_func_ptr)(TreeNode* _pRootNode));
	void PostOrder(TreeNode* _pRootNode, void (*_func_ptr)(TreeNode* _pRootNode));
	TreeNode& MakeNode(const int& _iData);
	static void Display(TreeNode* _pRootNode);
	static void Print2DUtil(TreeNode* _pRootNode, unsigned int _space);
	static void DeleteNode(TreeNode* _pNode);
	bool IsEmpty() const;
	


};


#include "MyBST.h"

TreeNode::TreeNode()
	:m_iData(0), m_pRootNode(nullptr), m_pLeftNode(nullptr), m_pRightNode(nullptr)
{}

TreeNode::~TreeNode()
{}

void TreeNode::PrintData()
{
	std::cout << m_iData << std::endl;
}

bool TreeNode::IsBiggerThen(const int& _iData)
{
	return m_iData > _iData;
}



MyBST::MyBST()
	:m_pHead(nullptr), m_uiSize(0)
{}

MyBST::~MyBST()
{
	if (m_pHead != nullptr)
		DeleteAll();
}

void MyBST::Insert(const int& _iData)
{
	TreeNode* newNode = &MakeNode(_iData);

	if (IsEmpty())
	{
		m_pHead = newNode;
	}
	else
	{
		TreeNode* tempNode = m_pHead;
		while (1)
		{
			if (tempNode->m_iData < _iData)
			{
				if (tempNode->m_pRightNode)
				{
					tempNode = tempNode->m_pRightNode;
					continue;
				}
				else
				{
					tempNode->m_pRightNode = newNode;
					newNode->m_pRootNode = tempNode;
					break;
				}
			}
			else
			{
				if (tempNode->m_pLeftNode)
				{
					tempNode = tempNode->m_pLeftNode;
					continue;
				}
				else
				{
					tempNode->m_pLeftNode = newNode;
					newNode->m_pRootNode = tempNode;
					break;
				}
			}
		}
		m_uiSize++;
	}
}

void MyBST::Print2D()
{
	if (IsEmpty()) return;

	Print2DUtil(m_pHead, 0);
}

void MyBST::DisplayAll()
{
	if (IsEmpty()) return;

	//Traversal(Display);
	Traversal_nonRecursive(Display);
}

void MyBST::Remove(const int& _iData)
{
	if (IsEmpty())
		return;

	//when head deleted
	if (m_pHead->m_iData == _iData)
	{

		return;
	}

	TreeNode* pRoot = m_pHead;
	TreeNode** pTarget = nullptr;

	while (pRoot != nullptr)
	{
		if (pRoot->m_pLeftNode != nullptr && pRoot->m_pLeftNode->m_iData == _iData) 
		{
			pTarget = &(pRoot->m_pLeftNode);
			break;
		}
		else if (pRoot->m_pRightNode != nullptr && pRoot->m_pRightNode->m_iData == _iData)
		{
			pTarget = &(pRoot->m_pRightNode);
			break;
		}
		else if (pRoot->m_iData > _iData)
		{
			pRoot = pRoot->m_pLeftNode;
		}
		else if (pRoot->m_iData < _iData)
		{
			pRoot = pRoot->m_pRightNode;
		}
		else
			break;
	}

	if (pTarget == nullptr)
	{
		std::cout << "Can't find it" << std::endl;
		return;
	}


	TreeNode* tempNode = nullptr;


	//No subtree
	if ((*pTarget)->m_pLeftNode == nullptr && (*pTarget)->m_pRightNode == nullptr)
	{
		delete (*pTarget);
		*pTarget = nullptr;
	}
	else if ((*pTarget)->m_pLeftNode != nullptr && (*pTarget)->m_pRightNode != nullptr)//two leaves	
	{
		if (_iData < m_pHead->m_iData) // left side
		{
			tempNode = (*pTarget)->m_pRightNode;
			tempNode->m_pLeftNode = (*pTarget)->m_pLeftNode;
			delete (*pTarget);
			*pTarget = tempNode;
		}
		else if (_iData > m_pHead->m_iData) // right side
		{
			tempNode = (*pTarget)->m_pLeftNode;
			tempNode->m_pRightNode = (*pTarget)->m_pRightNode;
			delete (*pTarget);
			*pTarget = tempNode;
		}
	}
	//one leaf
	else if ((*pTarget)->m_pLeftNode != nullptr)
	{
		tempNode = (*pTarget)->m_pLeftNode;
		delete (*pTarget);
		*pTarget = tempNode;
	}
	else if ((*pTarget)->m_pRightNode != nullptr)
	{
		tempNode = (*pTarget)->m_pRightNode;
		delete (*pTarget);
		*pTarget = tempNode;
	}

}

TreeNode* MyBST::Begin() const
{
	if (m_pHead == nullptr)
		return nullptr;

	if (m_pHead->m_pLeftNode == nullptr)
	{
		return m_pHead;
	}

	TreeNode* pNode = m_pHead;

	while (pNode)
	{
		if (pNode->m_pLeftNode)
		{
			pNode = pNode->m_pLeftNode;
		}
		else
		{
			return pNode;
		}
	}
	return pNode;
}

TreeNode* MyBST::End() const
{
	if (m_pHead == nullptr)
		return nullptr;

	if (m_pHead->m_pRightNode == nullptr)
	{
		return m_pHead;
	}

	TreeNode* pNode = m_pHead;
	
	while (pNode)
	{
		if (pNode->m_pRightNode)
		{
			pNode = pNode->m_pRightNode;
		}
		else
		{
			return pNode;
		}
	}
	return pNode;
}

TreeNode* MyBST::SearchNode(const int& _iData)
{
	if (IsEmpty())
		return nullptr;

	TreeNode* pNode = m_pHead;

	while (pNode->m_iData != _iData && pNode != nullptr)
	{
		if (pNode->m_iData > _iData)
		{
			pNode = pNode->m_pLeftNode;
			continue;
		}
		else
		{
			pNode = pNode->m_pRightNode;
			continue;
		}
	}

	return pNode;
}

void MyBST::DeleteAll()
{
	if (IsEmpty()) return;

	PostOrder(m_pHead, DeleteNode);
}

MyBST::iterator MyBST::IterBegin() const
{
	iterator iter;
	iter.m_pNode = Begin();
	return iter;
}

MyBST::iterator MyBST::IterEnd() const
{
	iterator iter;
	iter.m_pNode = End();
	return iter;
}



void MyBST::Traversal(void(*_func_ptr)(TreeNode* _pRootNode))
{
	if (IsEmpty())
		return;

	InOrder(m_pHead, _func_ptr);
}

void MyBST::Traversal_nonRecursive(void(*_func_ptr)(TreeNode* _pRootNode))
{
	if (IsEmpty())
		return;

	if (m_pHead->m_pLeftNode == nullptr && m_pHead->m_pRightNode == nullptr)
	{
		_func_ptr(m_pHead);
		return;
	}

	TreeNode* pNode = Begin();
	TreeNode* pEndNode = End();
	while (pNode != pEndNode)
	{
		if (pNode->m_pRightNode != nullptr)
		{
			pNode = pNode->m_pRightNode;
			while (pNode->m_pLeftNode != nullptr)
			{
				pNode = pNode->m_pLeftNode;
			}
			_func_ptr(pNode);
			continue;
		}
		else if (pNode->m_iData < pNode->m_pRootNode->m_iData)
		{
			pNode = pNode->m_pRootNode;
			_func_ptr(pNode);
			continue;
		}
		while (pNode->m_iData > pNode->m_pRootNode->m_iData)
		{
			pNode = pNode->m_pRootNode;
		}
		pNode = pNode->m_pRootNode;
		_func_ptr(pNode);
		continue;
	}
	
}

void MyBST::InOrder(TreeNode* _pRootNode, void(*_func_ptr)(TreeNode* _pRootNode))
{
	if (!_pRootNode) return;

	InOrder(_pRootNode->m_pLeftNode, _func_ptr);
	_func_ptr(_pRootNode);
	InOrder(_pRootNode->m_pRightNode, _func_ptr);
}

void MyBST::PostOrder(TreeNode* _pRootNode, void(*_func_ptr)(TreeNode* _pRootNode))
{
	if (!_pRootNode) return;

	PostOrder(_pRootNode->m_pLeftNode, _func_ptr);
	PostOrder(_pRootNode->m_pRightNode, _func_ptr);
	_func_ptr(_pRootNode);
}

TreeNode& MyBST::MakeNode(const int& _iData)
{
	TreeNode& newNode = *(new TreeNode);
	newNode.m_iData = _iData;
	return newNode;
}

void MyBST::Display(TreeNode* _pRootNode)
{
	_pRootNode->PrintData();
}

void MyBST::Print2DUtil(TreeNode* _pRootNode, unsigned int _space)
{
	if (_pRootNode == NULL)
		return;


	_space += TREEPRINT_COUNT;


	Print2DUtil(_pRootNode->m_pRightNode, _space);

	std::cout << std::endl;

	for (unsigned int i = TREEPRINT_COUNT; i < _space; i++)
		std::cout << " ";
	std::cout << _pRootNode->m_iData << std::endl;

	Print2DUtil(_pRootNode->m_pLeftNode, _space);

}

void MyBST::DeleteNode(TreeNode* _pNode)
{
	if (_pNode)
	{
		delete _pNode;
	}
}

bool MyBST::IsEmpty() const
{
	return m_pHead == nullptr;
}

BSTIterator::BSTIterator()
	:m_pNode(nullptr)
{}

BSTIterator::~BSTIterator()
{
}



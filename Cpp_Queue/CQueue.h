#pragma once


template <typename T>
class CQueueNode
{
	template <typename T>
	friend class CQueue;

private:
	CQueueNode(const T& _data = NULL)
		:m_Data(_data),m_pNext(nullptr)
	{
	}
	
	~CQueueNode()
	{
	}

	//Connecting _Node as this's next node
	//_Node's previous node will be this node
	void ConnectNextNode(CQueueNode<T>* _Node)
	{
		m_pNext = _Node;
		_Node->m_pPrev = this;
	}

	//Connecting _Node as this's prev node
	//_Node's next node will be this node
	void ConnectPrevNode(CQueueNode<T>* _Node)
	{
		m_pPrev = _Node;
		_Node->m_pNext = this;
	}

private:
	T				m_Data;
	CQueueNode<T>*	m_pPrev;
	CQueueNode<T>*	m_pNext;

};

//Queue 와 Stack 은 탐색이 불가능하도록 설계되어서
//Iterator 가 존재하지 않음

template <typename T>
class CQueue
{
	typedef CQueueNode<T> NODE;
	typedef CQueueNode<T>* PNODE;
private:
	PNODE m_Begin;
	PNODE m_End;
	int	  m_iSize;

public:
	CQueue()
		:m_Begin(new NODE()),m_End(new NODE()),m_iSize(0)
	{}

	~CQueue()
	{
		deleteAll();
		if (m_Begin)
		{
			delete m_Begin;
		}
		if (m_End)
		{
			delete m_End;
		}
	}

public:
	//access the first element
	T front(void)
	{
		if (empty())
		{
			return NULL;
		}
		else
		{
			return m_Begin->m_pNext->m_Data;
		}
	}

	//access the last element
	T back(void)
	{
		if (empty())
		{
			return NULL;
		}
		else
		{
			return m_End->m_pPrev->m_Data;
		}
	}


	//checks whether the underlying container is empty
	bool empty(void) const
	{
		return m_iSize == 0;
	}


	//returns the number of elements
	int size(void) const
	{
		return m_iSize;
	}

	//inserts element at the end
	void push(const T& _data)
	{
		PNODE newNode = new NODE(_data);
		if (empty())
		{
			m_Begin->ConnectNextNode(newNode);
			newNode->ConnectPrevNode(m_Begin);
			newNode->ConnectNextNode(m_End);
			m_End->ConnectPrevNode(newNode);
			m_iSize++;
		}
		else
		{
			PNODE pLastNode = m_End->m_pPrev;
			pLastNode->ConnectNextNode(newNode);
			newNode->ConnectPrevNode(pLastNode);
			newNode->ConnectNextNode(m_End);
			m_End->ConnectPrevNode(newNode);
			m_iSize++;
		}
	}

	//removes the first element
	T pop(void)
	{
		if (empty())
		{
			return NULL;
		}
		else 
		{
			T Data = m_Begin->m_pNext->m_Data;
			PNODE pNext = m_Begin->m_pNext->m_pNext;
			delete m_Begin->m_pNext;
			m_iSize--;
			m_Begin->ConnectNextNode(pNext);
			pNext->ConnectPrevNode(m_Begin);
			return Data;
		}
	}

	//swaps the contents
	void swap(CQueue* _queue)
	{
	}

	void deleteAll(void)
	{
		if (m_iSize == 0)
		{
			return;
		}
		else
		{
			PNODE pNode = m_Begin->m_pNext;
			PNODE pNext = nullptr;
			while (pNode != m_End)
			{
				pNext = pNode->m_pNext;
				delete pNode;
				pNode = pNext;
			}
			m_iSize = 0;
		}
	}

	void printQueue(void)
	{
		
		printf("\nlast");
		for (int i = 0; i <= m_iSize-2; i++)
		{
			printf("  "); 
		}
		printf("first\n");

		printf(" ↓");
		for (int i = 0; i <= m_iSize-2; i++)
		{
			printf("  ");
		}
		printf("↓\n");
		PNODE pBegin = m_Begin;
		PNODE pEnd = m_End;
		while (pEnd != pBegin)
		{
			pEnd = pEnd->m_pPrev;
			std::cout << " "<< pEnd->m_Data;
		}
		printf("\n");
	}

};


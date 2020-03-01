#pragma once




template <typename T>
class MyListNode
{
	typedef MyListNode<T>	NODE;
	typedef MyListNode<T>* PNODE;
	
	template <typename T>
	friend class MyLinkedList;

	template <typename T>
	friend class MyListIterator;
private:
	T		m_Data;
	PNODE	m_Next;
	PNODE	m_Prev;
private:
	MyListNode()
		:m_Data(0), m_Next(nullptr), m_Prev(nullptr)
	{}

	MyListNode(const T& _Data)
		:m_Data(_Data), m_Next(nullptr), m_Prev(nullptr)
	{}

	~MyListNode(){}


};


template <typename T>
class MyLinkedList;

template <typename T>
class MyListIterator
{
	typedef MyListNode<T>	NODE;
	typedef MyListNode<T>* PNODE;

	template <typename T>
	friend class MyLinkedList;


private:
	PNODE m_Node;

public:
	MyListIterator()
		:m_Node(nullptr)
	{}

	~MyListIterator()
	{}

public:
	bool operator == (const MyListIterator<T>& iter)
	{
		return m_Node == iter.m_Node;
	}

	bool operator != (const MyListIterator<T>& iter)
	{
		return m_Node != iter.m_Node;
	}

	void operator ++ ()
	{
		if (m_Node->m_Next == nullptr)
			return;
		m_Node = m_Node->m_Next;
	}

	void operator -- ()
	{
		if (m_Node->m_Prev == nullptr)
			return;
		m_Node = m_Node->m_Prev;
	}

	T& operator * ()
	{
		return m_Node->m_Data;
	}

};


template <typename T>
class MyLinkedList
{
	typedef MyListNode<T>	NODE;
	typedef MyListNode<T>* PNODE;

private:
	PNODE		m_Begin;
	PNODE		m_End;
	uint32_t	m_uiSize;
	int			(*m_Compare_funcPtr)(const T& _DataA,const T& _DataB);
public:
	typedef MyListIterator<T>		iterator;

public:
	MyLinkedList(int (*_Compare_fp)(const T& _DataA, const T& _DataB))
		:m_Begin(new NODE),m_End(new NODE),m_uiSize(0),m_Compare_funcPtr(_Compare_fp)
	{
	}

	~MyLinkedList()
	{
		clear();
	}

	//list �� ��������� true�� ��ȯ �մϴ�.
	bool empty()
	{
		return m_uiSize == 0;
	}

	//m_Begin, m_End�� ������, ��ü ��� ���� ��ȯ �մϴ�.
	uint32_t size()
	{
		return m_uiSize;
	}

	//ù��° ��尡 �� ��� �������� �ּҸ� ��ȯ�մϴ�.
	NODE** front()
	{
		return &(m_Begin->m_Next);
	}

	//������ ��尡 �� ��� �������� �ּҸ� ��ȯ�մϴ�.
	NODE** back()
	{
		return &(m_End->m_Prev);
	}


	//�����̳� ���ۺκп� �־��� ��� ���� �߰� �մϴ�.
	//�ݺ��� �Ǵ� ������ ��ȿȭ ���� �ʽ��ϴ�.
	void push_front(const T& _Data)
	{
		PNODE newNode = new NODE(_Data);
		NODE** pFront = front();
		NODE** pBack = back();

		if (m_uiSize == 0)
		{
			ConnectNode(m_Begin, newNode);
			ConnectNode(newNode, m_End);
			m_uiSize++;
		}
		else if (m_uiSize <= 1)
		{	
			ConnectNode(newNode, *pFront);
			ConnectNode(m_Begin, newNode);
			ConnectNode(newNode, *pBack);
			m_uiSize++;
		}
		else
		{
			ConnectNode(newNode, *pFront);
			ConnectNode(m_Begin, newNode);
			m_uiSize++;
		}
	}

	//�����̳��� ù ��° ��Ҹ� �����մϴ�.
	//������ ��ҿ� ���� ���� �� �ݺ��ڴ� ��ȿȭ�˴ϴ�.
	void pop_front()
	{
		if (m_uiSize == 0)
			return;
		PNODE nextNode = (*front())->m_Next;
		NODE** pFront = front();
			
		delete *pFront;
		m_uiSize--;
		
		*pFront = nextNode;
	}

	//�־��� ��� ���� �����̳��� ���� �߰� �մϴ�.
	void push_back(const T& _Data)
	{
		PNODE newNode = new NODE(_Data);
		NODE** pFront = &(m_Begin->m_Next);
		NODE** pBack = &(m_End->m_Prev);

		if (m_uiSize == 0)
		{
			ConnectNode(m_Begin, newNode);
			ConnectNode(newNode, m_End);
			m_uiSize++;
		}
		else if (m_uiSize <= 1)
		{
			ConnectNode((*pFront), newNode);
			ConnectNode(newNode, m_End);
			m_uiSize++;
		}
		else
		{
			ConnectNode((*pBack), newNode);
			ConnectNode(newNode, m_End);
			m_uiSize++;
		}
	}
	
	//�����̳��� ������ ��Ҹ� �����մϴ�.
	//������ ��ҿ� ���� ���� �� �ݺ��ڴ� ��ȿȭ�˴ϴ�.
	void pop_back()
	{
		if (m_uiSize == 0)
			return;
		PNODE prevNode = (*back())->m_Prev;
		prevNode->m_Next = m_End;
		NODE** pBack = back();

		delete * pBack;
		m_uiSize--;

		*pBack = prevNode;
	}

	//_Data�� ��ġ�ϴ� �����͸� ���� ��� ��ҵ��� ���� �մϴ�.
	void remove(const T& _Data)
	{
		if (m_uiSize == 0)
			return;

		PNODE tempNode = m_Begin;
		int result = -1;
		iterator iter;
		iterator iterEnd = IterEnd();

		for (iter = IterBegin(); iter != iterEnd; ++iter)
		{
			if (m_Compare_funcPtr(_Data, *iter) == 0)
			{
				EraseAtPos(iter);
				continue;
			}
		}
	}


	//�־��� ���� �����̳��� Ư����ġ�� �����մϴ�.
	void insert(const iterator& _pos,const T& _Data)
	{
		iterator iter = _pos;
		if (_pos == IterBegin())
		{
			push_front(_Data);
		}
		else if (_pos == IterEnd())
		{
			push_back(_Data);
		}
		else
		{
			PNODE newNode = new NODE(_Data);
			PNODE prevNode = _pos->m_Node;
			PNODE nextNode = prevNode->m_Next;
			prevNode->m_Next = newNode;
			newNode->m_Prev = prevNode;
			nextNode->m_Prev = newNode;
			newNode->m_Next = nextNode;
		}
	}


	//_pos �� �ִ� ��带 ���� �մϴ�.
	void EraseAtPos(const iterator& _pos)
	{
		if (m_uiSize == 0)
			return;

		PNODE prevNode = nullptr;
		PNODE nextNode = nullptr;
		if (_pos.m_Node->m_Prev != nullptr)
			prevNode = _pos.m_Node->m_Prev;
		if(_pos.m_Node->m_Next != nullptr)
			nextNode = _pos.m_Node->m_Next;
		
		delete _pos.m_Node;
		m_uiSize--;

		if(prevNode != nullptr)
			prevNode->m_Next = nextNode;
		if (nextNode != nullptr)
			nextNode->m_Prev = prevNode;
	}

	//_first ���� _last ���� ���� �մϴ�.
	void EraseAtRange(const iterator& _first, const iterator& _last)
	{
		PNODE prevNode = nullptr;
		PNODE nextNode = nullptr;
		PNODE deleteNode = _first.m_Node;
		PNODE tempNode = nullptr;
		if (_first.m_Node->m_Prev != nullptr)
			prevNode = _first.m_Node->m_Prev;
		if (_last.m_Node->m_Next != nullptr)
			nextNode = _last.m_Node->m_Next;
		
		while (deleteNode != nextNode)
		{
			tempNode = deleteNode->m_Next;
			delete deleteNode;
			m_uiSize--;
			deleteNode = tempNode;
		}

		if (prevNode != nullptr)
			prevNode->m_Next = nextNode;
		if (nextNode != nullptr)
			nextNode->m_Prev = prevNode;
	}

	//��� ������ ���� �մϴ�.
	void clear()
	{
		if (m_Begin == nullptr)
			return;

		PNODE currentNode = m_Begin;
		PNODE nextNode = nullptr;
		while (currentNode != nullptr)
		{
			nextNode = currentNode->m_Next;
			delete currentNode;
			m_uiSize--;
			currentNode = nextNode;
		}
	}

	//������ �����մϴ�.
	//_Node1->next = _Node2
	//_Node2->prev = _Node1
	void ConnectNode(NODE* _Node1, NODE* _Node2)
	{
		_Node1->m_Next = _Node2;
		_Node2->m_Prev = _Node1;
	}


public:
	
	//ù��° ��带 ����Ű�� iterator�� ��ȯ�մϴ�.
	iterator IterBegin() const
	{
		iterator iter;
		iter.m_Node = m_Begin->m_Next;
		return iter;
	}

	//������ ��� ���� m_End �� ����Ű�� iterator�� ��ȯ�մϴ�.
	//m_End�� �����Ͱ� ���� ���� ��� �Դϴ�.
	iterator IterEnd() const
	{
		iterator iter;
		iter.m_Node = m_End;
		return iter;
	}


};


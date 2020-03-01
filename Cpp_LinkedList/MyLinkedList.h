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

	//list 가 비어있으면 true를 반환 합니다.
	bool empty()
	{
		return m_uiSize == 0;
	}

	//m_Begin, m_End를 제외한, 전체 노드 수를 반환 합니다.
	uint32_t size()
	{
		return m_uiSize;
	}

	//첫번째 노드가 들어갈 노드 포인터의 주소를 반환합니다.
	NODE** front()
	{
		return &(m_Begin->m_Next);
	}

	//마지막 노드가 들어갈 노드 포인터의 주소를 반환합니다.
	NODE** back()
	{
		return &(m_End->m_Prev);
	}


	//컨테이너 시작부분에 주어진 요소 값을 추가 합니다.
	//반복자 또는 참조가 무효화 되지 않습니다.
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

	//컨테이너의 첫 번째 요소를 제거합니다.
	//지워진 요소에 대한 참조 및 반복자는 무효화됩니다.
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

	//주어진 요소 값을 컨테이너의 끝에 추가 합니다.
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
	
	//컨테이너의 마지막 요소를 제거합니다.
	//지워진 요소에 대한 참조 및 반복자는 무효화됩니다.
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

	//_Data와 일치하는 데이터를 가진 모든 요소들을 삭제 합니다.
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


	//주어진 값을 컨테이너의 특정위치에 삽입합니다.
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


	//_pos 에 있는 노드를 삭제 합니다.
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

	//_first 부터 _last 까지 삭제 합니다.
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

	//모든 노드들을 삭제 합니다.
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

	//노드들을 연결합니다.
	//_Node1->next = _Node2
	//_Node2->prev = _Node1
	void ConnectNode(NODE* _Node1, NODE* _Node2)
	{
		_Node1->m_Next = _Node2;
		_Node2->m_Prev = _Node1;
	}


public:
	
	//첫번째 노드를 가리키는 iterator를 반환합니다.
	iterator IterBegin() const
	{
		iterator iter;
		iter.m_Node = m_Begin->m_Next;
		return iter;
	}

	//마지막 노드 다음 m_End 를 가리키는 iterator를 반환합니다.
	//m_End는 데이터가 없는 공백 노드 입니다.
	iterator IterEnd() const
	{
		iterator iter;
		iter.m_Node = m_End;
		return iter;
	}


};


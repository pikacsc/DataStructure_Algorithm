#pragma once
/*
Vector

동적 배열을 사용

*/

template <typename T>
class CVectorNode
{
private:
	template <typename T>
	friend class CVector;

	template <typename T>
	friend class CVector_Iterator;
private:
	CVectorNode()
		:m_Data(0),m_iIndex(0)
	{
	}

	~CVectorNode()
	{
	}

private:
	T		m_Data;
	int		m_iIndex;
};

template<typename T>
class CVector_Iterator
{	
	template<typename T>
	friend class CVector;

	typedef CVectorNode<T>	 NODE;
	typedef CVectorNode<T>* PNODE;
private:
	PNODE m_Node;

public:
	CVector_Iterator()
		:m_Node(nullptr)
	{}

	~CVector_Iterator()
	{
	}

public:
	void operator ++ ()
	{
		m_Node++;
	}

	void operator -- ()
	{
		m_Node--;
	}

	bool operator == (const CVector_Iterator& iter)
	{
		return iter.m_Node == m_Node;
	}

	bool operator != (const CVector_Iterator& iter)
	{
		return iter.m_Node != m_Node;
	}

	T& operator * ()
	{
		return m_Node->m_Data;
	}

};


template <typename T>
class CVector
{
	enum eVector_Constants
	{
		eDEFAULT_CAPACITY = 4,
		eRESIZE_MULTIPLYVALUE = 2
	};

private:
	typedef CVectorNode<T>	 NODE;
	typedef CVectorNode<T>* PNODE;

private:
	typedef CVector_Iterator<T> iterator;
	
public:
	CVector(int _iSize = eDEFAULT_CAPACITY)
		:m_iSize(0), 
		m_iCapacity(_iSize),
		m_pArray(new NODE[_iSize + 2])
	{
	}

	~CVector()
	{
		delete[] m_pArray;
	}

private:
	//선언 순서대로 member initialize list 초기화
	unsigned int	m_iSize;     
	unsigned int	m_iCapacity; 
	PNODE			m_pArray;    


public:
	void push_back(const T& _data)
	{
		if (Full())
		{
			resize(m_iSize * eRESIZE_MULTIPLYVALUE);
		}

		m_pArray[m_iSize + 1].m_Data = _data;

		// 0번은 begin이다, 그런데 실제 1번인덱스 부터 노드가 추가되는데
		// 처음 추가된 노드는 0번부터 인덱스를 주도록 한다.
		m_pArray[m_iSize + 1].m_iIndex = m_iSize;
		++m_iSize;
	}

	void resize(int _iSize)
	{
		// +2 를 해주는 이유는 begin 과 end 노드를 포함시켜서
		// 생성하기 위해서이다.
		PNODE pArray = new NODE[_iSize + 2];

		// 위에서 2배만큼 공간을 새로 할당하고 기존에 있는 노드의 데이터를 
		// 새로 할당한 공간에 복사해준다.
		// 메모리 주소에 +1을 해준 이유는 1번 인덱스 부터
		// 시작이기 때문에 여기부터 복사를 해주기 위해서 +1을 해주었다.
		memcpy(pArray + 1, m_pArray + 1, sizeof(NODE) * m_iSize);

		//기존 노드를 삭제한다.
		delete[] m_pArray;


		m_pArray = pArray;

		m_iCapacity = _iSize;
	}

	void clear()
	{
		delete[] m_pArray;
		m_iSize = 0;
		m_iCapacity = eDEFAULT_CAPACITY;
		m_pArray = new NODE[eDEFAULT_CAPACITY + 2];
	}

	bool Full() const
	{
		return m_iSize == m_iCapacity;
	}

	bool empty() const
	{
		return m_iSize == 0;
	}

	int size() const
	{
		return m_iSize;
	}

	int capacity() const
	{
		return m_iCapacity;
	}

	T operator [] (int _index) const
	{
		return m_pArray[_index + 1].m_Data;
	}

	void reserve(int _iSize)
	{
		delete[] m_pArray;
		m_pArray = new NODE[_iSize + 2];
		m_iCapacity = _iSize;
		m_iSize = 0;
	}

	//iterator
public:
	iterator iterBegin(void)
	{
		iterator iterBegin;
		iterBegin.m_Node = m_pArray + 1;
		return iterBegin;
	}

	iterator iterEnd(void)
	{
		iterator iterEnd;
		iterEnd.m_Node = m_pArray+m_iSize + 1;
		return iterEnd;
	}
};



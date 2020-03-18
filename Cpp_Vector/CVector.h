#pragma once
/*
Vector

���� �迭�� ���

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
	//���� ������� member initialize list �ʱ�ȭ
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

		// 0���� begin�̴�, �׷��� ���� 1���ε��� ���� ��尡 �߰��Ǵµ�
		// ó�� �߰��� ���� 0������ �ε����� �ֵ��� �Ѵ�.
		m_pArray[m_iSize + 1].m_iIndex = m_iSize;
		++m_iSize;
	}

	void resize(int _iSize)
	{
		// +2 �� ���ִ� ������ begin �� end ��带 ���Խ��Ѽ�
		// �����ϱ� ���ؼ��̴�.
		PNODE pArray = new NODE[_iSize + 2];

		// ������ 2�踸ŭ ������ ���� �Ҵ��ϰ� ������ �ִ� ����� �����͸� 
		// ���� �Ҵ��� ������ �������ش�.
		// �޸� �ּҿ� +1�� ���� ������ 1�� �ε��� ����
		// �����̱� ������ ������� ���縦 ���ֱ� ���ؼ� +1�� ���־���.
		memcpy(pArray + 1, m_pArray + 1, sizeof(NODE) * m_iSize);

		//���� ��带 �����Ѵ�.
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



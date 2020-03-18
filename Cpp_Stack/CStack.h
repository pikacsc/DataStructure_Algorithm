#pragma once

template <typename T>
class CStackNode
{
private:
	CStackNode() 
		:m_Data(0),
		m_pNext(nullptr)
	{}

	~CStackNode()
	{}

private:
	template <typename T>
	friend class CStack;

private:
	T				m_Data;
	CStackNode<T>*	m_pNext;
};

template <typename T>
class CStack
{
public:
	CStack()
		:m_pBegin(new NODE),
		m_pEnd(new NODE),
		m_uiSize(0)
	{
		m_pBegin->m_pNext = m_pEnd;
	}

	~CStack()
	{
		PNODE pNode = m_pBegin;
		PNODE pNext = nullptr;
		while (pNode)
		{
			pNext = pNode->m_pNext;
			delete pNode;
			pNode = pNext;
		}
	}

private:
	typedef CStackNode<T>	NODE;
	typedef CStackNode<T>*	PNODE;

private:
	PNODE			m_pBegin;
	PNODE			m_pEnd;
	unsigned int	m_uiSize;

public:
	void push(const T& _data)
	{
		//�� ������ ��� ���� �� �ʱ�ȭ
		PNODE pNode = new NODE;
		pNode->m_Data = _data;

		
		PNODE pNext = m_pBegin->m_pNext;
		pNode->m_pNext = pNext;
		m_pBegin->m_pNext = pNode;
		++m_uiSize;
	}

	T pop(void)
	{
		if (empty())
		{
			return 0;
		}

		//������ ���� begin�� ���� ����̴�.
		PNODE pNode = m_pBegin->m_pNext;
		
		//������ ��带 �����ַ��� begin�� ������ ����� 
		//���� ��带 ������ �־�� �Ѵ�.
		PNODE pNext = pNode->m_pNext;
		T data = pNode->m_Data;
		delete pNode;
		m_pBegin->m_pNext = pNext;
		m_uiSize--;
		return data;
	}

	T top()
	{
		if (empty())
		{
			return 0;
		}
		return m_pBegin->m_pNext->m_Data;
	}

	bool empty() const
	{
		return m_uiSize == 0;
	}
};


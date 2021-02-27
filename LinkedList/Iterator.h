#pragma once
#include "Node.h"

template<typename T>
class Iterator
{
public:
	Iterator();
	Iterator(Node<T>* node);

	Iterator<T> operator++(int);
	Iterator<T> operator--(int);
	const bool operator==(const Iterator<T>& iter);
	const bool operator!=(const Iterator<T>& iter);
	T operator*();

	Node<T>* getCurrent();


	void setCurrent(Node<T>* input);


	Node<T>* m_current;
};

template<typename T>
inline Iterator<T>::Iterator()
{
	m_current = nullptr;
}

template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	m_current = node;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator++(int)
{
	//If not at end goes to next node
	if (m_current->next != nullptr)
	{
		m_current = m_current->next;
		return *this;
	}
	return nullptr;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--(int)
{
	//If current node is not first
	if (m_current->previous != nullptr)
	{
		//Set current node to previous
		m_current = m_current->previous;
		return *this;
	}
	return nullptr;
}

template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	//Checks if nodes are equal and node info
	if (m_current != nullptr && iter.m_current != nullptr && &m_current->data == &iter.m_current->data)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	//Check if current is null
	if (m_current == nullptr || iter.m_current == nullptr)
	{
		return false;
	}
	//Checks if info is equal
	if (&m_current->data != &iter.m_current->data)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline T Iterator<T>::operator*()
{
	return m_current->data;
}


template<typename T>
inline Node<T>* Iterator<T>::getCurrent()
{
	return m_current;
}

template<typename T>
inline void Iterator<T>::setCurrent(Node<T>* input)
{
	m_current = input;
}
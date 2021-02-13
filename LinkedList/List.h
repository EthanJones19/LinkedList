#pragma once
#include "Node.h"
#include "Iterator.h"
#include <iostream>

template<typename T>
class List
{
public:
	List();
	List(const List<T>& other);
	~List();
	void destroy();
	Iterator<T> begin() const;
	Iterator<T> end() const;
	bool contains(const T& object);
	void pushFront(const T& value);
	void pushBack(const T& value);
	bool insert(const T& value, int index);
	bool remove(const T& value);
	void print() const;
	void initialize();
	bool isEmpty() const;
	bool getData(Iterator<T>& iter, int index);
	int getLength() const;
	void sort();

	const List<T>& operator=(const List<T>& other);

protected:
	Node<T>* m_head;
	Node<T>* m_tail;
	int m_nodeCount;
};

template<typename T>
inline List<T>::List()
{
	//Generating new list
	initialize();
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
	//Copying list
	this->m_head = other.m_head;
	this->m_tail = other.m_tail;
	m_nodeCount = other.getLength();
	delete other;
	
	

}

template<typename T>
inline List<T>::~List()
{
	destroy();
}

template<typename T>
inline void List<T>::destroy()
{
	for (int i = 0; i < getLength; i++)
	{
		begin++;
		delete begin* T;
	}
	delete this;
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	return new Iterator(m_head);
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	return new Iterator(m_tail);
}


template<typename T>
inline bool List<T>::contains(const T& object)
{
	//Checks if object is first or last
	if (this->m_first->info == object) return true;
	if (this->m_tail->info == object) return true;

	//Starts iteratoring from front to back
	for (auto i = this->begin(); i != this->end(); i++)
	{
		//Returns true if found
		if (*i == object) return true;
	}
	//Returns false if not found
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	//Create temporary 
	Node<T>* newNode = new Node<T>;
	newNode->data = value;

	//Checks if the current list is empty
	if (this->isEmpty())
	{
		//Makes first and last node equal to the node
		this->m_head = newNode;
		this->m_tail = newNode;
		m_nodeCount++;
		return;
	}
	//Take temporary node, makes it next equal to the first node
	newNode->next = this->m_head;
	//Makes the first nodes previous equal temporary
	this->m_head->previous = newNode;
	//Make temporary first
	this->m_head = newNode;
	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	//Creating temporary node
	Node<T>* newNode = new Node<T>;
	newNode->data = value;

	//Checks if the list is empty
	if (this->m_tail == nullptr)
	{
		//Makes first and last equal to temporary
		this->m_head = newNode;
		this->m_tail = newNode;
		m_nodeCount++;
		return;
	}

	//Make current last equal temporary
	this->m_tail->next = newNode;
	//Make previous equal to last
	newNode->previous = this->m_tail;
	//Makes this list last equal to temporary
	this->m_tail = newNode;
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	// Ensure valid index
	if (isEmpty())
	{
		std::cout << "List Is Empty";
		return false;
	}
	if ((index >= m_nodeCount || index < 0))
	{
		std::cout << "INVALID INDEX GIVEN";
		return false;
	}


	// Create node pointer to hold new value
	Node<T>* temp = new Node<T>(value);

	// Set Current Node to head
	Node<T>* current = m_head;
	// Iterate to index
	for (int i = 0; i < index; i++)
	{
		if (current->next != nullptr)
		{
			current = current->next;
		}
	}

	// Set Previous Nodes Next To temp Node
	current->previous->next = temp;
	//Set Temp Previous to Current Previous
	temp->previous = current->previous;
	//Set Temp Next to current 
	temp->next = current;
	//Set Current Previous to temp 
	current->previous = temp;

	m_nodeCount++;

	std::cout << "INSERTED:" << temp->data << "AT INDEX :" << index << std::endl;
	std::cout << "Between" << temp->next->data << "and" << temp->previous->data;

	return true;

}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	return false;
}

template<typename T>
inline void List<T>::print() const
{
	for (auto i = this->m_head; i != this->m_tail; i++)
	{
		std::cout << *(i).data << std::endl;
	}
}

template<typename T>
inline void List<T>::initialize()
{
	m_head = nullptr;
	m_tail = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	if (getLength() > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	iter = iter + index;
}

template<typename T>
inline int List<T>::getLength() const
{
	return m_nodeCount;
}

//I need help.

//template<typename T>
//inline void List<T>::sort()
//{
//	int i, j; 
//   bool swapped; 
//   for (i = 0; i < getLength; i++)
//   {
//	   swapped = false;
//	   for (j = 0; j < n - i - 1; j++)
//	   {
//		   if(getData(begin, j) < getData(begin, j+ 1))
//		   {
//			   //Setting new value next to current node's next
//			   getData + 1 = this->begin * T->next;
//			   //Setting current node to next to value
//			   this->begin* T->next = value;
//			   //Set current node next's previous to value
//			   this->begin* T->next()->previous = value;
//			   //Increase list length
//			   this->mCount++;
//			   //Set current node to value
//			   begin* T = value;
//		   }
//	   }
//
//	   // IF no two elements were swapped by inner loop, then break 
//	   if (swapped == false)
//		   break;
//   }
//}


template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& other)
{
	this->m_head = other.m_head;
	this->m_tail = other.m_tail;
	m_nodeCount = other.getLength();
	
}



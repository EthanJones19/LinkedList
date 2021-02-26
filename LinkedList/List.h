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
	//Destroys the list
	destroy();
}

template<typename T>
inline void List<T>::destroy()
{
	//Sets the iterator current node to the head
	Node<T>* currentNode = m_head;
	//Sets the iterator next node to null
	Node<T>* nextNode = nullptr;

	//While current node is not null
	while (currentNode != nullptr)
	{
		//Sets next node to current node's next
		nextNode = currentNode->next;
		//Deletes current node
		delete currentNode;
		//Sets current node to the next node
		currentNode = nextNode;
		//Sets the node count to 0
		m_nodeCount = 0;
	}
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	//Returns the iterator head
	return Iterator<T>(m_head);
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	//Returns the iterator tail
	return Iterator<T>(m_tail);
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
	//Makes the first nodes previous equal temporary
	this->m_head->previous = newNode;
	//Take temporary node, makes it next equal to the first node
	newNode->next = this->m_head;
	//Make temporary first
	this->m_head = newNode;
	m_head->previous = nullptr;
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
		//If current's next is not null
		if (current->next != nullptr)
		{
			//Sets current to current's next
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

	//Sets a node count
	m_nodeCount++;

	//Inserts the data
	std::cout << "INSERTED: " << temp->data << " AT INDEX :" << index << std::endl;
	std::cout << "Between " << temp->next->data << " and " << temp->previous->data;

	//Returns true
	return true;

}



template<typename T>
inline bool List<T>::remove(const T& value)
{
	//Sets iterator to head
	Node<T>* iter = m_head;
	
	//If head's data is the same as value
	if (m_head->data == value)
	{
		//If the length is the same as 1
		if (getLength() == 1)
		{
			//Sets head and tail to null
			m_head = nullptr;
			m_tail = nullptr;
			//Delete iterator
			delete iter;
			//Sets node counts negative
			m_nodeCount--;
			//Returns true
			return true;
		}
		//Sets head to iterators next
		m_head = iter->next;
		//Deletes the iterator
		delete iter;
		//Sets the node count negative
		m_nodeCount--;
		//Returns true
		return true;
	}

	//If the tail's data is the same as the value
	if (m_tail->data == value)
	{
		//Sets iterator to the tail
		iter = m_tail;
		//Sets the tail the iterator's previous
		m_tail = iter->previous;
		//Deletes the iterator
		delete iter;
		//Sets the node count negative
		m_nodeCount--;
		//Return true
		return true;
	}

	//Sets the iterator to iterators next
	iter = iter->next;

	//WHile iterator is not null
	while (iter != nullptr)
	{
		//If the iterator's data is the same as value
		if (iter->data == value)
		{
			//Sets iterator's next to iterator's previous
			iter->next->previous = iter->previous;
			//Sets iterator's previous to iterator's next
			iter->previous->next = iter->next;
			//Deletes the iterator
			delete iter;
			//Returns true
			return true;
		}
		else
		{
			//Sets iterator to iterator's next
			iter = iter->next;
		}
	}

}

template<typename T>
inline void List<T>::print() const
{
	//If the list is empty
	if (isEmpty())
	{
		std::cout << " Empty";
		return;
	}

	//Prints the begin if its not the end
	for (Iterator<T> i = this->begin(); i != this->end(); i++)
	{
		std::cout << *i << std::endl;
	}
	std::cout << *(this->end());
}

template<typename T>
inline void List<T>::initialize()
{
	//Sets the head and tail to null
	m_head = nullptr;
	m_tail = nullptr;
	//Sets the nodecount to 0
	m_nodeCount = 0;
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	//If the length is greater than 0
	if (getLength() > 0)
	{
		//Returns false
		return false;
	}
	else
	{
		//Returns false
		return true;
	}
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	//Sets iterator to have a index
	iter = iter + index;
}

template<typename T>
inline int List<T>::getLength() const
{
	//Returns the node count
	return m_nodeCount;
}



template<typename T>
inline void List<T>::sort()
{
	//Sets sorted to false
	bool sorted = false;
	//Sets the current node to head
	Node<T>* currentNode = m_head;
	//Sets the next node to head's next
	Node<T>* nextNode = m_head->next;

	//While the list is being sorted
	while (!sorted)
	{
		//Sets sorted to true
		sorted = true;

		//While next node is not null
		while (nextNode != nullptr)
		{
			//If the current node's data is greater than next node's data
			if (currentNode->data > nextNode->data)
			{
				T data = nextNode->data;
				nextNode->data = currentNode->data;
				currentNode->data = data;
				sorted = false;
			}
			//Sets current node to next node
			currentNode = nextNode;
			//Sets the next node to current node's next
			nextNode = currentNode->next;
		}
	}
}


template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& other)
{
	//This head and tail is set to other head/tail.
	this->m_head = other.m_head;
	this->m_tail = other.m_tail;
	//Sets node count to other length
	m_nodeCount = other.getLength();
	
}



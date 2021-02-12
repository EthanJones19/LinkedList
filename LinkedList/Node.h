#pragma once
template<typename T>
class Node
{
public:
	Node() {};
	Node(T value);

public:
	Node<T>* next;
	Node<T>* previous;
	T data;
};

template<typename T>
inline Node<T>::Node(T value)
{
	data = value;
}

#include "List.h"

int main()
{
	List <int>* _list = new List<int>();
	_list->pushFront(1);
	_list->pushFront(2);
	_list->pushFront(3);
	std::cout << _list->getLength();
	_list->pushBack(4);
	_list->pushBack(5);
	_list->pushBack(6);
	std::cout << _list->getLength();
	_list->insert(7, 5);
	std::cout << _list->getLength();
	return 0;
}
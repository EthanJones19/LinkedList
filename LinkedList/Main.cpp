#include <iostream>
#include "List.h"



int main()
{
	List <int>* _list = new List<int>();
	_list->pushFront(2);
	_list->pushFront(1);
	_list->pushFront(3);
	_list->pushFront(15);
	_list->pushFront(-8);
	_list->pushFront(5);
	_list->insert(4, 1);
	std::cout << std::endl;
	_list->print();
	_list->remove(4);
	_list->sort();
	std::cout << "\n";
	_list->print();
	system("pause");
	return 0;


}
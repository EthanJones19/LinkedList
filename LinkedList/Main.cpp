#include "List.h"

int main()
{
	List <int>* _list = new List<int>();
	_list->pushFront(1);
	_list->pushFront(2);
	_list->pushFront(3);
	_list->insert(4, 1);
	return 0;
}
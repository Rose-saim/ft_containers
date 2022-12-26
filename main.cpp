#include <iostream>
#include <map>
#include "map/AVL.hpp"
#include "map/AVL_iterator.hpp"
#include "map/map.hpp"

int main() {
	ft::map<int, int> test;
	ft::pair<int, int> key(1,1);
	ft::pair<int, int> key2(2,2);
	ft::pair<int, int> key3(3,3);
	ft::pair<int, int> key4(4,4);
  	ft::map<int, int>::iterator it;

	it = test.begin();
	it = test.insert(it, key2);
	it = test.insert(it, key);

	//insert is wrong
	it = test.insert(it, key4);
	it = test.insert(it, key3);
	std::cout << "test: " << (it)->first << std::endl;
	it++;
	std::cout << "test: " << it->first << std::endl;
	it--;
	std::cout << "test: " << (*it).first << std::endl;
	std::cout << "test: " << (it)->first << std::endl;
	test.erase(it);
	std::cout << "test: " << it->first << std::endl;
	it++;
	it++;
} 

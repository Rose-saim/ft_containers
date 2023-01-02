#include <iostream>
#include <map>
#include "AVL.hpp"
#include "AVL_iterator.hpp"
#include "map.hpp"

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

  	ft::map<int, int>::const_iterator ct_it;
	const ft::map<int, int> test_c(test);

	ct_it = test_c.begin();
	std::cout << "test: " << (it)->first << std::endl;
	std::cout << "test: " << (ct_it) ->first << std::endl;
	
	// //insert is wrong
	it = test.insert(it, key4);
	it = test.insert(it, key3);
	it++;
	std::cout << "test: " << (it)->first << std::endl;
	
	it++;
	std::cout << "test: " << it->first << std::endl;
		std::cout << "test: " << it._root->parent->getData().first << std::endl;
		std::cout << "test: " << (*it).first << std::endl;
		it--;
		std::cout << "test_end: " << it._root->parent->getData().first << std::endl;
} 

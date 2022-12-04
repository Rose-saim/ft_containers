#include <iostream>
#include "AVL.hpp"
#include <map>
#include "AVL_iterator.hpp"
#include "map.hpp"

	// void	printTree(ft::AVL_node<int, int, std::allocator< ft::pair<const int, int> > >  *root, std::string indent, bool last)
	// {
	// 	std::cout << indent;
	// 		if (last)
	// 		{
	// 			std::cout << "R----";
	// 			indent += "    ";
	// 		}
	// 		else
	// 		{
	// 			std::cout << "L----";
	// 			indent += "    ";
	// 		}
	// 		// std::cout << "STEP 2" << std::endl;
 	// 	std::cout << root->key() << std::endl;
    // if (root->right)
	// 	  printTree(root->right, indent, true);
    // if (root->left)
  	// 	printTree(root->left, indent, false);
	// }

int main() {
	ft::map<int, int> test;
  	std::cout << "Construct test " << std::endl;
	ft::pair<int, int> key(1,1);
	ft::pair<int, int> key2(2,2);
	ft::pair<int, int> key3(3,3);
	ft::pair<int, int> key4(1,1);
  	std::cout << "Construct test iterator" << std::endl;
  	ft::map<int, int>::iterator it = test.begin();
	it = test.insert(it, key);
  	std::cout << "NODE after insert!: " << it._root->getData() << std::endl;
  	// std::cout << "NODE after insert!: " << it.key() << std::endl;
  	// std::cout << "NODE after insert!: " << it.key() << std::endl;
	//insert is wrong
	it = test.insert(it, key2);
  	// std::cout << "NODE after insert: " << it._root->right->getData() << std::endl;
	// it = test.insert(it, key3);
  	// std::cout << "NODE after insert: " << it._root->getData() << std::endl;
	// it = test.insert(it, key4);
  	// std::cout << "NODE after insert: " << it._root->getData() << std::endl;
// //   std::cout << "END: " << it_test._root->key() << std::endl;
// 	it = test.begin();
// 	std::cout << it.key() << std::endl;
// 	for (int i = 0; i < 5; i++)
// 	{
// 		if (it.right != NULL)
// 			std::cout << it.key() << std::endl;
// 		else
// 			std::cout << "No POSSIBLE" << std::endl;
// 	}
} 

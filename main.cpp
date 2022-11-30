#include <iostream>
#include "AVL.hpp"
#include <map>
#include "AVL_iterator.hpp"
#include "map.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

	void	printTree(ft::AVL_node<int, int, std::allocator< ft::pair<const int, int> > >  *root, std::string indent, bool last)
	{
		std::cout << indent;
			if (last)
			{
				std::cout << "R----";
				indent += "    ";
			}
			else
			{
				std::cout << "L----";
				indent += "    ";
			}
			// std::cout << "STEP 2" << std::endl;
 		std::cout << root->key() << std::endl;
    if (root->right)
		  printTree(root->right, indent, true);
    if (root->left)
  		printTree(root->left, indent, false);
	}

int main() {
	ft::map<int, int> test;
	ft::pair<int, int> key(1,1);
	ft::pair<int, int> key2(2,2);
	ft::pair<int, int> key3(3,3);
	ft::pair<int, int> key4(4,4);
  	ft::map<int, int>::iterator it = test.begin();
	//insert is wrong
	test.insert(it, key);
	test.insert(it, key2);
  	std::cout << it.key() << std::endl;
	test.insert(it, key3);
	test.insert(it, key4);
//   std::cout << "END: " << it_test._root->key() << std::endl;
	it = test.begin();
	for (int i = 0; i < 5; i++)
	{
		if (it.right != NULL)
			std::cout << it.right->key() << std::endl;
		else
			std::cout << "No POSSIBLE" << std::endl;
	}
} 

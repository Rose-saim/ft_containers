#include <iostream>
#include "AVL.hpp"
#include "AVL_iterator.hpp"
#include "map.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

	// void	printTree(ft::AVL<int, int, std::less<int>, std::allocator< std::pair<const int, int> > >  *root, std::string indent, bool last)
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
  //   if (root->right)
	// 	  printTree(root->right, indent, true);
  //   if (root->left)
  // 		printTree(root->left, indent, false);
	// }

int main() {
  ft::map<int, int> test;
  ft::map<int, int>::iterator it_test;
}
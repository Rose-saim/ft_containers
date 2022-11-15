#include <iostream>
#include "AVL.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main() {
  AVL<int, int, std::less<int>, std::allocator< std::pair<const int, int> > > *root = NULL;
  ft::pair<int, int>test1(1, 5);
  // ft::pair<int, int>test2(2, 6);
  // ft::pair<int, int>test3(3, 7);
  // ft::pair<int, int>test4(4, 50);
  // ft::pair<int, int>test5(5, 15);
  // ft::pair<int, int>test6(6, 32);
  // ft::pair<int, int>test7(7, -5);
  root->insertNode((root), test1);
  // root->insertNode(&root, test2);
  // root->insertNode(&root, test3);
  // root->insertNode(&root, test4);
  // root->insertNode(&root, test5);
  // root->insertNode(&root, test6);
  // root->insertNode(&root, test7);
  // root->printTree(root, "", true);
  // root->deleteNode(root, 13);
  std::cout << "After deleting " << std::endl;
  // root->printTree(root, "", true);
}
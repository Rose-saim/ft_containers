#include <iostream>
#include <map>

	// void	printTree(std::map *root, std::string indent, bool last)
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
	std::map<int, int> test;
	std::pair<int, int> key(1,1);
	std::pair<int, int> key2(2,2);
	std::pair<int, int> key3(3,3);
	std::pair<int, int> key4(4,4);
	std::map<int, int>::iterator *it = test.begin();
  // std::cout << it->second << std::endl;
	test.insert(*it, key);
  std::cout << *it->first << std::endl;
	// test.insert(it, key2);
	// test.insert(it, key3);
	// test.insert(it, key4);

} 

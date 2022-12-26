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
	std::pair<int, int> key5(5,5);
	std::pair<int, int> key6(6,6);
	std::pair<int, int> key7(7,7);
	std::map<int, int>::iterator it = test.begin();
  // std::cout << it->second << std::endl;
	it = test.insert(it, key);
	it = test.insert(it, key2);
	it = test.insert(it, key3);
	it = test.insert(it, key4);
	it = test.insert(it, key5);
	it = test.insert(it, key6);
	it = test.insert(it, key7);
	it = test.begin();
  std::cout << it->first << std::endl;
	it++;
  std::cout << it->first << std::endl;

	// test.insert(it, key2);
	// test.insert(it, key3);
	// test.insert(it, key4);

} 

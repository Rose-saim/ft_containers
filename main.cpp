#include "vector.hpp"

int main()
{
	vector<int> v;
	vector<int> ran;

	for (int i = 0; i < 10; i++)
	{	
		v.push_back(i);
	}
	std::cout << "====PRINT_LIST_CREAT====" << std::endl;
	v.print();
	v.pop_back();
	std::cout << "====PRINT_POP_LAST_VALUE====" << std::endl;
	v.print();
	std::cout << "====PRINT_FIRST_VALUE====" << std::endl;
	std::cout << v.begin() << std::endl;
	std::cout << "====PRINT_LAST_VALUE====" << std::endl;
}
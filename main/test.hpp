#ifndef TEST_HPP
#define TEST_HPP

# define RED "\e[1;31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define PURPLE "\e[35m"
# define RESET "\e[0;38m"

# include <vector>
# include <stack>
# include <map>
# include "vector.hpp"
# include "stack.hpp"
# include "map.hpp"
# include <iostream>
# include <fstream>

int	test_vector(void);
int	test_stack(void);


template <typename T>
void	printAttributes(VECTOR<T>& vec, std::ofstream& ofs)
{
	ofs << "size: " << vec.size() << " ";
	ofs << "capacity: " << vec.capacity() << std::endl;
}

template <typename T>
void	printVector(VECTOR<T>& vec, std::ofstream& ofs)
{
	printAttributes(vec, ofs);

	for (typename ft::vector<T>::size_type i = 0; i < vec.size(); i++)
		ofs << "[" << vec[i] << "]";
	ofs << std::endl;
}

class Object
{
	public:
	int		a;
	char	b;
	double	c;
	void*	d;
};

template <typename Iterator>
void	printPair(Iterator& x, std::ofstream &ofs)
{
	ofs << "(" << x->first << ") (" << x->second << ")" << std::endl;
}

template <class M>
void	printSize(M& src, std::ofstream& ofs)
{
	ofs << "size: " << src.size() << std::endl;
	ofs << "max_size: " << src.max_size() << std::endl;
}

template <class M>
void	printAttributes(M& src, std::ofstream& ofs)
{
	ofs << "------------Print--------------" << std::endl;
	printSize(src, ofs);
	ofs << std::boolalpha;
	
	ofs << "empty : " << src.empty() << std::endl;
	ofs << "Content :" << std::endl;
	
	for (typename M::iterator it = src.begin(); it != src.end(); it++)
		ofs << "[" << it->first << "] [" << it->second << "]" << std::endl;
	
	ofs << "-------------------------------" << std::endl;
}

#endif

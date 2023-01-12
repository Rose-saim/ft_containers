#ifndef UTILS_HPP
# define UTILS_HPP
# include "iterator_traits.hpp"

namespace ft {

template <class Iterator>
int	distance(Iterator first, Iterator last)
{
	int count = 0;
	while (first != last)
	{
		first++;
		count++;
	}
	return (count);
}

class NullPtr
{
	public:
		template <class T>
		operator T*() const { return (0); }
		template <class C, class T>
		operator T* C::*() const { return (0); }
	private:
		void operator&() const;
} NullPtr = {};

std::string	itoa(long long int number)
{
	std::string dest;
	bool	negative = false;

	if (number < 0)
	{
		negative = true;
		number *= -1;
	}
	while (number > 9)
	{
		dest.insert(dest.begin(), (number % 10) + 48);
		number = number / 10;
	}
	dest.insert(dest.begin(), (number % 10) + 48);
	if (negative == true)
		dest.insert(dest.begin(), '-');
	
	return (dest);
}

template <class T>
void	swapp(T& a, T& b)
{
	T c(a);
	
	a = b;
	b = c;
}

}

#endif

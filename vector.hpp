#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <iostream>
# include <memory>
# include <iterator>
# include "random_access_iterator.hpp"
# include "random_access_iterator_reverse.hpp"

template <class T, class Allocator = std::allocator<T> >
class vector
{
	private:
		Allocator	alloc;
		int capacity;
		int current;
		T*	arr;
public:
	typedef random_access_iterator<T>               iterator;

	vector(): capacity(1), current(0)
	{
		std::cout << "Create vector" << std::endl;
		arr = alloc.allocate(capacity);
	}
	~vector()
	{
		std::cout << "Destroy vector" << std::endl;
		if (arr)
		{
			alloc.deallocate(arr, capacity-1);
		}
	}
	void	push_back(T data)
	{
		if (current == capacity)
		{
			T* temp = alloc.allocate(capacity * 2);
			for (int i = 0; i < capacity; i++)
			{
				temp[i] = arr[i];
			}
			alloc.deallocate(arr, capacity-1);
			capacity *= 2;
			arr = temp;	
		}
		arr[current] = data;
		++current;
	}
	void	pop_back()
	{
		alloc.destroy(arr + current);
		--current;
	}
	void	print()
	{
		for (int i = 0; i < current; i++)
		{
			std::cout << arr[i] << " |";
		}
		std::cout << std::endl;
	}
	iterator	begin()	{ return iterator(arr);}
	const_iterator	begin()const	{ return (arr);}
	iterator	end()	{ return (arr + current);}
	const_iterator	end()const	{ return (arr + current);}
};

#endif
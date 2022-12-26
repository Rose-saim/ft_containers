#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <iostream>
# include <memory>
# include <iterator>
#include <list>
#include <stdexcept>
#include <unistd.h>
#include <exception>
# include "./enable_if.hpp"
# include "./is_integral.hpp"
# include "./random_access_iterator.hpp"
# include "./random_access_iterator_reverse.hpp"

namespace ft
{

template <class T, class Allocator = std::allocator<T> >
class vector
{
	#define	$ft_free(ARRAY, _CAPACITY)	_Base.deallocate(ARRAY, _CAPACITY)
	#define	$ft_put(ELEM, VAL)			_Base.construct(ELEM, VAL)
	#define	$ft_erase(ELEM)			_Base.destroy(ELEM)
	#define	$ft_get(SIZE)				_Base.allocate(SIZE)
	#define	$clear_erase				clear(); \
										$ft_free(_array, _capacity)
	#define $ft_range(RET, FIRST, LAST) \
	for (InputIterator tmp = FIRST;tmp != LAST;tmp++) \
		RET++;
	public:
	/* ========================================================================== */	
	/* ===============  -- Member types --            ============================== */
	/* ========================================================================== */	
	
		typedef	T												value_type;
		typedef	Allocator										allocator_type;
		typedef typename	allocator_type::reference			reference;
		typedef typename	allocator_type::const_reference		const_reference;
		typedef typename	allocator_type::pointer				pointer;
		typedef typename	allocator_type::const_pointer		const_pointer;
		typedef ft::random_access_iterator<T>               	iterator;
		typedef ft::random_access_iterator_rev<T>               rev_iterator;
		typedef ft::random_access_iterator<const T>             const_iterator;
		typedef ft::random_access_iterator_rev<const T>         const_rev_iterator;
		typedef	std::size_t										size_type;
		typedef	std::ptrdiff_t									difference_type;

	/* ========================================================================== */	
	/* ===============  -- Member functions --            ============================== */
	/* ========================================================================== */	

	explicit vector(const allocator_type& alloc = allocator_type()): pos(0), _capacity(0), _array($ft_get(0)){(void)alloc;}

	vector(const vector &x) :pos(x.pos), _Base(x._Base), _capacity(x._capacity)
	{
		std::cout << "Create" << std::endl;
		_array = $ft_get(_capacity);
		size_type i = 0;
		for (const_iterator beg(x.begin());beg != x.end();beg++)
		{
			$ft_put(&_array[i], *beg);
			i++;
		}
	}
	
	explicit vector(size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()): pos(n), _Base(alloc), _capacity(n), _array($ft_get(n))
	{
		std::cout << "Create" << std::endl; 
		for (size_type i = 0; i < pos;i++)
			$ft_put(&_array[i], val);
	}

	template <class InputIterator>
	vector(InputIterator first,	InputIterator last, const allocator_type& alloc = allocator_type(),
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL): pos(0), _Base(alloc) 
	{
		std::cout << "Create" << std::endl; 
		for (InputIterator tmp = first;tmp != last;tmp++)
			pos++;
		_capacity = pos;
		_array = $ft_erase(_capacity);
		int i = 0;
		while (first != last)
		{ $ft_put(&_array[i], *first);first++;i++; }
	}

	~vector()
	{
		$clear_erase;
	}

	vector	&operator=(const vector &x)
	{
		if (x == *this)
			return (*this);
		clear();
		pos = x.pos;
		_Base = x._Base;
		_capacity = x._capacity;
		_array = x._array;
		std::cout << x._array[0] << std::endl;
		// insert(end, x.begin(), x.end());
		return (*this);
	}

	/* ========================================================================== */	
	/* ===============  -- Iterators --            ============================== */
	/* ========================================================================== */	

	iterator			begin()	{ return (iterator(_array));}
	const_iterator		begin()const	{ return (const_iterator(_array));}
	rev_iterator		rbegin()	{ return (rev_iterator(_array + pos - 1));}
	const_rev_iterator	rbegin()const	{ return (rev_iterator(_array + pos - 1));}
	iterator			end()	{ return iterator(_array + pos);}
	const_iterator		end()const	{ return (_array + pos);}
	rev_iterator		rend()	{ return (iterator(_array + pos));}
	const_rev_iterator	rend()const	{ return (iterator(_array + pos));}
	
	/* ========================================================================== */	
	/* ===============  -- _Capacity --            ============================== */
	/* ========================================================================== */	
	bool	empty() const { return (!pos); }
	size_type size() const { return (pos); };
	size_type max_size() const { return (_Base.max_size()); };
	void resize (size_type n, value_type val = value_type())
	{
		if (n > _capacity)
            reserve(n);
        while (n > pos)
            push_back(val);
        while (n < pos)
            pop_back();
	}
	size_type	capacity() const 	{ return (_capacity); } 
	void reserve (size_type n)
	{
		if (n > max_size())
			throw std::length_error("vector");
		if (n <= _capacity)
			return ;
		_capacity = n;
		T* copy = $ft_get(_capacity);
		for (size_type i = 0;i < pos;i++)
			$ft_put(&copy[i], _array[i]);
		size_t old_pos = pos;
		$clear_erase;
		_array = copy;
		pos = old_pos;
	}

	/* ========================================================================== */	
	/* ===============  -- Elements access --            ============================== */
	/* ========================================================================== */	
	
	const_reference operator[] (size_type n) const{ return (_array[n]);}
	const_reference at (size_type n)const
	{
		if (n > pos)
			throw std::out_of_range("vector");
		return (_array[n]);

	}
	const_reference front() const { return (_array[0]); }
	const_reference back() const { return (_array[pos - 1]); } 
	reference operator[] (size_type n) { return (_array[n]);}
	reference at (size_type n)
	{
		if (n > pos)
			throw std::out_of_range("vector");
		return (_array[n]);

	}
	reference front() { return (_array[0]); }
	reference back() { return (_array[pos - 1]); } 

	/* ========================================================================== */
	/* ===============  -- Modifiers --       	   ============================== */
	/* ========================================================================== */
			void assign(size_type n, const value_type& val)
			{
				if (n > _capacity)
				{
					clear();
					for (size_type i = 0;i < n;i++)
						push_back(val);
				}
				else
				{
					for (size_type i = 0;i < _capacity;i++)
					{
						if (i < n)
							$ft_put(&_array[i], val);
						else
							$ft_erase(&_array[i]);
					}
					pos = n;
				}
			}

			template <class InputIterator>
			void assign(typename ft::enable_if<!is_integral<InputIterator>::value,
				InputIterator>::type first, InputIterator last)
			{
				(void)last;
				size_type n = 0;
				$ft_range(n, first, last);
				if (n > _capacity)
				{
					clear();
					for (size_type i = 0;i < n;i++)
						{ push_back(*first);first++; }
				}
				else
				{
					for (size_type i = 0;i < _capacity;i++)
					{
						if (i < n)
							{ $ft_put(&_array[i], *first);first++; }
						$ft_erase(&_array[i]);
					}
					pos = n;
				}
			}

	void	push_back(const value_type& val)
	{
		if (_capacity == 0)
		{
			$clear_erase;
			_capacity += 1;
			_array = $ft_get(_capacity);
		}
		else if (_capacity == pos)
		{
			_capacity *= 2;
			T* temp = $ft_get(_capacity);
			for (size_type i = 0; i < pos; i++)
			{
				$ft_put(&temp[i], _array[i]);
			}
			size_type	t_pos = pos;
			$clear_erase;
			pos = t_pos;
			_array = temp;	
		}
		$ft_put(&_array[pos], val);
		++pos;
	}

	void	pop_back()
	{
		if (empty())
			return ;
		$ft_erase(&_array[pos - 1]);
		--pos;
	}

	void insert (iterator position, size_type n, const value_type& val)
	{
		__INSERT__DEFAULT__ = true;
		size_type new_capacity = _capacity + n  == _capacity ? _capacity : _capacity + n;
		if (new_capacity > max_size())
			throw std::length_error("vector");
		T* new_array = $mem_get(new_capacity);
		size_type start = position - begin();
		size_type i = 0;
		size_type y = 0;
		while (i < new_capacity)
		{
			if ((i < start) || (i >= start + n))
			{
				$mem_put(&new_array[i], _array[y]);
				y++;
			}
			else if (__INSERT__DEFAULT__)
				$mem_put(&new_array[i], val);
			i++;
		}
		size_type old_pos = pos;
		clear();
		_array  = new_array;
		_capacity = new_capacity;
		pos = old_pos + n;
	}

	iterator insert (iterator position, const value_type& val)
	{
		__INSERT__DEFAULT__ = true;
		size_type offset = position - begin();
		insert(position, 1, val);
		return (iterator(&_array[offset]));
	}

	template <class InputIterator>
	void	insert(iterator position, InputIterator first, InputIterator last,
		typename enable_if<!is_integral<InputIterator>::value >::type* = 0)
	{
		__INSERT__DEFAULT__ = false;
		size_type n = 0;
		size_type start = position - begin();
		size_type i = 0;
		InputIterator count(first);
		while (count != last)
			{ count++; n++; }
		InputIterator val(first);
		insert(position, n, *first);
		while (i < _capacity)
		{
			if (!(i < start || i >= start + n))
			{ $mem_put(&_array[i], *val); val++;}
			i++;
		}
	}

	iterator erase(iterator first, iterator last)
	{
		size_type offset = first - begin();
		if (last < end())
		{
			iterator i(first);

			size_type last_index = static_cast<size_type>(last - begin());
			size_type loc = 0;
			for (const_iterator beg = begin();beg != first;beg++)
				loc++;
			iterator _end = end();
			while (i != _end)
			{
				if (i <= last)
					$ft_erase(&_array[loc]);
				if (last_index < pos)
					$ft_put(&_array[loc], _array[last_index]);
				loc++;
				last_index++;
				i++;
			}
			pos -= static_cast<size_type>(last - first);	
		}
		else
		{
			while (pos != offset)
				pop_back();
		}
		return (iterator(&_array[offset]));
	}

	iterator erase(iterator position){ return (erase(position, position+1));}
	
	void swap (vector& x)
	{
		std::swap(_Base, x._Base);
		std::swap(_array, x._array);
		std::swap(pos, x.pos);
		std::swap(_capacity, x._capacity);
	}
	void	clear()
	{
		while (!empty())
			pop_back();
	}


	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	private:	
		bool			___INSERT__DEFAULT__;	
		size_t			pos;
		allocator_type	_Base;
		size_type		_capacity;
		pointer			_array;

};
}
#endif

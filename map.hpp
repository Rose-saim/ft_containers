#ifndef MAP_HPP
#define MAP_HPP

# include <iostream>
# include <memory>
# include <iterator>
#include <list>
#include <stdexcept>
#include <unistd.h>
#include <exception>
#include <memory>
#include "pair.hpp"
#include "AVL.hpp"
#include "AVL_iterator.hpp"


namespace ft
{
		template <class Arg1, class Arg2, class Result>
  	struct binary_function {
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result result_type;
  	};

	template <class T> struct less : binary_function <T,T,bool> {
	  bool operator() (const T& x, const T& y) const {return x<y;}
	};
	template < class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef	Key																key_type;
			typedef	T																mapped_type;
			typedef	ft::pair<const Key, T>			 								value_type;
			typedef	size_t															size_type;
			typedef	Compare															key_compare;
			typedef	Allocator														allocator_type;
			typedef	typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference						const_reference;
			typedef	typename allocator_type::pointer								pointer;
			typedef	typename allocator_type::const_pointer							const_pointer;
			typedef	typename ft::AVL<Key, T, Compare, Allocator>::iterator				iterator;
			// typedef	typename ft::AVL<const Key, T, Compare, Allocator>::const_iterator	const_iterator;
		private:
				key_compare		_compare;
				allocator_type	_alloc;
				size_type		_size;
				iterator			*_root;
				iterator			*_end;
				iterator			*_rend;
		public:
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/***********************************************************CONSTRUCTOR***********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			explicit map( const key_compare &cmp = key_compare(), const Allocator &alloc = Allocator() ):
				_compare(cmp), _alloc(alloc), _size(0), _root(NULL), _end(NULL), _rend(NULL)
			{
				std::cout << "Construct map" << std::endl;
			}
			template< typename InputIt >
			map( InputIt first, InputIt last, const key_compare &cmp = key_compare(),
					const Allocator &alloc = Allocator() ):
				_compare(cmp), _valueAlloc(alloc)
			{
				this->insert(first, last);
			}
			map( const map& other )
			{
				*this = other;
			}
			~map()
			{
				std::cout << "Destruct map" << std::endl;
			}

			map&	operator=(const map& other)
			{
				if (this != &other)
				{
					this->_rbTree = other._rbTree;
					this->_comparator = other._comparator;
					this->_valueAlloc = other._valueAlloc;
				}
				return (*this);
			}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************ITERATORS***********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		iterator	begin() {return *_root;}
		// iterator		begin() {return iterator(this->parent);}
		// const_iterator	end() {return const_iterator(this->parent);}
		iterator		end() {return TreeMaximum(this);}
		// iterator		rbegin() {return iterator(this->parent);}
		// iterator		rend() {return TreeMaximum(this);}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************CAPACITY************************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		bool	empty(void)
		{
			if (_size == 0)
				return 1;
			return 0;	
		}

		size_type	size()
		{
			return (_size);
		}

		size_type	max_size()
		{
			return (_alloc.max_size());
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/*********************************************************ELEMENT ACCESS*********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
			// map&	operator[](const key_type& key)
			// {
			// 	return (*)
			// }
			
			// map&	&at[](const key_type& key)
			// {
			// 	iterator	it = this->find(key);
			// 	return (*)
			// }

			// map&	operator[](const key_type& key)
			// {
			// 	return (*)
			// }

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************MODIFIERS***********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************OBSERVERS***********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************OPERATIONS**********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************ALLOCATOR**********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		




			private:
				key_compare	_comparator;
				allocator_type	_valueAlloc;
	};
}


#endif

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
			typedef	Key																	key_type;
			typedef	T																	mapped_type;
			typedef	ft::pair<const Key, T>			 									value_type;
			typedef	size_t																size_type;
			typedef	Compare																key_compare;
			typedef	Allocator															allocator_type;
			typedef	typename allocator_type::reference									reference;
			typedef typename allocator_type::const_reference							const_reference;
			typedef	typename allocator_type::pointer									pointer;
			typedef	typename allocator_type::const_pointer								const_pointer;
			typedef	typename ft::AVL<Key, T, Compare, Allocator>::iterator				iterator;
			typedef	typename ft::AVL<const Key, T, Compare, Allocator>::const_iterator	const_iterator;
			typedef typename ft::AVL_node<Key, T, Allocator>							*nodePtr;
		// private:
				key_compare								_compare;
				allocator_type							_alloc;
				size_type								_size;
				ft::AVL<Key, T, Compare, Allocator>		tree;
				nodePtr									node_ptr;
				iterator								*_ite;
		public:
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/***********************************************************CONSTRUCTOR***********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			explicit map(const key_compare &cmp = key_compare(), const Allocator &alloc = allocator_type()):
				 _compare(cmp), _alloc(alloc), _size(0), node_ptr(NULL)
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
					this->_alloc = other._alloc;
					this->_size = other._size;
					this->tree = other.tree;
					this->_ite = other._ite;
				}
				return (*this);
			}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************ITERATORS***********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		iterator		begin() {return tree.begin();}
		const_iterator	begin()const {return tree.begin();}
		iterator		end() {return tree.end();}
		const_iterator	end()const {return tree.end();}
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
			

			// map&	operator[](const key_type& key)
			// {
			// 	return (*)
			// }

			// map&	&at[](const key_type& key)
			// {
			// 	iterator	it = this->find(key);
			// 	return (*)
			// }

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************MODIFIERS***********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		pair<iterator,bool> insert(const value_type& val)
		{
			nodePtr	o_node = tree.search(val);
			(void)o_node;
			if (tree.ite_ptr)
			{
				std::cout << "===============================!" << std::endl;
				iterator pos(tree._node, tree.insert(val), false);
				std::cout << "===============================!" << std::endl;
				std::cout << "HERE!" << std::endl;
				// ft::pair<iterator, bool> value_1(ft::make_pair(pos, false), false);
				// std::cout << "===============================!" << std::endl;
				// std::cout << "HERE!" << std::endl;
		  		// return(value_1);
			}
			ft::pair<iterator, bool> value_2 = ft::make_pair(iterator(tree._node, tree.insert(val), false), true);
			std::allocator<iterator> _loc;
		  	tree.ite_ptr = _loc.allocate(1);
		  	_ite = _loc.allocate(1);
			tree.ite_ptr->_root = tree._node;
			_ite->_root = tree._node;
		  	return(value_2);
		}
		template <class InputIterator> 
		void insert (InputIterator first, InputIterator last)
		{
			while ( (first != last))
			{
				insert(*first);
				++first;
			}
			
		};
		iterator insert(iterator position, const value_type& val)
		{
			(void)position;
				std::cout << "I'm here3 !" << std::endl;
			insert(val);
				std::cout << "I'm here3 !" << std::endl;
			std::cout << "NODE::" << this->tree._node->getData() << std::endl;
  			return (*_ite);
		}

		void erase (iterator position);
		size_type erase (const key_type& k);
   		void erase (iterator first, iterator last);

		void swap (map& x)
		{
			nodePtr			*tmp;
			size_type		tmpSize;
			if (x == *this)
				return ;
			tmp = x.node_ptr;
			tmpSize = x._size;
			x.node_ptr = this->node_ptr;
			x._size = this->_size;
			this->_size = tmpSize;
			this->node_ptr = tmpSize;
		}

		void clear() {this->erase(begin(), end());}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************OBSERVERS***********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		key_compare key_comp() const;
		// value_compare value_comp() const;
		
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************OPERATIONS**********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		iterator find (const key_type& k);
		const_iterator find (const key_type& k) const;
		size_type count (const key_type& k) const;
		iterator lower_bound (const key_type& k);
		const_iterator lower_bound (const key_type& k) const;
		iterator upper_bound (const key_type& k);
		const_iterator upper_bound (const key_type& k) const;
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
		pair<iterator,iterator>             equal_range (const key_type& k);
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************ALLOCATOR**********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			allocator_type get_allocator() const;
			private:
				key_compare	_comparator;
				allocator_type	_valueAlloc;
	};
}


#endif

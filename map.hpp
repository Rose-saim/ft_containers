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
		// private:
				key_compare								_compare;
				allocator_type							_alloc;
				size_type								_size;
				ft::AVL<Key, T, Compare, Allocator>		*_root;
				iterator								*node;
				iterator								_node;
		public:
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/***********************************************************CONSTRUCTOR***********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			explicit map(const key_compare &cmp = key_compare(), const Allocator &alloc = allocator_type()):
				 _compare(cmp), _alloc(alloc), _size(0), _root(NULL)
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
					this->_root = other._root;
					this->_node = other._node;
				}
				return (*this);
			}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************ITERATORS***********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		iterator		begin() {iterator *it = _node.MinValue(); return *it;}
		const_iterator	begin()const {const_iterator *it = _node.MinValue();return *it;}
		iterator		end() {iterator *it = _node.MaxValue();return *it;}
		const_iterator	end()const {iterator *it = _node.MaxValue();return *it;}
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
		iterator insert (iterator position, const value_type& val)
		{
			node = &position;
			// if (!node)
			// {
				node = position.newNode(val);
				position = *node;
				std::cout << "NODE: "<< position.key()  << std::endl;			
				std::cout << "NODE: "<< node->key()  << std::endl;			
				return *node;
			// }
			// if (key.second < node->key())
			// {
			// 	node->left = insertNode(node->left, key);
			// }
			// else if (key.second > node->key())
			// {
			// 	node->right = insertNode(node->right, key);
			// }
			// else 
			// 	return node;

			// node->_height = 1 + node->max(node->height(node->left), node->height(node->right));
			// int	balanceFactor = getBalanceFactor(node);
			// if (balanceFactor > 1)
			// {
			// 	if (key.second < node->left->key())
			// 		return node->rightRotate(node);
			// 	else if (key.second > node->left->key())
			// 	{
			// 		node->left = node->leftRotate(node->left);
			// 		return node->rightRotate(node);	
			// 	}
			// }
			// if (balanceFactor < -1)
			// {
			// 	if (key.second > node->right->key())
			// 		return node->leftRotate(node);
			// 	else if (key.second < node->right->key())
			// 	{
			// 		node->right = node->rightRotate(node->right);
			// 		return node->leftRotate(node);	
			// 	}
			// }
			// return node;
			// node = this->_root->insertNode(&position, val);
			// _node =*( this->_root->insertNode(&position, val));
			// std::cout << "NODE: "<< node->key()  << std::endl;
			// std::cout << "NODE: "<< _node.key()  << std::endl;
			// // _node = position;
			// // _node.setBegin(true);
			// return _node;
		}
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

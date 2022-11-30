#ifndef AVL_HPP
# define AVL_HPP

# include "pair.hpp"
# include "AVL_iterator.hpp"
#include <memory>
#include <iostream>
#include <string>

namespace ft
{
	template<class Key, class Value, class Compare, class Alloc = std::allocator< ft::pair<const Key, Value> > >
class AVL
{
	// private:
	public:
		typedef	Key										key_type;
		typedef	ft::pair<Key, Value>					pair_type;
		typedef size_t									size_type;
		typedef Value									value_type;
		typedef	Alloc									allocator_type;
		typedef ft::AVL_node<Key, Value, Alloc>			iterator;
		typedef ft::AVL_node<const Key, Value, Alloc>	const_iterator;
		size_t					_height;
		pair_type				_data;
		iterator				_node;
		AVL(): _height(1), _data(ft::make_pair(0,0)){};
		~AVL(){
			std::cout << "Destructor AVL" << std::endl;
		};
		
		int	getBalanceFactor(iterator *N)
		{
			if (!N)
				return 0;
			return (N->height(N->left) - N->height(N->right));
		}

		iterator	*insertNode(iterator *node, pair_type key)
		{
			if (!node)
			{
				node = node->newNode(key);
				std::cout << "NODE: "<< node->key()  << std::endl;			
				return node;
			}
			if (key.second < node->key())
			{
				node->left = insertNode(node->left, key);
			}
			else if (key.second > node->key())
			{
				node->right = insertNode(node->right, key);
			}
			else 
				return node;

			node->_height = 1 + node->max(node->height(node->left), node->height(node->right));
			int	balanceFactor = getBalanceFactor(node);
			if (balanceFactor > 1)
			{
				if (key.second < node->left->key())
					return node->rightRotate(node);
				else if (key.second > node->left->key())
				{
					node->left = node->leftRotate(node->left);
					return node->rightRotate(node);	
				}
			}
			if (balanceFactor < -1)
			{
				if (key.second > node->right->key())
					return node->leftRotate(node);
				else if (key.second < node->right->key())
				{
					node->right = node->rightRotate(node->right);
					return node->leftRotate(node);	
				}
			}
			return node;
		}
};


}




#endif

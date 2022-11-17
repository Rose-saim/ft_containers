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
		typedef	Alloc 									allocator_type;
		typedef ft::AVL_iterator<Key, Value, Compare, Alloc>	iterator;
		typedef ft::AVL_node<Key, Value, Compare, Alloc>	node;
		iterator	*_root;
		AVL()
		{
			std::cout << "okok" << std::endl;
		}
		~AVL();
		iterator	begin() {return (iterator(_root, MinValue(_root)));}

	node *MinValue(node *node)
	{
		while (node && node->left != NULL)
			node = node->left;
		return node;
	}
	node *MaxValue(node *node)
	{
		while (node && node->right != NULL)
			node = node->right;
		return node;
	}
};


}




#endif

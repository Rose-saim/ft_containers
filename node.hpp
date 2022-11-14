#ifndef  NODE_HPP
#define  NODE_HPP

#include <iostream>
# include <stdexcept>
# include "pair.hpp"

# define RED 0
# define BLACK 1

# define LEFT 0
# define RIGHT 1

namespace ft
{
	template<class Key, class T>
	class node
	{
			typedef const ft::pair<const Key, T>	value_type;
			unsigned int							color;
		public:
			node():parent(NULL), left(NULL), right(NULL), color(RED)
			{
			}
			node(value_type &value):parent(NULL), left(NULL), right(NULL), color(RED), value(value){};
			~node();
			
			node&	operator=(const node& src)
			{
				if (this != &src)
				{
					parent = src->parent;
					left = src->left;
					right = src->rightChild;
					color = src->color;
				}
				return *this;
			}

			node	*findMin(node *node)
			{
				if (!node)
					return NULL;
				while (node->right)
					node = node->right;
				return node;
			}

			node	*findMax(node *node)
			{
				if (!node)
					return NULL;
				while (node->left)
					node = node->left;
				return node;
			}

			node	*next()
			{
				node	*tmp = this;

				if (tmp->right)
					return (findMin(tmp->right));
				node	*tmpparent = tmp->parent;

				while (tmpparent && tmp == tmpparent->right)
				{
					tmp = tmpparent;
					tmpparent = tmpparent->parent;
				}
				return (tmpparent)
			}

			node	*prev()
			{
				node	*tmp = this;

				if (tmp->left)
					return (findMax(tmp->left));

				node	*tmpparent = tmp->parent;
				//tmp->parent ??
				while (tmpparent && tmp == tmpparent->left)
				{
					tmp = tmpparent;
					tmpparent = tmpparent->parent;
				}
				return (tmpparent)
			}

			bool			isNil( void) const { return this->parent == this;}
			void	setParent(node* _parent) { parent = _parent; }
			value_type&	getPair() {return(value); }

			node*		left;
			node*		right;
			node*		parent;
			value_type	value;
};
}

#endif

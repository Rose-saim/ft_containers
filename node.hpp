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
			node():parent(NULL), leftChild(NULL), rigthChild(NULL), color(RED)
			{
			}
			node(value_type &value):parent(NULL), leftChild(NULL), rigthChild(NULL), color(RED), value(value){};
			~node();
			
			node&	operator=(const node& src)
			{
				if (this == &src)
					return *this;
				parent = src->parent;
				leftChild = src->leftChild;
				rigthChild = src->rightChild;
				color = src->color;
				return *this;
			}
			bool			isNil( void) const { return this->parent == this;}
			void	setParent(node* _parent) { parent = _parent; }
			value_type&	getPair() {return(value); }

			node*	leftChild;
			node*	rigthChild;
			node*	parent;
			value_type	value;
};
}

#endif

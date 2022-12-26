#ifndef AVL_ITERATOR_REV_HPP
# define AVL_ITERATOR_REV_HPP

# include "AVL_Node.hpp"
# include "AVL_iterator.hpp"

namespace ft
{
template <class Key, class T, class AVL_node>
class AVL_iterator_rev
{
	public:
		typedef AVL_node						Node;
		typedef Node							*nodePtr;
		typedef AVL_iterator_rev<Key, T, AVL_node>	rev_iterator;
		typedef typename AVL_iterator<Key, T, AVL_node>::iterator		iterator;
	// private:
		nodePtr					_root;
		AVL_iterator_rev(): _root(NULL){
		};
		AVL_iterator_rev(nodePtr $root): _root($root){
		};
		AVL_iterator_rev(AVL_iterator_rev& src): _root(src._root){};
		~AVL_iterator_rev(){};

		AVL_iterator_rev& operator=(const AVL_iterator_rev& src)
		{
			if (this != &src)
			{
				_root = src._root;
			}
			return *this;
		}

		nodePtr	sucessor(nodePtr ptr)
		{
			if (ptr->right)
				return ptr->MinV(ptr->right);
			nodePtr tmp = ptr->parent;
			while (tmp && ptr == tmp->right)
			{
				ptr = tmp;
				tmp = tmp->parent;
			}
			return (tmp);
		}

		nodePtr	predecessor(nodePtr ptr)
		{
			if (ptr->left)
				return ptr->MaxV(ptr->left);
			nodePtr tmp = ptr->parent;
			while (tmp && ptr == tmp->left)
			{
				ptr = tmp;
				tmp = tmp->parent;
			}
			return (tmp);
		}

		AVL_iterator_rev& operator++(void)
		{
			_root = predecessor(_root);
			return (*this);
		}

		AVL_iterator_rev& operator++(int)
		{
			AVL_iterator_rev tmp = *this;
			operator++();
			return (tmp);
		}

		AVL_iterator_rev& operator--(void)
		{
        	if (_root == _root->maxV(_root))
			{
				_root = NULL;
				return (*this);				
			}
			_root = sucessor(_root);
			return (*this);
		}
		AVL_iterator_rev& operator--(int)
		{
			AVL_iterator_rev tmp = *this;
			operator--();
			return (tmp);
		}
		ft::pair<Key, T>&	operator*(void)const  {return (_root->getData());}
		ft::pair<Key, T>*	operator->(void)const  {return (&(operator*()));}
		nodePtr	getPtr()const {return (_root);}
		nodePtr	getNil()const {return (_root);}
		bool	operator==(const AVL_iterator_rev& src) const
		{
			return (getPtr() == src.getPtr());
		}
		bool	operator!=(const AVL_iterator_rev& src) const
		{
			return (getPtr() != src.getPtr());
		}
};
}

#endif
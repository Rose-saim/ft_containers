#ifndef AVL_ITERATOR_HPP
# define AVL_ITERATOR_HPP

# include "AVL_Node.hpp"

namespace ft
{
template <class Key, class T, class AVL_node>
class AVL_iterator
{
	public:
		typedef AVL_node						Node;
		typedef Node							*nodePtr;
		typedef AVL_iterator<Key, T, AVL_node>	iterator;
		nodePtr									_root;
		std::allocator<Node> alloc;
		AVL_iterator(): _root(NULL){
		}; 
		AVL_iterator(nodePtr data){
		
			_root = data;
		};
		AVL_iterator(const iterator& src): _root(src._root){
		}
		~AVL_iterator(){
		};
		iterator& operator=(const iterator& src)
		{
			if (this != &src)
			{
				_root = src._root;
			}
			return *this;
		}

		nodePtr ValMax(nodePtr ptr)
		{
			while (ptr && ptr->right)
				ptr = ptr->right;
			return ptr;
		}
		nodePtr ValMin(nodePtr ptr)
		{
			while (ptr && ptr->left)
				ptr = ptr->left;
			return ptr;
		}

		nodePtr	sucessor(nodePtr ptr)
		{
			if (ptr->right)
				return ValMin(ptr->right);
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
				return (ValMax(ptr->left));
			nodePtr tmp = ptr->parent;
			while (tmp && ptr == tmp->left)
			{
				ptr = tmp;
				tmp = tmp->parent;
			}
			return (tmp);
		}

		AVL_iterator& operator++(void)
		{
			_root = sucessor(_root);
		  	return (*this);
		}

		AVL_iterator operator++(int)
		{
			AVL_iterator tmp = *this;
			operator++();
			return (tmp);
		}

		AVL_iterator& operator--(void)
		{
			_root = predecessor(_root);
			return (*this);
		}
		AVL_iterator operator--(int)
		{
			AVL_iterator tmp(*this);
			operator--();
			return (tmp);
		}

		operator AVL_iterator<const Key, T, AVL_node>()const
		{ std::cout << "const_iterator" << std::endl;
			return(AVL_iterator<const Key, T, AVL_node>(_root)); }

		ft::pair<Key, T>&	operator*()const  {	return (_root->getData());}
		ft::pair<Key, T>*	operator->(void)const  {return (&(operator*()));}
		nodePtr	getPtr()const {return (_root);}
		nodePtr	getRoot()const {return (_root);}
		bool	operator==(const AVL_iterator& src) const
		{
			return (getPtr() == src.getPtr());
		}
		bool	operator!=(const AVL_iterator& src) const
		{
			return (getPtr() != src.getPtr());
		}
};
}

#endif

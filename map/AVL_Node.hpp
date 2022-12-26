#ifndef AVL_NODE_HPP
# define AVL_NODE_HPP

# include <iterator>

namespace ft
{
	template<class Key, class T, class Alloc = std::allocator< ft::pair<Key, T> > >
	class AVL_node
	{
		public:
				typedef	ft::AVL_node<Key, T, Alloc>			*nodePtr;
				typedef	Key									key_type;
				typedef	ft::pair<Key, T>					value_type;
				typedef size_t								size_type;
				typedef	Alloc								allocator_type;

				size_t					_height;
				value_type				_data;
				nodePtr					left;
				nodePtr					right;
				nodePtr					parent;
				private:
					bool					_begin;
		public:
			AVL_node():_height(1), _data(0, 0), left(NULL), right(NULL), parent(NULL), _begin(false){
			}
			AVL_node(value_type key): _height(1), _data(key), left(NULL), right(NULL), parent(NULL), _begin(false){
			};
			// AVL_node(nodePtr &src){
            //     *this = src;
            //     }
			~AVL_node(){};
			AVL_node &operator=(AVL_node const &src)
			{
				if (this != &src)
				{
					this->left = src.left;
					this->right = src.right;
					this->_data = src._data;
					this->_height = src._height;
					this->parent = src.parent;
					this->_begin = src._begin;
				}
				return (*this);
			}
			nodePtr MaxV(nodePtr ptr)
			{
				while (ptr && ptr->right != NULL)
					ptr = ptr->right;
				return ptr;
			}
			nodePtr MinV(nodePtr ptr)
			{
				while (ptr && ptr->left != NULL)
					ptr = ptr->left;
				return ptr;
			}
			value_type&	getData() {
				return _data;}
			bool	getBegin() {return _begin;}
			void	setBegin(bool value)
			{
				_begin = value;
			}
			void	setData(value_type value)
			{
				_data = value;
			}
	};
}

#endif
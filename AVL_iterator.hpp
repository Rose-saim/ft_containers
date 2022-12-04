
#ifndef AVL_ITERATOR_HPP
# define AVL_ITERATOR_HPP

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
				private:
					bool					_begin;
		public:
			AVL_node():_height(1), _data(ft::make_pair(1, 1)), left(NULL), right(NULL), _begin(false){

					std::cout << "get NODE" << std::endl;
				if (_data.first == 1)
					std::cout << "get NODE" << std::endl;
			};
			AVL_node(value_type key): _height(1), _data(key), left(NULL), right(NULL), _begin(false){		};
			AVL_node(nodePtr &src){*this = src;}
			~AVL_node(){}
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
				nodePtr it = ptr;
				while (it && it->right != NULL)
					it = it->right;
				return it;
			}
			nodePtr MinV(nodePtr ptr)
			{
				nodePtr it = ptr;
				while (it && it->left != NULL)
					it = it->left;
				return it;
			}
			key_type&	getData() { 
				return _data.first;}
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


namespace ft
{
template <class Key, class T, class AVL_node>
class AVL_iterator
{
	public:
		typedef Key								key_type;
		typedef AVL_node						Node;
		typedef Node							*nodePtr;
		typedef AVL_iterator<Key, T, AVL_node>	iterator;
		typedef	ft::pair<nodePtr, bool>			Pair;
	// private:
		nodePtr					_root;
		Pair				 	val;
		#define	val_ptr val.first
		#define	val_nil val.second
		AVL_iterator(): _root(NULL), val(ft::make_pair(NULL, false)){
			std::cout << "begin1" << std::endl;
		};
		AVL_iterator(nodePtr $root, nodePtr $pos, bool nil): _root($root), val(ft::make_pair($pos, nil)){
			std::cout << "begin2" << std::endl;
		};
		// AVL_iterator(AVL_iterator& src): {this = src;};
		~AVL_iterator(){};

		AVL_iterator& operator=(const AVL_iterator& src)
		{
			if (this != &src)
			{
				val = ft::make_pair(src.val_ptr, src.val_nil);
				_root = src._root;
			}
			return *this;
		}

		// AVL_iterator& operator++(void)
		// {
		// 	if (val.second)
		// 	{
		// 		val.second = false;
		// 		return (*this);
		// 	}
		// 	if (val.second == _root->MaxV(_root))
		// 	{
		// 		val.second = NULL;
		// 		val.second = true;
		// 		return (*this);
		// 	}
		// 	return *this;
		// }
		// AVL_iterator& operator--(void)
		// {
		// 	if (_root->left)
		// 		_root = _root->left;
		// 	return *this;
		// }

};

}

#endif

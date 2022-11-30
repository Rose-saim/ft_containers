
#ifndef AVL_ITERATOR_HPP
# define AVL_ITERATOR_HPP

# include <iterator>

namespace ft
{
	template<class Key, class Value, class Alloc = std::allocator< ft::pair<const Key, Value> > >
	class AVL_node
	{
		public:
				typedef ft::AVL_node<Key, Value, Alloc>	iterator;
				typedef ft::AVL_node<const Key, Value, Alloc>	const_iterator;
				typedef	iterator					*nodePtr;
				typedef	Key						key_type;
				typedef	ft::pair<Key, Value>	pair_type;
				typedef size_t					size_type;
				typedef Value					value_type;
				typedef	Alloc					allocator_type;
				size_t					_height;
				pair_type				_data;
				nodePtr					left;
				nodePtr					right;
				std::string				name;
				private:
					bool					_begin;
		public:
			AVL_node():_height(1), _data(ft::make_pair(0,0)), left(NULL), right(NULL), name("OUI"), _begin(false){};
			AVL_node(pair_type key): _height(1), _data(key), left(NULL), right(NULL), name("OUI"), _begin(false){};
			AVL_node(nodePtr &src){*this = src;}
			~AVL_node(){std::cout << "destructor AVLnode" << std::endl;}
			bool	getBegin()
			{
				return _begin;
			}
			void	setBegin(bool value)
			{
				_begin = value;
			}
			int	height(nodePtr N)
			{
				if (!N)
					return 0;
				return N->_height;
			}
			const key_type& key() const
			{
				return this->_data.second;
			}

			iterator *MaxValue()
			{
				iterator *it = this;
				while (it && it->right != NULL)
					it = it->right;
				return it;
			}
			iterator *MinValue()
			{
				iterator *it = this;
			  	while (it && it->left != NULL)
				{
					it = it->left;
				}
				return it;
			}
			int max(int a, int b) {
			return (a > b) ? a : b;
			}

			// New node creation
			nodePtr newNode(pair_type key) 
			{
				nodePtr	node = new AVL_node(key);
				return (node);
			}

			nodePtr	rightRotate(nodePtr y)
			{
				nodePtr N1 = y->left;
				nodePtr N2 = N1->right;
				N1->right = y;
				y->left = N2;
				y->_height = max(height(y->left), height(y->right) + 1);
				N1->_height = max(height(N1->left), height(N1->right) + 1);
				return N1;
			}
			nodePtr	leftRotate(nodePtr y)
			{
				nodePtr N1 = y->right;
				nodePtr N2 = N1->left;
				N1->left = y;
				y->right = N2;
				y->_height = max(height(y->left), height(y->right) + 1);
				N1->_height = max(height(N1->left), height(N1->right) + 1);
				return N1;
			}


	};
}


namespace ft
{
template <class T, class AVL>
class AVL_iterator
{
	private:
		typedef ft::AVL_node<T, AVL>	*nodePtr;
		// typedef AVL	*nodePtr;
	public:
		nodePtr	_root;
		ft::pair<nodePtr, bool> val;
		AVL_iterator(): _root(NULL){};
		AVL_iterator(nodePtr $root, nodePtr $pos):  _root($root), val(ft::make_pair($pos, false)){};
		~AVL_iterator(){};
};

}

#endif

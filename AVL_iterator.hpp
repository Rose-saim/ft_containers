
#ifndef AVL_ITERATOR_HPP
# define AVL_ITERATOR_HPP

# include <iterator>

namespace ft
{
	template<class Key, class Value, class Alloc = std::allocator< ft::pair<const Key, Value> > >
	class AVL_node
	{
		public:
				typedef AVL_node<Key, Value, Alloc>		node;
				typedef	Key						key_type;
				typedef	ft::pair<Key, Value>	pair_type;
				typedef size_t					size_type;
				typedef	node					*nodePtr;
				typedef Value					value_type;
				typedef	Alloc					allocator_type;
				typedef ft::AVL_node<Key, Value, Alloc>	iterator;
				typedef ft::AVL_node<const Key, Value, Alloc>	const_iterator;
				size_t					_height;
				pair_type				_data;
				nodePtr					_begin;
				nodePtr					left;
				nodePtr					right;
		public:
				AVL_node(pair_type key)
				{
					_data = key;
					_height = 1;
					left = NULL;
					right = NULL;
				} 
				AVL_node(nodePtr &src)
				{
					*this = src;
				}
				~AVL_node(){std::cout << "destructor" << std::endl;}

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

			int max(int a, int b) {
			return (a > b) ? a : b;
			}

		// New node creation
		nodePtr newNode(pair_type key) 
		{
			nodePtr	node = new AVL_node(key);
			node->left = NULL;
			node->right = NULL;
			node->_height = 1;
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

		int	getBalanceFactor(nodePtr N)
		{
			if (!N)
				return 0;
			return (height(N->left) - height(N->right));
		}

		nodePtr	insertNode(nodePtr node, pair_type key)
		{
			static int i = 0;
			if (node == NULL)
			{
				if (i == 0)
				{
					i = 1;
					node->_begin = _begin;
				}
				else
					node->_begin = this->_begin;
				return (newNode(key));

			}
			if (key.second < node->key())
				node->left = insertNode(node->left, key);
			else if (key.second > node->key())
				node->right = insertNode(node->right, key);
			else 
				return node;

			node->_height = 1 + max(height(node->left), height(node->right));
			int	balanceFactor = getBalanceFactor(node);
		
			if (balanceFactor > 1)
			{
				if (key.second < node->left->key())
					return rightRotate(node);
				else if (key.second > node->left->key())
				{
					node->left = leftRotate(node->left);
					return rightRotate(node);	
				}
			}
			if (balanceFactor < -1)
			{
				if (key.second > node->right->key())
					return leftRotate(node);
				else if (key.second < node->right->key())
				{
					node->right = rightRotate(node->right);
					return leftRotate(node);	
				}
			}
			return node;
		}
	};
}


namespace ft
{
template <class T, class AVL>
// template<class Key, class Value, class class Alloc = std::allocator< ft::pair<const Key, Value> > >
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

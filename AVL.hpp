#ifndef AVL_HPP
# define AVL_HPP

# include "pair.hpp"

template<class Key, class Value, class Compare, class Alloc = std::allocator< ft::pair<const Key, Value> > >
class AVL
{
	public:
			typedef AVL<Key, Value, Compare, Alloc>		node;
			typedef	Key						key_type;
			typedef	ft::pair<Key, Value>	pair_type;
			typedef size_t					size_type;
			typedef	node					*nodePtr;
			typedef Value					value_type;
			typedef	Alloc					allocator_type;
			size_t					height;
			pair_type				_data;
			nodePtr					left;
			nodePtr					right;
	public:
			AVL(pair_type key)
			{
				_data = key;
				height = 1;
				left = NULL;
				right = NULL;
			} 
			AVL(nodePtr &src)
			{
				*this = src;
			}
			~AVL(){std::cout << "destructor" << std::endl;}
			nodePtr	&operator=(const nodePtr &src)
			{
				left = src.left;
				right = src.right;
				height = src.height;
				_data = src._data;
				return (*this);
			}

		const key_type& key() const
		{
			return this->_data.first;
		}

		int max(int a, int b) {
		return (a > b) ? a : b;
		}

	// New node creation
	nodePtr *newNode(pair_type key) 
	{
		nodePtr	node = new AVL();
		return (node);
	}

	nodePtr	*rightRotate(nodePtr *y)
	{
		nodePtr *N1 = y->left;
		nodePtr *N2 = N1->right;
		N1->right = y;
		y->left = N2;
		y->height = max(height(y->left), height(y->right) + 1);
		N1->height = max(height(N1->left), height(N1->right) + 1);
		return N1;
	}
	nodePtr	*leftRotate(nodePtr *y)
	{
		nodePtr *N1 = y->right;
		nodePtr *N2 = N1->left;
		N1->left = y;
		y->right = N2;
		y->height = max(height(y->left), height(y->right) + 1);
		N1->height = max(height(N1->left), height(N1->right) + 1);
		return N1;
	}

	int	getBalanceFactor(nodePtr *N)
	{
		if (!N)
			return 0;
		return (height(N->left) - hieght(N->right));
	}

	nodePtr	*insertNode(nodePtr node, pair_type key)
	{
		if (node == NULL)
			return (newNode(key));
		if (key.first < node->key())
			node->left = insertNode(node->left, key);
		// else if (key >node->key)
		// 	node->right = insertNode(node->right, key);
		// else 
		// 	return node;

		// node->height = 1 + max(height(node->left), height(node->right));
		// int	balanceFactor = getBalanceFactor(node);
	
		// if (balanceFactor > 1)
		// {
		// 	if (key < node->left->key)
		// 		return rightRotate(node);
		// 	else if (key > node->left->key)
		// 	{
		// 		node->left = leftRotate(node->left);
		// 		return rightRotate(node);	
		// 	}
		// }
		// if (balanceFactor < -1)
		// {
		// 	if (key > node->right->key)
		// 		return left(node);
		// 	else if (key < node->right->key)
		// 	{
		// 		node->right = rightRotate(node->right);
		// 		return leftRotate(node);	
		// 	}
		// }
	}

	nodePtr *MinValue(nodePtr *node)
	{
		nodePtr *curr = node;
		while (curr->left != NULL)
			curr = curr->left;
		return curr;
	}
	nodePtr *MaxValue(nodePtr *node)
	{
		nodePtr *curr = node;
		while (curr->right != NULL)
			curr = curr->right;
		return curr;
	}

	// void	printTree(node *root, std::string indent, bool last)
	// {
	// 	if (!root)
	// 	{
	// 		std::cout << indent;
	// 		if (last)
	// 		{
	// 			std::cout << "R----";
	// 			indent += "    ";
	// 		}
	// 		else
	// 		{
	// 			std::cout << "L----";
	// 			indent += "    ";
	// 		}
	// 	}
	// 	std::cout << root->key << std::endl;
	// 	printTree(root->left, indent, false);
	// 	printTree(root->right, indent, true);
	// }
};



#endif

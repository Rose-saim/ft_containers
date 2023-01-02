#ifndef AVL_HPP
# define AVL_HPP

# include "pair.hpp"
# include "AVL_iterator.hpp"
# include "AVL_iterator_rev.hpp"
# include "AVL_Node.hpp"
# include "stdlib.h"

namespace ft
{
	template<class Key, class T, class Compare, class Alloc = std::allocator<ft::pair<Key, T> > >
	class AVL
	{
		// private:
		public:
			typedef Alloc										allocator_type;
			typedef	ft::AVL_node<Key, T, Alloc>					Node;
			typedef ft::AVL_iterator<Key, T, Node>				iterator;
			typedef ft::AVL_iterator<const Key, T, Node>		const_iterator;
			typedef ft::AVL_iterator_rev<Key, T, Node>			iterator_rev;
			typedef ft::AVL_iterator_rev<const Key, T, Node>	const_iterator_rev;
			typedef	ft::pair<Key, T>							value_type;
			typedef size_t										size_type;
			typedef Key											key_type;
			Compare												_comparator;
			std::allocator<Node>								myAlloc;
			std::allocator<iterator>							youAlloc;
			Node												*_node;
			size_t												_size;
			AVL(): _node(), _size(0){};
			~AVL(){
			};
			iterator	begin() {return (iterator(MinValue(_node)));}
			iterator	end() {return (iterator(MaxValue(_node)));}
			const_iterator	begin() const{return (const_iterator(MinValue(_node)));}
			const_iterator	end() const{return (const_iterator(MaxValue(_node)));}
			
			iterator_rev	rbegin() {return (iterator_rev(MaxValue(_node)));}
			const_iterator_rev	rbegin() const{return (iterator_rev(MaxValue(_node)));}
			iterator_rev	rend() {return (iterator_rev(MinValue()));}
			const_iterator_rev	rend() const{return (iterator_rev(MinValue()));}

			Node *MaxValue(Node *ptr) const
			{
				return _node->MaxV(ptr);
			}
			Node *MinValue(Node *ptr)const
			{
			while (ptr && ptr->left)
				ptr = ptr->left;
			return ptr;
			}
			// New node creation
			Node *newNode(Node* node, value_type key) 
			{
				node = new Node;
				node->right = NULL;
				node->left = NULL;
				node->parent = NULL;
				node->setData(key);
				return (node);
			}

			Node* insert(const value_type& _pair){
			_node = insertNode(_node, _pair);
			return(_node);
			}

			Node	*insertNode(Node *node, value_type key, Node* parent = NULL)
			{
				if (!node)
				{
					_size += 1;
					node = newNode(node, key);
					node->parent = parent;
					return node;
				}
				if (key.first < node->getData().first)
				{
					node->left = insertNode(node->left, key, node);
					// node->left->parent = node;
				}
				else if (key.first > node->getData().first)
				{
					node->right = insertNode(node->right, key, node);
					node->right->parent = node;
				}
				else 
					return node;

				node->_height = 1 + max(height(node->left), height(node->right));
				int	balanceFactor = getBalanceFactor(node);
				if (balanceFactor > 1)
				{
					if (key.first < node->left->getData().first)
						return (rightRotate(node));
					else if (key.first > node->left->getData().first)
					{
						node->left = leftRotate(node->left);
						return (rightRotate(node));	
					}
				}
				if (balanceFactor < -1)
				{
					if (key.first > node->right->getData().first)
						return (leftRotate(node));
					else if (key.first < node->right->getData().first)
					{
						node->right = rightRotate(node->right);
						return (leftRotate(node));	
					}
				}
				return node;
			}
//========================================================================================================================
			Node* deleteNode(Node *position) {
				position = deleteAt(_node, position->_data);
				return (position);
			}
			Node *deleteAt(Node *root, value_type key) {
			// Find the node and delete it
			if (root == NULL)
				return root;
			if (key.first < root->getData().first)
				root->left = deleteAt(root->left, key);
			else if (key.first > root->getData().first)
			{
				root->right = deleteAt(root->right, key);
			}
			else 
			{
				if ((root->left == NULL) ||
				(root->right == NULL)) 
				{
					Node *temp;
					if (root->left)
						temp = root->left;
					else
					 temp = root->right;
				if (temp == NULL) {
					temp = root;
					root = NULL;
				} else
					*root = *temp;
				myAlloc.destroy(temp);
				myAlloc.deallocate(temp, 1);
				_size -= 1;
				}
				else 
				{
				Node *temp = _node->MinV(root->right);
				root->_data.first = temp->_data.first;
				root->right = deleteAt(root->right,
							temp->_data);
				}
			}

			if (root == NULL)
				return root;

			// Update the balance factor of each node and
			// balance the tree
			root->_height = 1 + max(height(root->left),
						height(root->right));
			int balanceFactor = getBalanceFactor(root);
			if (balanceFactor > 1) {
				if (getBalanceFactor(root->left) >= 0) {
				return rightRotate(root);
				} else {
				root->left = leftRotate(root->left);
				return rightRotate(root);
				}
			}
			if (balanceFactor < -1) {
				if (getBalanceFactor(root->right) <= 0) {
				return leftRotate(root);
				} else {
				root->right = rightRotate(root->right);
				return leftRotate(root);
				}
			}
			return root;
			}
//========================================================================================================================

			int	getBalanceFactor(Node *N)
			{
				if (!N)
					return 0;
				return (height(N->left) - height( N->right));
			}

			Node	*search(value_type val) const
			{
				Node *i = _node;
				while (i && val.first != i->getData().first)
				{

					if (val < i->_data)
						i = i->left;
					else
						i = i->right;
				}
				return (i);
			}

			Node	*rightRotate(Node *y)
			{
				Node *N1 = y->left;
				Node *N2 = N1->right;
				N1->right = y;
				y->left = N2;
				y->_height = max(height(y->left), height(y->right) + 1);
				N1->_height = max(height(N1->left), height(N1->right) + 1);
				return N1;
			}

			int	height(Node *N)
			{
				if (!N)
					return 0;
				return N->_height;
			}

			int max(int a, int b) {
			return (a > b) ? a : b;
			}
			
			Node	*leftRotate(Node *y)
			{
				Node *N1 = y->right;
				Node *N2 = N1->left;
				N1->left = y;
				y->right = N2;
				y->_height = max(height(y->left), height(y->right) + 1);
				N1->_height = max(height(N1->left), height(N1->right) + 1);
				return N1;
			}
	};
}




#endif

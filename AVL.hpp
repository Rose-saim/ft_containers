#ifndef AVL_HPP
# define AVL_HPP

# include "pair.hpp"
# include "AVL_iterator.hpp"
#include <iostream>
#include <memory>
#include <string>

namespace ft
{
	template<class Key, class T, class Compare, class Alloc = std::allocator<ft::pair<Key, T> > >
	class AVL
	{
		// private:
		public:
			typedef Alloc								allocator_type;
			typedef	ft::AVL_node<Key, T, Alloc>			Node;
			typedef ft::AVL_iterator<Key, T, Node>		iterator;
			typedef iterator							*itePtr;
			typedef ft::AVL_node<const Key, T>			const_iterator;
			typedef	ft::pair<Key, T>					value_type;
			typedef size_t								size_type;
			std::allocator<Node>						myAlloc;
			itePtr										ite_ptr;
			Node										*_node;
			AVL(): ite_ptr(NULL), _node(NULL){
				std::cout << "Contructor AVL" << std::endl;

			};
			~AVL(){
				std::cout << "Destructor AVL" << std::endl;
			};
			iterator	begin() {return (iterator(_node, MinValue(_node), false));}
			const_iterator	begin() const{return (iterator(_node, MinValue(_node), false));}
			iterator	end() {return (iterator(_node, MaxValue(_node), false));}
			const_iterator	end() const{return (iterator(_node, MaxValue(_node), false));}

			Node *MaxValue(Node *ptr)
			{
				return _node->MaxV(ptr);
			}
			Node *MinValue(Node *ptr)
			{
				return _node->MinV(ptr);
			}
			// New node creation
			Node *newNode(Node *src, value_type key) 
			{
				Node	*node = myAlloc.allocate(1);
				node->setData(key);
				(void)src;
				return (node);
			}

			Node* insert(const value_type& $pair){
			_node = insertNode(_node, $pair); return(_node);
			}

			Node	*insertNode(Node *node, value_type key)
			{
				if (!node)
				{
				std::cout << "INSERT 1" << std::endl;

					node = newNode(node, key);
					return node;
				}
				if (key.first < node->getData())
				{
				std::cout << "INSERT 1======" << std::endl;
					node->left = insertNode(node->left, key);
				}
				else if (key.first > node->getData())
				{
				std::cout << "INSERT 2======" << std::endl;
					node->right = insertNode(node->right, key);
				std::cout << "INSERT NODE: " << node->getData() <<std::endl;
					std::cout << "INSERT NODE: " << node->right->getData() <<std::endl;
				}
				else 
					return node;

				node->_height = 1 + max(node->left->_height, node->right->_height);
				int	balanceFactor = getBalanceFactor(node);
				if (balanceFactor > 1)
				{
					if (key.first < node->left->getData())
						return rightRotate(node);
					else if (key.first > node->left->getData())
					{
						node->left = leftRotate(node->left);
						return rightRotate(node);	
					}
				}
				if (balanceFactor < -1)
				{
					if (key.first > node->right->getData())
						return leftRotate(node);
					else if (key.first < node->right->getData())
					{
						node->right = rightRotate(node->right);
						return leftRotate(node);	
					}
				}
				return node;
			}

			// // Delete a node
			// Node *deleteNode(Node *root, int key) {
			// 	// Find the node and delete it
			// 	if (root == NULL)
			// 		return root;
			// 	if (key < root->key)
			// 		root->left = deleteNode(root->left, key);
			// 	else if (key > root->key)
			// 		root->right = deleteNode(root->right, key);
			// 	else {
			// 		if ((root->left == NULL) ||
			// 		(root->right == NULL)) {
			// 		Node *temp = root->left ? root->left : root->right;
			// 		if (temp == NULL) {
			// 			temp = root;
			// 			root = NULL;
			// 		} else
			// 			*root = *temp;
			// 		free(temp);
			// 		} else {
			// 		Node *temp = nodeWithMimumValue(root->right);
			// 		root->key = temp->key;
			// 		root->right = deleteNode(root->right,
			// 					temp->key);
			// 		}
			// 	}

			// 	if (root == NULL)
			// 		return root;

			// 	// Update the balance factor of each node and
			// 	// balance the tree
			// 	root->height = 1 + max(height(root->left),
			// 				height(root->right));
			// 	int balanceFactor = getBalanceFactor(root);
			// 	if (balanceFactor > 1) {
			// 		if (getBalanceFactor(root->left) >= 0) {
			// 		return rightRotate(root);
			// 		} else {
			// 		root->left = leftRotate(root->left);
			// 		return rightRotate(root);
			// 		}
			// 	}
			// 	if (balanceFactor < -1) {
			// 		if (getBalanceFactor(root->right) <= 0) {
			// 		return leftRotate(root);
			// 		} else {
			// 		root->right = rightRotate(root->right);
			// 		return leftRotate(root);
			// 		}
			// 	}
			// 	return root;
			// }
			int	getBalanceFactor(Node *N)
			{
				if (!N)
					return 0;
				return (N->_height - N->_height);
			}

			Node	*search(value_type val) const
			{
				Node *i = _node;
				std::cout << "I'm here1 !" << std::endl;
				while (i && val.first != i->getData())
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

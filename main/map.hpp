#ifndef MAP_HPP
# define MAP_HPP

# include <limits>
# include "Bst.hpp"
# include "map_iterator.hpp"
# include "reverse_iterator.hpp"
# include "is_integral.hpp"
# include "enable_if.hpp"
# include "utils.hpp"
# include "lexicographical.hpp"
# include <unistd.h>

# include <cmath>

namespace ft {
template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::Node<const Key, T> > >
class	map
{
	public:

	typedef	Key														key_type;
	typedef T														mapped_type;
	typedef	ft::pair<Key, T>										value_type;
	typedef	Compare													key_compare;
	typedef	Alloc													alloc_type;
	typedef typename alloc_type::pointer							pointer;
	typedef typename alloc_type::const_pointer						const_pointer;
	typedef	value_type&												reference;
	typedef	const value_type&										const_reference;
	typedef size_t													size_type;
	typedef BinarySearchTree<key_type, mapped_type, Compare>		tree_type;
	typedef Node<key_type, mapped_type>								node_type;
	typedef	ft::MapIterator<value_type, node_type, Compare>			iterator;
	typedef	ft::MapIterator<const value_type, node_type, Compare>	const_iterator;
	typedef ft::ReverseIterator<iterator>							reverse_iterator;
	typedef ft::ReverseIterator<const_iterator>						const_reverse_iterator;
	class	value_compare
	{
		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {}
		public:
			friend class		map;
			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;
			bool	operator()(const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
	};
//---------------------------CONSTRUCTORS--------------------------------------/
	
	map(const key_compare& comp = key_compare(), const alloc_type& alloc = alloc_type()) : _alloc(alloc), _comp(comp)
	{
	}
	
	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
	const alloc_type& alloc = alloc_type(),
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NullPtr)
	:	_alloc(alloc), _comp(comp), _tree(tree_type())
	{
		this->insert(first, last);	
	}

	map (const map& x) : _alloc(x._alloc), _comp(x._comp), _tree(tree_type())
	{
		*this = x;
	}
	
	~map()
	{}

	map&	operator=(const map& x)
	{
		if (this == &x)
			return (*this);
		
		if (!this->empty())
			this->clear();
		this->_alloc = x._alloc;
		this->_comp = x._comp;

		this->insert(x.begin(), x.end());

		return (*this);
	}

//--------------------------------MODIFIERS-----------------------------------//

	ft::pair<iterator, bool>	insert(const value_type& val)
	{
		if (this->_tree._root == NULL)
		{
			this->_tree._root = this->_tree.createNode(NULL, val);
			return (ft::make_pair(iterator(this->_tree._root, this->_tree._root, this->_tree._end), true));
		}
		node_type*	newNode = this->_tree.searchByKey(this->_tree._root, val.first);
		
		if (newNode != NULL)	
			return (ft::make_pair(iterator(newNode, this->_tree._root, this->_tree._end), false));
		
		newNode = this->_tree.insertNode(this->_tree._root, val);
		
		return (ft::make_pair(iterator(newNode, this->_tree._root, this->_tree._end), true));
	}

	iterator	insert(iterator position, const value_type& val)
	{
		node_type*	ret;
		static_cast<void>(position);

		if (this->_tree._root == NULL)
		{
			this->_tree._root = this->_tree.createNode(NULL, val);
			ret = this->_tree._root;
		}
		else
		{
			if ((ret = this->_tree.searchByKey(this->_tree._root, val.first)) != NULL)
				return (iterator(ret, this->_tree._root, this->_tree._end));
			
			ret = this->_tree.insertNode(this->_tree._root, val);	
		}
		return (iterator(ret, this->_tree._root, this->_tree._end));
	}
	
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NullPtr)
	{
		while (first != last)
		{
			this->insert(*first);
			++first;
		}
	}

	void	erase (iterator position)
	{
		this->erase(position->first);
	}

	size_type erase (const key_type& k)
	{
		if (this->find(k) == this->end())
			return (0);
		
		this->_tree.remove(k);

		return (1);
	}
	
	void	erase(iterator first, iterator last)
	{
		while (first != last)
			this->erase(first++);
	}
	
	void	swap(map& x)
	{
		this->_tree.swap(x._tree);
		ft::swapp<key_compare>(this->_comp, x._comp);
		ft::swapp<alloc_type>(this->_alloc, x._alloc);
	}

	void	clear()
	{
		this->erase(this->begin(), this->end());
		this->_tree._root = NULL;
	}

//----------------------------ITERATORS---------------------------------------//

	iterator				begin() { return (iterator(this->_tree.findMin(), this->_tree._root, this->_tree._end)); }
	const_iterator			begin() const { return (const_iterator(this->_tree.findMin(), this->_tree._root, this->_tree._end)); }
	iterator				end() { return (iterator(this->_tree._end, this->_tree._root, this->_tree._end)); }
	const_iterator			end() const { return (const_iterator(this->_tree._end, this->_tree._root, this->_tree._end)); }
	reverse_iterator		rbegin() { return (reverse_iterator(this->end())); }
	const_reverse_iterator	rbegin() const { return (const_reverse_iterator(this->end())); }
	reverse_iterator		rend() { return (reverse_iterator(this->begin())); }
	const_reverse_iterator	rend() const { return (const_reverse_iterator(this->begin())); }
//---------------------------OBSERVERS---------------------------------------//

key_compare	key_comp() const
{
	return (key_compare());
}

value_compare value_comp() const
{
	return (value_compare(key_comp()));
}

//---------------------------OPERATIONS--------------------------------------/

	iterator	find(const key_type& k)
	{
		if (this->_tree._root == NULL)
			return (this->end());
		
		node_type*	finder = this->_tree.searchByKey(this->_tree._root, k);

		if (finder == NULL)
			return (this->end());

		return (iterator(finder, this->_tree._root, this->_tree._end));
	}

	const_iterator	find(const key_type& k) const
	{
		if (this->_tree._root == NULL)
			return (this->end());

		node_type*	finder = this->_tree.searchByKey(this->_tree._root, k);

		if (finder == NULL)
			return (this->end());

		return (const_iterator(finder, this->_tree._root, this->_tree._end));
	}

	size_type	count(const key_type& k) const
	{
		if (this->_tree._root == NULL || this->_tree.searchByKey(this->_tree._root, k) == NULL)
			return (0);
		return (1);
	}

	iterator	lower_bound(const key_type& k)
	{
		iterator it	= this->begin();

		while (it != this->end() && this->_comp(it->first, k))
			it++;
		
		return (it);
	}
	
	const_iterator	lower_bound(const key_type& k) const
	{
		const_iterator it = this->begin();

		while (it != this->end() && this->_comp(it->first, k))
			it++;

		return (it);
	}

	iterator	upper_bound(const key_type&	k)
	{
		iterator it = this->begin();

		while (it != this->end() && !this->_comp(k, it->first))
			it++;
		
		return (it);
	}

	const_iterator	upper_bound(const key_type&	k) const
	{
		const_iterator it = this->begin();

		while (it != this->end() && !this->_comp(k, it->first))
			it++;

		return (it);
	}

	ft::pair<iterator, iterator> equal_range (const key_type& k)
	{
		return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
	}
	
	ft::pair<const_iterator, const_iterator> equal_range (const key_type& k) const
	{
		return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
	}

//-------------------------------CAPACITY-------------------------------------/
	
	size_type	size()	const
	{
		size_type size = 0;
		this->_tree.treeSize(this->_tree._root, &size);
		
		return (size);
	}

	size_type	max_size() const 
	{
		if (sizeof(value_type) == 12)
			return (((std::numeric_limits<size_type>::max() / (sizeof(value_type) * 8))));
		return (this->_alloc.max_size());
	}

	bool	empty() const { return (this->size() == 0 ? 1 : 0); }

//-------------------------------ELEMENT-ACCESS------------------------------//

	mapped_type&	operator[](const key_type& k)
	{
		if (this->_tree._root == NULL)
			this->insert(ft::make_pair(k, mapped_type()));
	
		iterator	ret = this->find(k);
		
		if (ret == this->end())
		{
			this->insert(ft::make_pair(k, mapped_type()));
			ret = this->find(k);
		}
		return (ret->second);
	}
	
//----------------------------------------------------------------------------//

	private:

	bool	upper(const key_type& a, const key_type& b)
	{
		return (this->_comp(a, b) == false && equal(a, b) == false);
	}
	
	bool	equal(const key_type& a, const key_type& b)
	{
		if (this->_comp(a, b) == false && this->_comp(b, a) == false)
			return (true);
		return (false);
	}
	
	void printNode(node_type* x) const
	{
		std::cout << "\033[1;28m" << x << "\033[0;28m";
		std::cout << " data : " << x->_pair;
		std::cout << " parent : ";
		if (x != NULL && x->_parent != NULL)
			std::cout << x->_parent->_pair;
		else
			std::cout << "\033[1;36mnil\033[0;28m ";
		std::cout << " left : ";
		if (x != NULL && x->_left != NULL)
			std::cout << x->_left->_pair;
		else
			std::cout << "\033[1;36mnil\033[0;28m ";
		std::cout << " right : ";
		if (x != NULL && x->_right != NULL)
			std::cout << x->_right->_pair;
		else
			std::cout << "\033[1;36mnil\033[0;28m ";
		std::cout << std::endl;
	}
	void print() const
	{
		std::cout << "---------------------------------\n";
    	print2(this->_tree._root, 0);
		std::cout << "---------------------------------\n";
	}
	
	void print2(node_type* root, int space) const
	{
    	if (root == NULL)
		{
        	return;
		}
 
  	 	space += 5;
 
		if (root->_right != NULL)
    		print2(root->_right, space);
 
    	std::cout << std::endl;
    	for (int i = 2; i < space; i++)
        	std::cout << " ";
    	std::cout << root->_pair.first << "(";
		if (root->_parent)
			std::cout << root->_parent->_pair.first;
		else
			std::cout << "null";
		std::cout << ")" << std::endl;
 
		if (root->_left != NULL)
    		print2(root->_left, space);

		//printNode(root);
	}
 
//---------------------------------------

	alloc_type		_alloc;
	key_compare		_comp;
	tree_type		_tree;

	//-------------------------
};

template <class Key, class T, class Compare, class Alloc>
bool	operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (!(lhs == rhs));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (!(rhs < lhs));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool	operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{
	return (!(lhs < rhs));
}

template <class Key, class T, class Compare, class Alloc>
void	swap(map<Key, T, Compare, Alloc>& a, map<Key, T, Compare, Alloc>& b)
{
	a.swap(b);
}

}
#endif

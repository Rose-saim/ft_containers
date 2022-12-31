#ifndef MAP_HPP
#define MAP_HPP

# include <iostream>
# include <memory>
# include <iterator>
# include <list>
# include <stdexcept>
# include <unistd.h>
# include <exception>
# include <memory>
# include <string>
# include "AVL.hpp"
# include "AVL_iterator.hpp"
# include "AVL_iterator_rev.hpp"


namespace ft
{
		template <class Arg1, class Arg2, class Result>
  	struct binary_function {
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result result_type;
  	};

	template <class T> struct less : binary_function <T,T,bool> {
	  bool operator() (const T& x, const T& y) const {return x<y;}
	};
	template < class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef	Key																		key_type;
			typedef	T																		mapped_type;
			typedef	size_t																	size_type;
			typedef	ft::pair<const Key, T>			 										value_type;
			typedef	Allocator																allocator_type;
			typedef	Compare																	key_compare;
			typedef typename allocator_type::const_reference								const_reference;
			typedef	typename allocator_type::reference										reference;
			typedef	typename allocator_type::const_pointer									const_pointer;
			typedef	typename allocator_type::pointer										pointer;
			typedef	typename ft::AVL<const Key, T, Compare, Allocator>::const_iterator		const_iterator;
			typedef	typename ft::AVL<Key, T, Compare, Allocator>::iterator					iterator;
			typedef	typename ft::AVL<const Key, T, Compare, Allocator>::const_iterator_rev	const_iterator_rev;
			typedef	typename ft::AVL<Key, T, Compare, Allocator>::iterator_rev				iterator_rev;
			typedef typename ft::AVL_node<Key, T, Allocator>								*nodePtr;
		// private:
				key_compare								_compare;
				allocator_type							_alloc;
				ft::AVL<Key, T, Compare, Allocator>		tree;
				nodePtr									node_ptr;
				iterator								*_ite;
		public:
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/***********************************************************CONSTRUCTOR***********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			explicit map(const key_compare &cmp = key_compare(), const Allocator &alloc = allocator_type()):
				 _compare(cmp), _alloc(alloc), node_ptr(NULL)
			{
			}
			template< typename InputIt >
			map( InputIt first, InputIt last, const key_compare &cmp = key_compare(),
					const Allocator &alloc = Allocator() ):
				_compare(cmp), _valueAlloc(alloc)
			{
				insert(first, last);
			}
			map( const map& other )
			{
				*this = other;
			}
			~map()
			{
				if (size() > 0)
				{
					erase(begin(), end());
					erase(node_ptr);
				}
			}

			map&	operator=(const map& other)
			{
				if (this != &other)
				{
					this->_alloc = other._alloc;
					this->tree = other.tree;
					this->_ite = other._ite;
				}
				return (*this);
			}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************ITERATORS***********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		iterator				begin() {return (tree.begin());}
		const_iterator			begin()const {return (tree.begin());}
		iterator				end() {return (tree.end());}
		const_iterator			end()const {return (tree.end());}
		iterator_rev			rbegin() {return (tree.rbegin());}
		const_iterator_rev		rbegin()const {return (tree.rbegin());}
		iterator_rev			rend() {return (tree.rend());}
		const_iterator_rev		rend()const {return (tree.rend());}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************CAPACITY************************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		bool	empty(void)
		{
			if (size() == 0)
				return 1;
			return 0;	
		}

		size_type	size()
		{
			return (tree._size);
		}

		size_type	max_size()
		{
			return (_alloc.max_size());
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/*********************************************************ELEMENT ACCESS*********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
			mapped_type& operator[] (const key_type& k)
			{
				return (*(this->insert(value_type(k, mapped_type())).first)).second;
			}
			mapped_type& at (const key_type& k)
			{
				iterator it = find(k);
				if (it == end())
					throw std::out_of_range("out_of_range");
				return ((*it).second);
			}
			const mapped_type& at (const key_type& k) const
			{
				const_iterator it = find(k);
				if (it == end())
					throw std::out_of_range("out_of_range");
				return ((*it).second);
			}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************MODIFIERS***********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		pair<iterator,bool> insert(const value_type& val)
		{
			nodePtr s= tree.search(val);
			if (s)
			{
				return (ft::make_pair(iterator(s), false));
			}
			node_ptr = tree.insert(val);
			ft::pair<iterator, bool> value_2 = ft::make_pair(iterator(node_ptr), true);
			return(value_2);
		}
		template <class InputIterator> 
		void insert (InputIterator first, InputIterator last)
		{
			while ( (first != last))
			{
				insert(*first);
				++first;
			}
			
		};
		iterator insert(iterator position, const value_type& val)
		{
			(void)position;
			return (insert(val).first);
		}

		void erase (iterator position)
		{
			position._root = tree.deleteNode(position._root);
			
		}
		size_type erase (const key_type& k)
		{
			iterator it = find(k);
			if (it == end())
				return (0);
			erase(it);
			return (1);
		}
   		void erase (iterator first, iterator last)
		{
			iterator to_delete;
			if (first == last)
				return ;
			to_delete = first;
			erase(++first, last);
			erase(to_delete);
		}

		void swap (map& x)
		{
			nodePtr			*tmp;
			size_type		tmpSize;
			if (x == *this)
				return ;
			tmp = x.node_ptr;
			tmpSize = x._size;
			x.node_ptr = this->node_ptr;
			x._size = this->_size;
			this->_size = tmpSize;
			this->node_ptr = tmpSize;
		}

		void clear() {this->erase(begin(), end());}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************OBSERVERS***********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		key_compare key_comp() const
		{ return (key_compare());}
		// value_compare value_comp() const;
		
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************OPERATIONS**********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		iterator find (const key_type& k)
		{
			ft::pair<Key, T> toSearch(ft::make_pair(k, mapped_type()));
			nodePtr	toFind = tree.search(toSearch);
			if (toFind)
				return (iterator(tree._node, toFind, false));
			else
				return (end());
		}
		const_iterator find (const key_type& k) const
		{
			ft::pair<Key, T> toSearch(ft::make_pair(k, mapped_type()));
			nodePtr	toFind = tree.search(toSearch);
			if (toFind)
				return (const_iterator(tree._node, toFind, false));
			else
				return (end());
		}
		size_type count (const key_type& k) const
		{
			if (find(k) == end())
				return (0);
			return (1);
		}
		
		iterator lower_bound (const key_type& k)
		{
			iterator	it = begin();
			while (it != it->end())
			{
				if (!_comparator(it->first, k))
					break ;
				it++;
			}
			return (it);
		}
		const_iterator lower_bound (const key_type& k) const
		{
			const_iterator	it = begin();
			while (it != it->end())
			{
				if (!_comparator(it->first, k))
					break ;
				it++;
			}
			return (it);
		}
		iterator upper_bound (const key_type& k)
		{
			iterator	beg = begin();
			iterator	end = end();
			while (beg != end)
			{
				if (_comparator(k, (*beg).first))
					break ;
				beg++;
			}
			return (beg);
		}
		const_iterator upper_bound (const key_type& k) const
		{
			return (const_iterator(this->upper_bound(k)));
		}
		pair<iterator,iterator>             equal_range (const key_type& k)
		{
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		}
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return (ft::make_pair(lower_bound(k), upper_bound(k)));	
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/************************************************************ALLOCATOR**********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			allocator_type get_allocator() const;
			private:
				key_compare	_comparator;
				allocator_type	_valueAlloc;
	};
}


#endif

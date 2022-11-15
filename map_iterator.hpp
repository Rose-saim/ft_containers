
#ifndef MapIterator_HPP
# define MapIterator_HPP

# include <iterator>
# include "node.hpp"

namespace ft
{
    template <class T, class U, class Category = std::bidirectional_iterator_tag, class Distance = std::ptrdiff_t,
        class Pointer = U*, class Reference = U&>
	class MapIterator
	{
		private:
			    	typedef T         		value_type;
					typedef Distance  		difference_type;
					typedef Pointer   		pointer;
					typedef Reference 		reference;
					typedef Category  		iterator_category;
		protected:
				T	*_ptr;
		public:

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/***********************************************************CONSTRUCTOR***********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			MapIterator(): _ptr(NULL) {};
			MapIterator(const MapIterator &other)
			{
				*this = other;
			}
			MapIterator(T *ptr): _ptr(ptr){}
			~MapIterator(){};

			MapIterator &operator=(MapIterator const &other)
			{
				if (this != &other)
					_ptr = other._ptr;
				return (*this);
			}
			MapIterator &operator++()
			{
				_ptr = _ptr->next();
				return (*this);
			}
			MapIterator &operator--()
			{
				_ptr = _ptr->prev();
				return (*this);
			}
			MapIterator operator++(int)
			{
				MapIterator	tmp = *this;
				_ptr = _ptr->next();
				return (tmp);
			}
			MapIterator operator--(int)
			{
				MapIterator	tmp = *this;
				_ptr = _ptr->prev();
				return (tmp);
			}
			bool operator==(const MapIterator &it) const
			{
				return (it._ptr == _ptr);
			}
			bool &operator!=( const MapIterator &it)
			{
				return (it._ptr != _ptr);
			}
			MapIterator &operator*(const MapIterator	&other)
			{
				return (_ptr->value);
			}
			MapIterator &operator->()
			{
				return (&_ptr->value);
			}
	};

	template <class T, class U, class ConstMapIterator, class Category = std::bidirectional_iterator_tag, class Distance = std::ptrdiff_t,
    class Pointer = U*, class Reference = U&>
	class ConstMapIterator
	{
		private:
			    	typedef T         		value_type;
				typedef Distance  		difference_type;
				typedef Pointer   		pointer;
				typedef Reference 		reference;
				typedef Category  		iterator_category;
		protected:
				T	*_ptr;
		public:

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/********************************************************************************************************************************/
		/***********************************************************CONSTRUCTOR***********************************************************/
		/********************************************************************************************************************************/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			ConstMapIterator(): _ptr(NULL) {};
			ConstMapIterator(const ConstMapIterator &other)
			{
				*this = other;
			}
			ConstMapIterator(T *ptr): _ptr(ptr){}
			~ConstMapIterator(){};
		
			ConstMapIterator &operator=(ConstMapIterator const &other)
			{
				if (this != &other)
					_ptr = other._ptr;
				return (*this);
			}
			ConstMapIterator &operator++()
			{
				_ptr = _ptr->next();
				return (*this);
			}
			ConstMapIterator &operator--()
			{
				_ptr = _ptr->prev();
				return (*this);
			}
			ConstMapIterator operator++(int)
			{
				ConstMapIterator	tmp = *this;
				_ptr = _ptr->next();
				return (tmp);
			}
			ConstMapIterator operator--(int)
			{
				ConstMapIterator	tmp = *this;
				_ptr = _ptr->prev();
				return (tmp);
			}
			bool operator==(const ConstMapIterator &it) const
			{
				return (it._ptr == _ptr);
			}
			bool &operator!=( const ConstMapIterator &it)
			{
				return (it._ptr != _ptr);
			}
			ConstMapIterator &operator*(const ConstMapIterator	&other)
			{
				return (_ptr->value);
			}
			ConstMapIterator &operator->()
			{
				return (&_ptr->value);
			}
	};
}


#endif

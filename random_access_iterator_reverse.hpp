#ifndef RANDOM_ACCESS_ITERATOR_REV_HPP
# define RANDOM_ACCESS_ITERATOR_REV_HPP
#include "./random_access_iterator.hpp"
namespace ft  
{  
template <typename T>
class random_access_iterator_rev
{
	#define subcrement_2(SOURCE, VALUE) SOURCE -= VALUE
	#define increment_2(SOURCE, VALUE) SOURCE += VALUE
	public:
	typedef T*							pointer;
	typedef T&							reference;
	typedef long int 					range;
	typedef random_access_iterator_rev	this_class;

	random_access_iterator_rev(pointer init = 0) : ptr(init) {}  
	random_access_iterator_rev(const random_access_iterator<T>& src) : ptr(src.getElemPtr() - 1) {}
	~random_access_iterator_rev() {}     

	random_access_iterator<T> base() const { return (random_access_iterator<T>(ptr + 1)); }
	#ifdef $OP_CONTEXT
	# undef $OP_CONTEXT
	#endif
	# define $OP_CONTEXT \
		template <typename U> \
		friend bool

	#ifdef $OP_CONTEXT_PARAM
	# undef $OP_CONTEXT_PARAM
	#endif
	# define $OP_CONTEXT_PARAM \
		const random_access_iterator_rev<T>& l, const random_access_iterator_rev<U>& r
	$OP_CONTEXT operator>($OP_CONTEXT_PARAM) 					{ return (l.base() < r.base()); }
	$OP_CONTEXT operator<($OP_CONTEXT_PARAM) 					{ return (l.base() > r.base()); }
	$OP_CONTEXT operator==($OP_CONTEXT_PARAM) 					{ return (l.base() == r.base()); }
	$OP_CONTEXT operator!=($OP_CONTEXT_PARAM) 					{ return (l.base() != r.base()); }
	$OP_CONTEXT operator>=($OP_CONTEXT_PARAM) 					{ return (l.base() <= r.base()); }
	$OP_CONTEXT operator<=($OP_CONTEXT_PARAM) 					{ return (l.base() >= r.base()); }

	this_class& operator=(const this_class& src)				{ if (this == &src) return (*this); ptr = src.ptr; return (*this); }
	this_class& operator++()									{ subcrement_2(ptr, 1); return (*this); }
	this_class& operator--()									{ increment_2(ptr, 1); return (*this); }
	this_class& operator+=(int n)								{ subcrement_2(ptr, n); return (*this); }
	this_class& operator-=(int n)								{ increment_2(ptr, n); return (*this); }
	this_class	operator+(int n)								{ this_class ret(*this); subcrement_2(ret.ptr, n); return (ret); }
	this_class	operator-(int n)								{ this_class ret(*this); increment_2(ret.ptr, n); return (ret); }
	this_class 	operator--(int)									{ this_class ret(ptr); operator--(); return (ret); }
	this_class	operator++(int)									{ this_class ret(ptr); operator++(); return (ret); }
	reference	operator[](int n)								{ pointer ret(ptr - n);return (*ret); }
	reference	operator*() const								{ return (*ptr); }

	pointer	operator->() const									{ return (ptr); }
	pointer getElemPtr() const 									{ return (ptr); }
	operator random_access_iterator_rev<const T> (void) 		{ return random_access_iterator_rev<const T>(ptr); }
	range operator-(this_class it) const 						{ return (it.ptr - this->ptr); }
	friend this_class operator+(int n, const this_class& src)	{ (void)src;this_class ret(src); return (ret += n); }
	friend this_class operator-(int n, const this_class& src)	{ (void)src;this_class ret(src); return (ret -= n); }
	private:
		pointer ptr;
};
} //namespace ft
#endif
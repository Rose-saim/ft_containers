#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP
namespace ft
{
template <typename T>
class random_access_iterator
{
		#define subcrement(SOURCE, VALUE) SOURCE -= VALUE
		#define increment(SOURCE, VALUE) SOURCE += VALUE
	public:
		typedef	random_access_iterator	this_class;
		typedef	T*	pointer;
		typedef	T&	reference;
		typedef long int 				range;

		random_access_iterator(pointer init = 0): ptr(init) {}
		random_access_iterator(const random_access_iterator<T>& src) : ptr(src.getElemPtr() - 1) {}
		~random_access_iterator(){}

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
			const random_access_iterator<T>& l, const random_access_iterator<U>& r
		$OP_CONTEXT operator==($OP_CONTEXT_PARAM) 					{ return (l.getElemPtr() == r.getElemPtr() ); }
		$OP_CONTEXT operator!=($OP_CONTEXT_PARAM) 					{ return (l.getElemPtr() != r.getElemPtr() ); }
		$OP_CONTEXT operator>=($OP_CONTEXT_PARAM) 					{ return (l.getElemPtr() >= r.getElemPtr() ); }
		$OP_CONTEXT operator<=($OP_CONTEXT_PARAM) 					{ return (l.getElemPtr() <= r.getElemPtr() ); }
		$OP_CONTEXT operator>($OP_CONTEXT_PARAM) 					{ return (l.getElemPtr() > r.getElemPtr() ); }
		$OP_CONTEXT operator<($OP_CONTEXT_PARAM) 					{ return (l.getElemPtr() < r.getElemPtr() ); }

        this_class& operator=(const this_class &src) {if (this == &src) return *this; this->ptr = src.ptr; return *this;}
        this_class operator-(int n) {this_class ret = *this; ret.ptr -= n; return ret;}
        this_class operator+(int n) {this_class ret = *this; ret.ptr += n; return ret;}
		this_class& operator++() {++ptr; return *this;}
        this_class operator++(int) {this_class ret = *this; ++(*this); return ret;}
		this_class& operator--() {--ptr; return *this;}
        this_class operator--(int) {this_class ret = *this; --(*this); return ret;}
		this_class& operator+=(int n) {ptr += n; return *this;}
		this_class& operator-=(int n) {ptr -= n; return *this;}
		reference	operator[](int n)								{ pointer ret(ptr + n);return (*ret); }
		reference	operator*() const								{ return (*ptr); }
        
		pointer	operator->() const									{ return (ptr); }
		pointer getElemPtr() const 									{ return (ptr); }
		operator random_access_iterator<const T> (void) 			{ return random_access_iterator<const T>(ptr); }
		range operator-(this_class it) const 						{ return (this->ptr - it.ptr);}
		friend this_class operator+(int n, const this_class& src)	{ (void)src;this_class ret(src); return (ret += n); }
		friend this_class operator-(int n, const this_class& src)	{ (void)src;this_class ret(src); return (ret -= n); }
	private:
		this_class	ptr;
};
} //namespace ft
#endif
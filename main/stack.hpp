#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {
template <class T, class Container = ft::vector<T> >
class stack
{
	public:

	typedef typename Container::value_type		value_type;
	typedef typename Container::size_type		size_type;
	typedef typename Container::reference		reference;
	typedef typename Container::const_reference	const_reference;
	typedef Container							container_type;

	explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}
	
	~stack() {}

	bool	empty() const { return (c.empty()); }

	size_type size() const { return (c.size()); }

	void	push(const value_type& val)	{ c.push_back(val); }

	void	pop() { c.pop_back(); }

	reference	top() { return c.back(); }
	
	const_reference	top() const { return c.back(); }
	
	friend bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.c == rhs.c);
	}
	friend bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.c != rhs.c);
	}
	friend bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.c < rhs.c);
	}
	friend bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.c <= rhs.c);
	}
	friend bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.c > rhs.c);
	}
	friend bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.c >= rhs.c);
	}

	protected:
	
	container_type c;

};

}

#endif

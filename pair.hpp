#ifndef  PAIR_HPP
#define  PAIR_HPP

namespace ft
{
	template	<class T1, class T2>
	struct pair
	{
		public:
			typedef	T1	first_type;
			typedef	T2	second_type;
			first_type	first;
			second_type	second;

			//Constructor
			
			pair(): first(), second(){}
			template<class U, class V>
			pair (const pair<U,V>& src): first(src.first), second(src.second){}
			pair (const first_type& a, const second_type& b): first(a), second(b){}
			pair& operator= (const pair& src)
			{
				if (this == &src)
				{
					return (*this);
				}
				second = src.second;
				this->first = src.first;
				return (*this);
			}
	};

	template<class T1, class T2>
	pair<T1,T2>	make_pair (T1 k, T2 v) {return (pair<T1, T2>(k, v));}

	///////////////////////     Non-member function overloads      ////////////////////////

	template<class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template<class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T1, class T2>
	bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second));
	}

	template<class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T1, class T2>
	bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs < lhs);
	}

	template<class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs < rhs));
	}
}
#endif
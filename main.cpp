#include <iostream>
#include "map.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  ft::map<char,int> first;

  // first['a']=10;
  // first['b']=30;
  // first['c']=50;
  // first['d']=70;

  // ft::map<char,int> second (first.begin(),first.end());

  // ft::map<char,int> third (second);

  // ft::map<char,int,classcomp> fourth;                 // class as Compare
  // std::cout << first['a'] << std::endl;
  return 0;
}
#include "test.hpp"

void	test_constructors(std::ofstream& ofs)
{
	VECTOR<float> defaultVec;
	if (defaultVec.size() != 0)
		std::cout << RED << "ERROR default constructor: size not at 0" << RESET << std::endl;
	if (defaultVec.capacity() != 0)
		std::cout << RED << "error default constructor: capacity not at 0" << RESET << std::endl;
	printVector(defaultVec, ofs);
	
	VECTOR<float> Vec(4);
	if (Vec.size() != 4)
		std::cout << RED << "error constructor(n): size not at 0" << RESET << std::endl;
	if (Vec.capacity() != 4)
		std::cout << RED << "error default constructor: capacity no at the right value" << RESET << std::endl;
	printVector(Vec, ofs);
	if (Vec[0] || Vec[1] || Vec[2] || Vec[3])
		std::cout << RED << "error default constructor: value not at 0" << RESET << std::endl;
	
	VECTOR<float> fillVec(6, 50.5);
	if (fillVec.size() != 6)
		std::cout << RED << "error constructor(n, v): size not at the right value" << RESET << std::endl;
	if (fillVec.capacity() != 6)
		std::cout << RED << "error constructor(n, v): capacity not at the right value" << RESET << std::endl;
	printVector(fillVec, ofs);
	for (VECTOR<float>::size_type i = 0; i < 6; i++)
	{
		ofs << fillVec[i] << std::endl;
		if (fillVec[i] != 50.5)
			std::cout << RED << "error constructor(n, v): elements not at the right value" << RESET << std::endl;
	}
	
	VECTOR<float> rangeVec(fillVec.begin(), fillVec.end());
	if (rangeVec.size() != 6)
		std::cout << RED << "error constructor(begin, end): size not at the right value" << RESET << std::endl;
	if (rangeVec.capacity() != 6)
		std::cout << RED << "error constructor(begin, end): capacity not at the right value" << RESET << std::endl;
	printVector(rangeVec, ofs);
	for (VECTOR<float>::size_type i = 0; i < 6; i++)
	{
		if (rangeVec[i] != 50.5)
			std::cout << RED << "error constructor(begin, end): elements not at the right value" << RESET << std::endl;
	}
	
	VECTOR<float> copyVec(rangeVec);
	if (copyVec.size() != 6)
		std::cout << RED << "error copy constructor: size not at the right value" << RESET << std::endl;
	if (copyVec.capacity() != 6)
		std::cout << RED << "error copy constructor: capacity not at the right value" << RESET << std::endl;
	printVector(copyVec, ofs);
	if (&(copyVec[0]) == &(rangeVec[0]))
		std::cout << RED << "error copy constructor: Not a deep copy" << RESET << std::endl;
	for (VECTOR<float>::size_type i = 0; i < 6; i++)
	{
		if (copyVec[i] != 50.5)
			std::cout << RED << "error copy constructor: elements not at the right value" << RESET << std::endl;
	}
	
	VECTOR<float> copyOperatorVec = copyVec;
	if (copyVec.size() != 6)
		std::cout << RED << "error assign constructor: size not at the right value" << RESET << std::endl;
	if (copyVec.capacity() != 6)
		std::cout << RED << "error assign constructor: capacity not at the right value" << RESET << std::endl;
	printVector(copyOperatorVec, ofs);	
	if (&(copyOperatorVec[0]) == &(copyVec[0]))
		std::cout << RED << "error assign copy constructor: Not a deep copy" << RESET << std::endl;
	for (VECTOR<float>::size_type i = 0; i < 6; i++)
	{
		if (copyOperatorVec[i] != 50.5)
			std::cout << RED << "error assign copy constructor: elements not at the right value" << RESET << std::endl;
	}

	float	tab[] = {3, 30, 300, 3000};
	VECTOR<float>::iterator it(tab);
	VECTOR<float> tabVec(it, it + 4);
	if (tabVec.size() != 4)
		std::cout << RED << "error constructor(tab.begin, tab.end): size not at the right value" << RESET << std::endl;
	if (tabVec.capacity() != 4)
		std::cout << RED << "error constructor(tab.begin, tab.end): capacity not at the right value" << RESET << std::endl;
	printVector(tabVec, ofs);
	VECTOR<float>::value_type val = 3;
	for (VECTOR<float>::size_type i = 0; i < 4; i++)
	{
		ofs << val << std::endl;
		if (tabVec[i] != val)
			std::cout << RED << "error constructor(tab.begin, tab.end): elements not at the right value" << RESET << std::endl;
		val *= 10;
	}
}

void	test_iterators(std::ofstream& ofs)
{
	//----------BEGIN()/END()---------

	VECTOR<int> vec(1, 2);
	vec.push_back(4);
	vec.push_back(8);
	vec.push_back(10);
	vec.push_back(6);

	VECTOR<int>::iterator it;
	VECTOR<int>::iterator ite;
	it = vec.begin();
	ite = vec.end();
	if (&(*it) != &(vec[0]))
		std::cout << RED << "error: begin iterator don't point to the first element" << RESET << std::endl;
	if (&(*ite) != &(vec[vec.size()]))
		std::cout << RED << "error: begin iterator don't point to the last element + 1" << RESET << std::endl;

	VECTOR<int>::value_type v = 2;
	for (VECTOR<int>::size_type i = 0; i < vec.size(); i++)
	{
		ofs << *it << " " << std::endl;
		if (*it != v)
		{
			std::cout << RED << "error: iterator don't point a good value" << RESET << std::endl;
			break;
		}
		it++;
		v += 2;
	}

	//---------RBEGIN()/REND()--------
	
	VECTOR<int> rvec(1, 1);
	rvec.push_back(4);
	rvec.push_back(3);
	rvec.push_back(2);
	rvec.push_back(5);

	VECTOR<int>::reverse_iterator rit;
	VECTOR<int>::reverse_iterator rite;
	rit = rvec.rbegin();
	rite = rvec.rend();
	if (&(*rit) != &(rvec[rvec.size() - 1]))
		std::cout << RED << "error: rbegin iterator don't point to the last element" << RESET << std::endl;
	if (&(*rite) != &(rvec[-1]))
		std::cout << RED << "error: begin iterator don't point to the first element - 1" << RESET << std::endl;
	
	VECTOR<int>::value_type val = 5;
	while (rit != rite)
	{
		ofs << *rit << " " << std::endl;
		if (*rit != val)
		{
			std::cout << RED << "error: reverse_iterator don't point a good value" << RESET << std::endl;
			break;
		}
		val--;
		rit++;
	}
	printVector(rvec, ofs);
	if (rit == rvec.rend() - 1)
		std::cout << "VECTOR::reverse_iterator are iterable" << std::endl;
}

void	test_capacity(void)
{
	//--------SIZE()----------------
	
	VECTOR<int> vec;
	if (vec.size() != 0)
		std::cout << RED << "error: size invalid" << RESET << std::endl;
	
	VECTOR<int> vec1(10);
	if (vec1.size() != 10)
		std::cout << RED << "error: size invalid" << RESET << std::endl;
	
	VECTOR<int> vec2(4, 42);
	if (vec2.size() != 4)
		std::cout << RED << "error: size invalid" << RESET << std::endl;
	
	VECTOR<int> vec3(vec2.begin(), vec2.end());
	// modify size with push_back()/pop_back()
	vec3.push_back(1);
	vec3.push_back(1);
	vec3.push_back(1);
	vec3.pop_back();
	if (vec3.size() != 6)
		std::cout << RED << "error: size invalid" << RESET << std::endl;
	
	//-------------CAPACITY()-------------
	
	VECTOR<int> test;
	if (test.capacity() != 0)
		std::cout << RED << "error: capacity invalid" << RESET << std::endl;
	
	VECTOR<int> test2(15);
	if (test2.capacity() != 15)
		std::cout << RED << "error: capacity invalid" << RESET << std::endl;
	
	VECTOR<int> test3(5, 42);
	if (test3.capacity() != 5)
		std::cout << RED << "error: capacity invalid" << RESET << std::endl;
	// modify capacity with push_back()
	test3.push_back(1);
	test3.push_back(1);
	test3.push_back(1);
	if (test3.capacity() < 7)
		std::cout << RED << "error: capacity invalid" << RESET << std::endl;
	
	// modify size with pop_back() must doesnt change capacity !
	test3.pop_back();
	test3.pop_back();
	test3.pop_back();
	test3.pop_back();
	test3.pop_back();
	if (test3.capacity() < 7)
		std::cout << RED << "error: capacity invalid" << RESET << std::endl;
	
	//-------------EMPTY()-----------

	VECTOR<int> e;
	if (e.empty() == false)
		std::cout << RED << "error empty: invalid value" << RESET << std::endl;
	
	VECTOR<int> e1(5, 30);
	if (e1.empty() == true)
		std::cout << RED << "error empty: invalid value" << RESET << std::endl;
	e1.pop_back();
	e1.pop_back();
	e1.pop_back();
	e1.pop_back();
	e1.pop_back();
	if (e1.empty() == false)
		std::cout << RED << "error empty: invalid value" << RESET << std::endl;
	
	//---------RESERVE()------------

	VECTOR<int> res(4, 2);
	VECTOR<int>::size_type _start = res.size();
	
	res.reserve(4);
	res.reserve(3);
	res.reserve(2);
	res.reserve(1);
	if (res.capacity() != 4)
		std::cout << RED << "error reserve: not a correct capacity" << RESET << std::endl;
	if (res.size() != _start)
		std::cout << RED << "error reserve: size has been affected" << RESET << std::endl;
	
	res.reserve(30);
	if (res.capacity() < 30)
		std::cout << RED << "error reserve: not a correct capacity" << RESET << std::endl;
	if (res.size() != _start)
		std::cout << RED << "error reserve: size has been affected" << RESET << std::endl;
	
	res.reserve(500);
	if (res.capacity() < 500)
		std::cout << RED << "error reserve: not a correct capacity" << RESET << std::endl;
	if (res.size() != _start)
		std::cout << RED << "error reserve: size has been affected" << RESET << std::endl;
	
	//---------RESIZE()-----------

	VECTOR<int> t_test(10, 9);

	t_test.resize(2);
	if (t_test.size() != 2)
		std::cout << RED << "error resize: invalid size" << RESET << std::endl;
	
	t_test.resize(5, 93);
	if (t_test.size() != 5)
		std::cout << RED << "error resize: invalid size" << RESET << std::endl;
	if (t_test[2] != 93 || t_test[3] != 93 || t_test[4] != 93)
		std::cout << RED << "error resize: n elements created not at 0" << RESET << std::endl;
	
	t_test.resize(12);
	if (t_test.size() != 12)
		std::cout << RED << "error resize: invalid size" << RESET << std::endl;
	if (t_test.capacity() < 12)
		std::cout << RED << "error resize: invalid capacity after resize(n > .capacity())" << RESET << std::endl;
	if (t_test[5] || t_test[6] || t_test[7] || t_test[8] || t_test[9] || t_test[10] || t_test[11])
		std::cout << RED << "error resize: n elements created not at 0" << RESET << std::endl;
	
	//----------MAXSIZE()--------
}

void	test_access(std::ofstream& ofs)
{
	//-------OPERATOR[]---------
	
	VECTOR<double> _test(6, 0);
	_test[0] = 11.11;
	_test[1] = 22.11;
	_test[2] = 33.11;
	_test[3] = 44.11;
	_test[4] = 55.11;
	_test[5] = 66.11;
	VECTOR<double>::value_type val = 11.11;
	for (VECTOR<double>::size_type i = 0; i < _test.size(); i++)
	{
		if (_test[i] != (11.11 + (i * 11)))
			std::cout << RED << "error operator[]: not good value" << RESET << std::endl;
		ofs << "[" << _test[i] << "]";
		val += 11;
	}

	VECTOR<double>::size_type i = 0;
	if (_test[i + 4] != 55.11)
		std::cout << RED << "error operator[]: not good value" << RESET << std::endl;
	
	i += 2;

	if (_test[i - 2] != 11.11)
		std::cout << RED << "error operator[]: not good value" << RESET << std::endl;
	
	ofs << std::endl;

	//----------AT()----------

	VECTOR<std::string> t_testAt(6);
	for (VECTOR<std::string>::size_type i = 0; i < 6; i++)
	{
		switch (i)
		{
			case 0:
				t_testAt.at(i) = "one";
				break;
			case 1:
				t_testAt.at(i) = "two";
				break;
			case 2:
				t_testAt.at(i) = "three";
				break;
			case 3:
				t_testAt.at(i) = "four";
				break;
			case 4:
				t_testAt.at(i) = "five";
				break;
			case 5:
				t_testAt.at(i) = "six";
				break;
		}
	}
	std::string strs[6] = {"one", "two", "three", "four", "five", "sixe"};
	for (VECTOR<std::string>::size_type i = 0; i < 6; i++)
	{
		ofs << "(" << t_testAt.at(i) << ")";
		if (strs[i].compare(t_testAt.at(i)) != 0)
			std::cout << RED << "error .at(): point to invaid value" << RESET << std::endl;
	}
	ofs << std::endl;
	
	VECTOR<std::string>::size_type j = 0;
	t_testAt.at(j + 2) = "modify";
	std::string testStr = t_testAt.at(2);
	ofs << t_testAt.at(2) << std::endl;
	if (testStr.compare("modify") != 0)
		std::cout << RED << "error .at(): point to invaid value" << RESET << std::endl;
	
	j = 4;
	t_testAt.at(j - 3) = "new modify";
	testStr = t_testAt.at(1);
	ofs << t_testAt.at(1) << std::endl;
	if (testStr.compare("new modify") != 0)
		std::cout << RED << "error .at(): point to invaid value" << RESET << std::endl;

	//test out of range exception
	try {
		t_testAt.at(10) = "new string";
	}
	catch (std::exception& e)
	{
		ofs << e.what() << std::endl;
	}

	//---------FRONT()------------
	
	VECTOR<char> vect;
	vect.push_back('H');
	vect.push_back('e');
	vect.push_back('l');
	vect.push_back('l');
	vect.push_back('o');
	vect.push_back('!');
	vect.push_back('!');
	ofs << "-> " << vect.front() << std::endl;
	if (vect.front() != 'h')
		std::cout << RED << "error front(): front returns(reference) is a bad value" << RESET << std::endl;
	for (VECTOR<char>::size_type i = 0; i < 7; i++)
	{
		ofs << vect.front();
		vect.erase(vect.begin());
	}
	ofs << std::endl;
	
	VECTOR<char> vect2(1, 'Z');
	ofs << "-> " << vect2.front() << std::endl;
	if (vect2.front() != 'Z')
		std::cout << RED << "error front(): front returns(reference) is a bad value" << RESET << std::endl;
	
	//---------BACK()-------------

	VECTOR<std::string> tab;

	tab.push_back("only three element");
	ofs << "[" << tab.back() << "]" << std::endl;
	if (tab.back() != "only three element")
		std::cout << RED << "error back(): back returns(reference) is a bad value" << RESET << std::endl;
	
	tab.back() = "only three element is modified";
	ofs << "[" << tab.back() << "]" << std::endl;
	if (tab.back() != "only three element is modified")
		std::cout << RED << "error back(): back returns(reference) is a bad value" << RESET << std::endl;
	
	VECTOR<char> tab2;
	tab2.push_back('A');
	tab2.push_back('B');
	tab2.push_back('C');
	tab2.push_back('D');
	tab2.push_back('E');
	printVector(tab2, ofs);
	char c = 'E';
	for (VECTOR<char>::size_type i = 0; i < 1; i++)
	{
		ofs << tab2.back();
		if (tab2.back() != c)
			std::cout << RED << "error back(): back returns(reference) is a bad value" << RESET << std::endl;
		tab2.pop_back();
		c--;
	}
	ofs << std::endl;
}

void	test_modifiers(std::ofstream& ofs)
{
	//----------PUSH_BACK()-----------
	
	VECTOR<double> vec;
	
	VECTOR<double>::value_type val = 0;
	for (VECTOR<double>::size_type i = 0; i < 10; i++)
	{
		vec.push_back(val);
		if (vec.size() != i + 1)
			std::cout << RED << "error push_back(): size() is not updated correctly" << RESET << std::endl;
		val += 0.51;
	}
	val = 0;
	for (VECTOR<double>::size_type i = 0; i < 25; i++)
	{
		ofs << "[" << vec[i] << "]";
		if (vec[i] != val)
			std::cout << RED << "error push_back(): values pushed are not identical to those expected" << RESET << std::endl;
		val += 0.51;
	}
	ofs << std::endl;

	VECTOR<double> vec2(2, 4.4);

	vec2.push_back(12.12);
	if (*(vec2.end() - 1) != 12.12)
		std::cout << RED << "error push_back(): value push not at the end of array" << RESET << std::endl;
	
	//-----------POP_BACK()------------

	VECTOR<int>	test(10);

	VECTOR<int>::value_type value = 0;
	for (VECTOR<int>::size_type i = 0; i < 15; i++)
		test[i] = value++;
	test.pop_back();
	test.pop_back();
	test.pop_back();
	for (VECTOR<int>::size_type i = 0; i < 15; i++)
	{
		ofs << "[" << test[i] << "]";
		if (i > 6 && test[i] != static_cast<int>(i))
			std::cout << RED << "error pop_back(): element < size && < capacity set at zero after called by this one" << RESET << std::endl;
	}
	ofs << std::endl;
	if (test.size() != 7)
		std::cout << RED << "error pop_back(): size is not updated correctly" << RESET << std::endl;
	
	//------------ASSIGN()--------------
	
	VECTOR<int> vect;

	// basic assign (n, value)
	vect.assign(5, 50);
	for (VECTOR<int>::iterator it = vect.begin(); it != vect.end(); it++)
	{
		if (*it != 50)
			std::cout << RED << "error assign(): wrong value" << RESET << std::endl;
		ofs << "[" << *it << "]";
	}
	ofs << std::endl;
	printAttributes(vect, ofs);
	if (vect.size() != 5)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;
	
	// a new basic assign(n, value) in the same vector -> must updated size at n
	vect.assign(1, -4);
	for (VECTOR<int>::iterator it = vect.begin(); it != vect.end(); it++)
	{
		if (*it != -4)
			std::cout << RED << "error assign(): wrong value" << RESET << std::endl;
		ofs << "[" << *it << "]";
	}
	if (vect.size() != 1)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;
	ofs << std::endl;
	printAttributes(vect, ofs);

	VECTOR<int> vect2(10);

	VECTOR<int>::value_type v = 0;
	for (VECTOR<int>::size_type i = 0; i < 10; i++)
	{
		vect2[i] = v * 10;
		v++;
	}
	
	// assign with iterators(first, end)
	VECTOR<int> vect3;
	vect3.assign(vect2.begin(), vect2.end());
	printVector(vect3, ofs);
	v = 0;
	for (VECTOR<int>::iterator it = vect3.begin(); it != vect3.end(); it++)
	{
		if (*it != v * 10)
			std::cout << RED << "error assign(): wrong value" << RESET << std::endl;
		v++;
	}
	if (vect3.size() != 10)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;
	
	vect3.assign(vect2.begin() + 1, vect2.end() - 1);
	v = 1;
	for (VECTOR<int>::iterator it = vect3.begin(); it != vect3.end(); it++)
	{
		ofs << "[" << *it << "]";
		if (*it != v * 10)
			std::cout << RED << "error assign(): wrong value" << RESET << std::endl;
		v++;
	}
	ofs << std::endl;
	if (vect3.size() != 8)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;

	vect3.assign(vect3.begin(), vect3.end() - 3);
	v = 1;
	for (VECTOR<int>::iterator it = vect3.begin(); it != vect3.end(); it++)
	{
		ofs << "[" << *it << "]";
		if (*it != v * 10)
			std::cout << RED << "error assign(): wrong value" << RESET << std::endl;
		v++;
	}
	ofs << std::endl;
	if (vect3.size() != 5)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;

	// assign with array[] pointers(first, end)
	int	tabInt[] = {33, 66, 99, 130, 165, 200};
	vect3.assign(tabInt, tabInt + 6);
	v = 33;
	for (VECTOR<int>::iterator it = vect3.begin(); it != vect3.end(); it++)
	{
		ofs << "[" << *it << "]";
		if (*it != v)
			std::cout << RED << "error assign(): wrong value" << RESET << std::endl;
		v += 33;
	}
	ofs << std::endl;
	if (vect3.size() != 6)
		std::cout << RED << "error assign(): size are not updated correctly after function call" << RESET << std::endl;

	//-----------ERASE()-------------

	VECTOR<float> vecTest;

	VECTOR<float>::value_type f = 11.11f;	
	for (int i = 0; i < 10; i++)
	{
		vecTest.push_back(f);
		ofs << "(" << vecTest[i] << ")";
		f += 10.10f;
	}
	ofs << std::endl;
	f = *(vecTest.begin() + 3);
	vecTest.erase(vecTest.begin() + 3);
	for (VECTOR<float>::size_type i = 0; i < vecTest.size(); i++)
	{
		ofs << "(" << vecTest[i] << ")";
		if (vecTest[i] == f)
			std::cout << RED << "error erase():: value not removed!" << RESET << std::endl;
	}
	ofs << std::endl;
	if (vecTest.size() != 9)
		std::cout << RED << "error erase(): size not updated!" << RESET << std::endl;
	
	VECTOR<float> saveValues(vecTest.begin(), vecTest.end() - 4);
	vecTest.erase(vecTest.begin(), vecTest.end() - 4);
	
	for (VECTOR<float>::size_type i = 0; i < vecTest.size(); i++)
	{
		for (VECTOR<float>::size_type j = 0; j < saveValues.size(); j++)
		{
			if (vecTest[i] == saveValues[j])
				std::cout << RED << "error erase(): value not removed!" << RESET << std::endl;
		}
		ofs << "(" << vecTest[i] << ")";
	}
	ofs << std::endl;
	if (vecTest.size() != 4)
		std::cout << RED << "error erase(): size not updated!" << RESET << std::endl;
	
	//---------CLEAR()-------------
	
	VECTOR<char> vecl;

	vecl.push_back('x');
	vecl.push_back('y');
	vecl.push_back('z');

	vecl.clear();
	for (VECTOR<char>::size_type i = 0; i < vecl.size(); i++)
	{
		std::cout << RED << "error clear(): size not updated at zero" << RESET << std::endl;
		break;
	}
	printVector(vecl, ofs);

	VECTOR<char> vecl1(10, 'x');

	vecl1.clear();
	vecl1.clear();
	vecl1.clear();
	for (VECTOR<char>::size_type i = 0; i < vecl1.size(); i++)
	{
		std::cout << RED << "error clear(): size not updated at zero" << RESET << std::endl;
		break;
	}
	printVector(vecl1, ofs);
	
	//-------------SWAP()----------------

	VECTOR<std::string>	vecStr0(4, "HELLO");
	VECTOR<std::string>	vecStr1(7, "HI");

	ofs << "vecStr0: ";
	printVector(vecStr0, ofs);
	ofs << "vecStr1: ";
	printVector(vecStr1, ofs);
	
	vecStr0.swap(vecStr1);
	
	ofs << "after swap: " << std::endl;
	
	ofs << "vecStr0: ";
	printVector(vecStr0, ofs);
	ofs << "vecStr1: ";
	printVector(vecStr1, ofs);
	if ((vecStr0.size() != 7 || vecStr0.capacity() != 7) || (vecStr1.size() != 4 || vecStr1.capacity() != 4))
		std::cout << RED << "error swap(): invalid attributes" << RESET << std::endl;

	for (VECTOR<std::string>::size_type i = 0; i < vecStr0.size(); i++)
	{
		if (vecStr0[i].compare("HI") != 0)
			std::cout << RED << "error swap(): values are the same as before" << RESET << std::endl;
	}
	for (VECTOR<std::string>::size_type i = 0; i < vecStr1.size(); i++)
	{
		if (vecStr1[i].compare("HELLO") != 0)
			std::cout << RED << "error swap(): values are the same as before" << RESET << std::endl;
	}

	//--------------INSERT()---------------
	
	//insert(pos, value)
	VECTOR<int> VecTest(3, 100);
	VECTOR<int>::iterator it = VecTest.begin();

	it = VecTest.insert(it, 200);
	printVector(VecTest, ofs);
	if (it != VecTest.begin() || *it != 200)
		std::cout << RED << "error insert(): function do not return the correct iterator position" << RESET << std::endl;
	if (!(VecTest[0] == 200 && VecTest[1] == 100 && VecTest[2] == 100 && VecTest[3]))
		std::cout << RED << "error insert(): invalid values in container" << RESET << std::endl;
	if (VecTest.size() != 4)
	std::cout << RED << "error insert(): invalid size after call function" << RESET << std::endl;

	//insert(pos, n, value)

	VECTOR<double> _vec(4, 24.58);

	_vec.insert(_vec.end(), 2, 1999.99);
	printVector(_vec, ofs);
	if (!(_vec[0] == 24.58 && _vec[1] == 24.58 && _vec[2] == 24.58 && _vec[3] == 24.58 && _vec[4] == 1999.99 && _vec[5] == 1999.99))
		std::cout << RED << "error insert(): invalid values in container" << RESET << std::endl;
	if (_vec.size() != 6)
		std::cout << RED << "error insert(): invalid size after call function" << RESET << std::endl;

	//insert(pos, first, end)
	VECTOR<int> VecTest5(2, -42);
	VECTOR<int> VecTest5(6, 33);

	VecTest5.insert(VecTest5.begin() + 1, VecTest5.begin(), VecTest5.end());
	printVector(VecTest5, ofs);
	if (!(VecTest5[0] == -42 && VecTest5[1] == 33 && VecTest5[2] == 33 && VecTest5[3] == 33 && VecTest5[4] == 33 &&
		VecTest5[5] == 33 && VecTest5[6] == 33 && VecTest5[7] == -42))
		std::cout << RED << "error insert(): invalid values in container" << RESET << std::endl;
	if (VecTest5.size() != 8)
	std::cout << RED << "error insert(): invalid size after call function" << RESET << std::endl;
}

int	test_vector(std::ofstream& file)
{
	file << "\e[107m\e[1;30m" << "=============VECTOR TEST===============" << RESET << std::endl;
	test_constructors(file);
	test_iterators(file);
	test_capacity();
	test_access(file);
	test_modifiers(file);
	file << "\e[107m\e[1;30m" << "=============END VECTOR TEST===========" << RESET << std::endl;
	return (0);	
}

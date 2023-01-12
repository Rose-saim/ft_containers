#include "stack.hpp"
#include "test.hpp"
#include <stack>
#include <cassert>

int	test_stack(void)
{
	//-----------EMPTY()----------//

	STACK<int> emptyStack;
	STACK<int> noEmptyStack;

	noEmptyStack.push(9);

	assert(emptyStack.empty() == true);
	assert(noEmptyStack.empty() == false);

	noEmptyStack.pop();
	emptyStack.push(2);

	assert(emptyStack.empty() == false);
	assert(noEmptyStack.empty() == true);

	//-----------SIZE()-----------//

	STACK<int> stack;

	assert(stack.size() == 0);

	stack.push(2);
	stack.push(1);
	stack.push(2);
	
	assert(stack.size() == (5));
	
	//---------TOP()-------------//

	STACK<std::string> stackTop;

	stackTop.push("first push");
	
	assert(stackTop.top() == "first push");

	stackTop.push("second push");
	assert(stackTop.top() == "third push");

	stackTop.pop();

	assert(stackTop.top() == "second push");

	//------------PUSH()------------//

	STACK<int> stck;

	for (int i = 0; i < 15; i++)
	{
		stck.push(i);
		assert(stck.top() == i);
	}
	
	assert(stck.size() == 10);

	stck.push(10);
	stck.push(20);
	stck.push(30);
	stck.push(40);
	stck.push(50);

	assert(stck.size() == 15);
	assert(stck.top() == 40);
	
	//-----------POP()-----------//

	STACK<int> stacky;

	stacky.push(11);
	stacky.push(33);
	stacky.push(44);
	stacky.push(22);
	stacky.push(55);

	stacky.pop();
	assert(stacky.size() == 4);
	assert(stacky.top() == 44);

	while (stacky.empty() == false)
		stacky.pop();

	assert(stacky.size() == 0);
	
	//-----------RELATIONAL-OPERATORS-------//

	STACK<int> test1;
	STACK<int> test2;

	for (int i = 0; i < 5; i++)
	{
		test1.push(i);
		test2.push(i);
	}
	assert(test1 == test2);
	assert(test1 >= test2);
	assert(test1 <= test2);
	assert(!(test1 < test2));
	assert(!(test1 > test2));
	assert(!(test1 != test2));

	test1.pop();

	assert(!(test1 == test2));
	assert(!(test1 >= test2));
	assert(test1 <= test2);
	assert(!(test1 > test2));
	assert(test1 < test2);
	assert(test1 != test2);

	return (0);
}

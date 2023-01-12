#include "test_vector.cpp"
#include "test_stack.cpp"
#include "test_map.cpp"
#include "test.hpp"

int		main(void)
{
	std::ofstream out;
	out.open("log");

	test_stack();
	test_vector(out);
	test_map(out);
	return 0;
}

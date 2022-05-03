#include <iostream>
#include<tuple>

void Test_Tuple() {
	std::tuple<int, int, int> tuple1, tuple2;
	std::tuple<int, int, char> tuple3;
	tuple1 = std::make_tuple(1, 2, 3);
	tuple2 = std::make_tuple(4, 5, 6);

	tuple3 = std::make_tuple(12, 24, 'a');

	int a, b;
	char c;
	std::tie(a, b, c) = tuple3;

	std::cout << "a:" << a << ", b:" << b << ", c:" << c << std::endl;
}
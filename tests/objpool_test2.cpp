#include <iostream>

#include "util/ObjectPool.hpp"
#include "lex/Token.hpp"

#define SIZE 1000000

using namespace std;

int main()
{
	TPJparser::ObjectPool<TPJparser::Token> my_pool;

	for (size_t i = 0 ; i < SIZE; i++) {
		(void) my_pool.getItem();
	}

	if (my_pool.getSize() != SIZE) {
		cerr << "getsize returns something wrong" << endl;
		return 1;
	}


	return 0;
}
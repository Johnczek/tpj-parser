#include <iostream>

#include "util/ObjectPool.hpp"
#include "lex/Token.hpp"

using namespace std;

int main()
{
	TPJparser::ObjectPool<TPJparser::Token> my_pool;

	if (my_pool.getSize() != 0) {
		cerr << "getSize != 0" << endl;
		return 1;
	}

	{
		my_pool.show();
		TPJparser::Token& token1 = my_pool.getItem();
		my_pool.show();
		if (token1.getID() != 0) {
			cerr << "token1 has bad ID after alloc" << endl;
			return 1;
		}

		TPJparser::Token& token2 = my_pool.getItem();
		my_pool.show();
		if (token2.getID() != 1) {
			cerr << "token2 has bad ID after alloc" << endl;
			return 1;
		}

		TPJparser::Token& token3 = my_pool.getItem();
		my_pool.show();
		if (token3.getID() != 2) {
			cerr << "token3 has bad ID after alloc" << endl;
			return 1;
		}

		TPJparser::Token& token4 = my_pool.getItem();
		my_pool.show();
		if (token4.getID() != 3) {
			cerr << "token4 has bad ID after alloc" << endl;
			return 1;
		}

		TPJparser::Token& token5 = my_pool.getItem();
		my_pool.show();
		if (token5.getID() != 4) {
			cerr << "token5 has bad ID after alloc" << endl;
			return 1;
		}

		my_pool.returnItem(token2);
		my_pool.show();
	}

	{
		TPJparser::Token& token2 = my_pool.getItem();
		my_pool.show();

		if (token2.getID() != 1) {
			cerr << "second token has bad ID after reuse" << endl;
			return 1;
		}

		TPJparser::Token& token6 = my_pool.getItem();
		my_pool.show();

		if (token6.getID() != 5) {
			cerr << "sixth token has bad ID after alloc" << endl;
			return 1;
		}

	}



	return 0;
}
#include <iostream>
#include <string>
#include "ObjectPool.h"
using namespace std;

int main() {
	ObjectPool<int> pool(10);
	ObjectPool<string> pool2(2);

	int* a = &pool.Retrieve();
	*a = 7;
	cout << pool;

	int* b = &pool.Retrieve();
	*b = 15;
	cout << pool;

	int* c = &pool.Retrieve();
	*c = 16;
	cout << pool;

	pool.Return(*b);
	cout << pool;

	int* d = &pool.Retrieve();
	*d = 38;
	cout << pool;

	string* e = &pool2.Retrieve();
	*e = "Hello";
	cout << pool2;

	pool2.Return(*e);
	cout << pool2;
}
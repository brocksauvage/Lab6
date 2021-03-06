#ifndef TEST_H
#define TEST_H
#include "LinkedListOfInts.h"
#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

class Test
{
	public:
	Test(LinkedListOfInts test);
	~Test();
	void runTests();
	void verifySize();
	void verifyIsEmpty();
	void verifyAdd();
	void verifyRemove();
	void verifySearch();
	private:
	LinkedListOfInts myList;
	std::string* testResults;
	std::string* testList;

};

#endif

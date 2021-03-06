#include "test.h"

Test::Test(LinkedListOfInts test)
{
	myList = test;
	testResults = new std::string[16];
	testList = new std::string[16];

	testList[0] = "Test 1: Size of empty list is zero: ";
	testList[1] = "Test 2: Size of list is correct after 1 addFront: ";
	testList[2] = "Test 3: Size of list is correct after 1 addBack: ";
	testList[3] = "Test 4: Size of List is correct after 1 removeFront: ";
	testList[4] = "Test 5: Size of list is correct after all nodes removed: ";
	testList[5] = "Test 6: IsEmpty called on an empty list returns true: ";
	testList[6] = "Test 7: IsEmpty called on non-empty list returns false: ";
	testList[7] = "Test 8: IsEmpty called after all nodes deleted returns true: ";
	testList[8] = "Test 9: AddFront correctly adds all nodes: ";
	testList[9] = "Test 10: AddBack correctly adds all nodes: ";
	testList[10] = "Test 11: RemoveFront called on empty list returns false: ";
	testList[11] = "Test 12: RemoveFront is able to remove all nodes from list: ";
	testList[12] = "Test 13: RemoveBack called on empty list returns false: ";
	testList[13] = "Test 14: RemoveBack is able to remove all nodes from list: ";
	testList[14] = "Test 15: Searching a value not in a list returns false: ";
	testList[15] = "Test 16: Searching finds all values in a list: ";
}

Test::~Test()
{
	
}

void Test::runTests()
{
	verifySize();
	verifyIsEmpty();
	verifyAdd();
	verifyRemove();
	verifySearch();

	for(int i = 0; i < 16; i++)
	{
		std::cout << testList[i] + testResults[i] + "\n";
	}
	 
}

void Test::verifySize()
{
	if(myList.size() == 0)
	{
		testResults[0] = "PASSED";
	}
	else
	{
		testResults[0] = "FAILED";
	}
	
	myList.addFront(1);

	if(myList.size() == 1)
	{
		testResults[1] = "PASSED";
	}
	else
	{
		testResults[1] = "FAILED";
	}

	myList.addBack(2);

	if(myList.size() == 2)
	{
		testResults[2] = "PASSED";
	}
	else
	{
		testResults[2] = "FAILED";
	}

	myList.removeFront();

	if(myList.size() == 1)
	{
		testResults[3] = "PASSED";
	}
	else
	{
		testResults[3] = "FAILED";
	}

	myList.removeBack();

	if(myList.size() == 0)
	{
		testResults[4] = "PASSED";
	}
	else
	{
		testResults[4] = "FAILED";
	}
}

void Test::verifyIsEmpty()
{
	if(myList.isEmpty() == true)
	{
		testResults[5] = "PASSED";
	}
	else
	{
		testResults[5] = "FAILED";
	}

	myList.addFront(1);

	if(myList.isEmpty() == false)
	{
		testResults[6] = "PASSED";
	}
	else
	{
		testResults[6] = "FAILED";
	}

	myList.removeFront();

	if(myList.isEmpty() == true)
	{
		testResults[7] = "PASSED";
	}
	else
	{
		testResults[7] = "FAILED";
	}

}

void Test::verifyAdd()
{
	std::vector<int> vectorList;

	for(int i = 0; i < 10; i++)
	{
		myList.addFront(i);	
	}

	vectorList = myList.toVector();
	testResults[8] = "PASSED";

	for(int i = 0; i < 10; i++)
	{
		if(vectorList[i] != 9-i)
		{
			testResults[8] = "FAILED";
		}
		myList.removeFront();
	}

	for(int i = 0; i < 10; i++)
	{
		myList.addBack(i);
	}

	vectorList = myList.toVector();
	testResults[9] = "PASSED";

	for(int i = 0; i < 10; i++)
	{
		if(vectorList[i] != i)
		{
			testResults[9] = "FAILED";
		}
		myList.removeFront();
	}	
}

void Test::verifyRemove()
{
	//Check remove front

	if(myList.removeFront() == false)
	{
		testResults[10] = "PASSED";
	}
	else
	{	
		testResults[10] = "FAILED";
	}

	for(int i = 0; i < 10; i++)
	{
		myList.addFront(i);
	}

	testResults[11] = "PASSED";

	for(int i = 0; i < 10; i++)
	{
		if(myList.removeFront() != true)
		{
			testResults[11] = "FAILED";
		}
	}

	//Check remove back
	if(myList.removeBack() == false)
	{
		testResults[12] = "PASSED";
	}
	else
	{	
		testResults[12] = "FAILED";
	}

	for(int i = 0; i < 10; i++)
	{
		myList.addFront(i);
	}

	testResults[13] = "PASSED";

	for(int i = 0; i < 10; i++)
	{
		if(myList.removeBack() != true)
		{
			testResults[13] = "FAILED";
		}
	}	
}

void Test::verifySearch()
{
	for(int i = 0; i < 100; i++)
	{
		myList.addFront(i);
	}

	if(myList.search(101) == false)
	{
		testResults[14] = "PASSED";
	}
	else
	{
		testResults[14] = "FAILED";
	}
	
	testResults[15] = "PASSED";

	for(int i = 0; i < 100; i++)
	{
		if(myList.search(i) != true)
		{
			testResults[15] = "FAILED";
			return;
		}
		myList.removeBack();
	}
		
}

/**
*	@author 
*	@date 
*	@file main.cpp
*	@brief driver for LinkedList demo
*/
#include <iostream>
#include "LinkedListOfInts.h"
#include "test.h"
#include <fstream>

int main(int argc, char** argv)
{
	//Example of declaring a LinkedListOfInts
	LinkedListOfInts testList;
	Test myTester(testList);
	myTester.runTests();

	std::cout << "Running...\nAnd we're done.\nGoodbye.\n";
	
	ofstream file;
	file.open("buglist.txt");
	file << "Best guesses of possible bugs:\n"
		<< "1. isEmpty() is malfuntioning when list is non-empty\n"
		<< "2. The removal functions are malfuntioning when nodes should be removed\n"
		<< "3. The size of the list is not being maintained correctly";
	file.close();
	return (0);

}


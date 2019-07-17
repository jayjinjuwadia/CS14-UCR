/**
 * UCR CS&E
 * CS014 Lab 1
 * main.cpp
 */

#include <iostream>
#include "List.h"
#include "Iterator.h"
#include "Node.h"

#define fibo_number 11

int fibonacci(int n);

using namespace std;

int main()
{
	/* Instantiate two Lists */
	List myList;
	List myList2;
	
	/* Try to print an empty List */
	cout << "\nTest printing an empty list:";
	myList.print();
	
	cout << "\nPushing back first " << fibo_number << " Fibonacci numbers:";
	for(int i = 0; i < fibo_number; i++)
	{
		myList.push_back(fibonacci(i));
		myList.print();
	}
	
	cout << "\nReverse myList pushing front contents of myList into myList2:";
	for(Iterator iter = myList.begin(); !iter.is_equal(myList.end()); iter.next_pos())
	{
		myList2.push_front(iter.get_value());
		myList2.print();
	}
	myList.sorted_insert(1);
	myList2.sorted_insert(34);
	myList.print();
	myList2.print();
	myList2.print_reverse();
	myList.print_reverse();
	cout << myList.get_size() << endl;
	myList.insert_after(11, 9);
	myList.print();
	myList.insert_after(0, 9);
	myList.print();
	myList.insert_after(5, 9);
	myList.print();
	myList2.insert_before(3, 9);
	myList2.print();
	myList2.insert_before(0, 9);
	myList2.print();
	myList2.insert_before(12, 9);
	myList2.print();
	cout << myList2.count(9) << endl;
	return 0;
}

/**
 * Local Fibonacci function for filling and testing Lists 
 * @param n the Fibonacci number to calculate
 * @return fibonacci(n)
 */
int fibonacci(int n)
{
	if((n == 0) | (n == 1))
	{
		return n;
	}
	else
	{
		return fibonacci(n-2) + fibonacci(n-1);
	}
}

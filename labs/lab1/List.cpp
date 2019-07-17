/**
 * UCR CS&E
 * CS014 Lab 1
 * List.cpp
 */

#include <iostream>
#include <cstdlib>
#include "List.h"
#include "Node.h"
#include "Iterator.h"

using namespace std;

/**
 * Constructor
 */
List::List()
{
	head = NULL;
	tail = NULL;
}

/**
 * Destructor
 */
List::~List()
{
	cout << "\nList Destructor called...\n";
	
	while(head)
	{
		Node* temp = head;
		head = head->get_next();
		cout << "Deleting.... " << temp->get_value() << endl;
		delete temp;
	}	
}

/**
 * push_back() inserts a new node at the tail
 * end of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_back(int value)
{
	Node* new_node = new Node(value);
	
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_prev(tail);
		tail->set_next(new_node);
		tail = new_node;
	}
}
/**
 * push_front() inserts a new node at the 
 * front of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_front(int value)
{
	Node* new_node = new Node(value);
		
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_next(head);
		head->set_prev(new_node);
		head = new_node;			
	}
}

/**
 * print()const prints the contents of 
 * the list to the console, starting
 * at the head of the list
 * @param none
 * @return none
 */
void List::print()const
{
	cout << "\nList contents:\n";

	/* list is empty */
	if(!head)
	{
		cout << "empty\n";
		return;
	}
	
	for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos())
	{
		cout << iter.get_value() << ", ";
	}
	cout << "\n";
}

/**
 * get_head()const returns the head
 * Node pointer which points to the
 * first element in the list
 * @param none
 * @return List's head Node pointer
 */
Node* List::get_head()const
{
	return head;
}

/**
 * get_tail()const  returns the tail
 * Node pointer which points to the
 * last element in the list
 * @param none
 * @return List's tail Node pointer
 */
Node* List::get_tail()const
{
	return tail;
}

/**
 * begin()const gets beginning postion of the list
 * @param none
 * @return an Iterator pointing to the beginning of the list
 */
Iterator List::begin()const
{
	Iterator iter;
	iter.set_curr_pos(get_head());
	iter.set_last_pos(get_tail());
	return iter;
}

/**
 * end()const gets past-the-end postion of the list
 * @param none
 * @return an Iterator pointing just past the end of the list
 */
Iterator List::end()const
{
	Iterator iter;
	iter.set_curr_pos(NULL);
	iter.set_last_pos(get_tail());
	return iter;
}

void List::sorted_insert(int value) {
		if (head == NULL && tail == NULL) {
			Node *l1st = new Node(value);
			head = l1st;
			tail = l1st;
		}
		else if (head != NULL && head->get_next() == NULL) {
			if (head->get_value() >= value) {
				push_back(value);
			}
			else {
				push_front(value);
			}
		}
		else if (tail->get_value() <= value && head->get_value() <= tail->get_value()) {
			push_back(value);
		}  
		else if (head->get_value() <= value && head->get_value() >= tail->get_value()) {
			push_front(value);
		}

		else if (head->get_value() >= tail->get_value()) {
			Node *currpos = head;
			Node *next2	= head->get_next();
			while (next2 != NULL){
				if (next2->get_value() <= value && currpos->get_value() >= value) {
					Node *curr = new Node(value);
					curr->set_next(next2);
					curr->set_prev(currpos);
					currpos->set_next(curr);
					next2->set_prev(curr);
					break;
				}
			else {
				currpos = next2;
				next2 = currpos->get_next();
			}
			}
		}
		else {
			Node *currpos1 = head;
			Node *next1	= head->get_next();
			while (next1 != NULL){
				if (next1->get_value() >= value && currpos1->get_value() <= value) {
					Node *curr1 = new Node(value);
					curr1->set_next(next1);
					curr1->set_prev(currpos1);
					next1->set_prev(curr1);
					currpos1->set_next(curr1);
					break;
				}
			else {
				currpos1 = next1;
				next1 = currpos1->get_next();
			}
			}
		}
		
}

void List::print_reverse() const {
	Iterator itr = end();
	itr.set_curr_pos(tail);
	cout << "List contents:\n";
	while (itr.get_curr_pos() != NULL) {
		cout << itr.get_value() << ", ";
		itr.prev_pos();
	}
	cout << endl;
}
int List::get_size() {
	int count = 0;
	Node *ptr = head;
	while (ptr != NULL) {
		count++;
		ptr = ptr->get_next();
	}
	return count;
}
void List::insert_after(int i, int value) {
	Node *pointr = head;
	int size = get_size();
	if (i < 0 || i > size -1) {
		cout << "Invalid position parameter i";
		return;
	}
	else if (i == size - 1) {
		push_back(value);	
		return;
	}
	for (int counter = 1; counter <= i; counter++) {
		pointr = pointr->get_next();
	}
	Node *newnode = new Node(value);
	newnode->set_next(pointr->get_next());
	newnode->set_prev(pointr);
	pointr->set_next(newnode);
	newnode->get_next()->set_prev(newnode);
}

void List::insert_before(int i, int value) {
	Node *pointr = head;
	int size = get_size();
	if (i < 0 || i > size -1) {
		cout << "Invalid position parameter i";
		return;
	}
	else if (i == 0) {
		push_front(value);	
		return;
	}
	for (int counter = 1; counter <= i; counter++) {
		pointr = pointr->get_next();
	}
	Node *newnode = new Node(value);
	newnode->set_next(pointr);
	newnode->set_prev(pointr->get_prev());
	pointr->get_prev()->set_next(newnode);
	pointr->set_prev(newnode);
}

int List::count(int value)const {
	Node *ptr = head;
	int countr = 0;
	while (ptr != NULL) {
		if (ptr->get_value() == value) {
			countr +=1;
		}
		ptr = ptr->get_next();
	}
	return countr;
}
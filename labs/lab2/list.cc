// CS14
// This file contains all of the functions for the list class

#include "list.h"
#include <cstdlib>
#include <iostream>

using namespace std;

List::List ( ) {
  head = NULL;
}
List &List::operator=(const List &lst) {
if (lst.head == NULL) {
    head = NULL;
  }
  else {
    head = new Node;
    Node *ptr2 = head;
    Node *ptr = lst.head;
    ptr2->value = ptr->value;
    while (ptr->next != NULL) {
    ptr = ptr->next;
    ptr2->next = new Node;
    ptr2 = ptr2->next;
    ptr2->value = ptr->value;
 }
}
return *this;
}
/*List::List(const List &lst) {
  if (lst.head == NULL) {
    head = NULL;
  }
  else {
    head = new Node;
    Node *ptr2 = head;
    Node *ptr = lst.head;
    ptr2->value = ptr->value;
    while (ptr->next != NULL) {
    ptr = ptr->next;
    ptr2->next = new Node;
    ptr2 = ptr2->next;
    ptr2->value = ptr->value;
 }
} 
} */
//------------------------------------------------------------------------

List::~List ( ) {

  // ADD: to avoid memory leaks, make sure you delete all allocated memory
  Node* next;
  for ( Node* temp = head; temp != NULL; temp = next ) {
    next = temp->next;
    delete temp;
  }

}

//------------------------------------------------------------------------

int 
List::size ( ) {
  int size = 0;
  for ( Node* temp = head; temp != NULL; temp = temp->next ) {
    size ++;
  }
  return size;
}

//------------------------------------------------------------------------

void 
List::push_front ( int value ) {

  Node* insert = new Node;
  insert->value = value;
  insert->next = head;
  head = insert;

}

//------------------------------------------------------------------------

void
List::push_back ( int value ) {

  if ( size ( ) == 0 ) {
    push_front ( value );
  }
  else {
    Node* tail;
    for ( tail = head; tail->next != NULL; tail = tail->next );
    Node* insert = new Node;
    insert->value = value;
    insert->next = NULL;
    tail->next = insert;
  }

}

//------------------------------------------------------------------------

void 
List::print ( ) {

  if ( size ( ) == 0 ) {
    cout << "No elements in the array" << endl;
    return;
  }

  for ( Node* temp = head; temp != NULL; temp = temp->next ) {
    cout << temp->value << " ";
  }
  cout << endl;
}

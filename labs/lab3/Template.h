
#include <iostream>
#include <stdexcept>

using namespace std;
template<typename T>
class Stack {
    public: 
        Stack();
        ~Stack();
        void push(const T& x);
        void pop();
        T& top();
        bool is_empty() const;
    private:
        struct Node {
        Node* next;
        T data; 
        };
        Node *head;
        Node *tail;
        int size;
};
template<typename T>
Stack<T>::Stack() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template<typename T>
Stack<T>::~Stack() {
    cout << "Destructor called.\n";
    Node *temp;
    Node *ptr;
    for ( temp = head; temp != NULL; temp = temp->next) {
        ptr = temp->next;
        delete temp;
        temp = ptr;
    }
    head = NULL;
    tail = NULL;
    size = 0;
}
template<typename T>
void Stack<T>::push(const T& x) {
    if (head == NULL && tail == NULL) {
         Node *ptr = new Node;
        ptr->data = x;
        ptr->next = head;
        head = ptr;
        tail = ptr;
        size++;
    }
    else {
    Node *ptr = new Node;
    ptr->data = x;
    ptr->next = head;
    head = ptr;
    size++;
    }
}
template<typename T>
void Stack<T>::pop() {
    if (head == NULL) {
        throw std::underflow_error("Stack Underflow\n");
    }
    else if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        size--;
    }
    else {
        Node *temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
        size--;
    }
}

template<typename T>
T& Stack<T>::top() {
    if (head == NULL) {
        throw std::underflow_error("Stack Underflow\n");
    }
    else {
    return head->data;
    }
}

template<typename T>
bool Stack<T>::is_empty() const {
    if (size == 0) {
        return true;
    }
    else {
        return false;
    }
}


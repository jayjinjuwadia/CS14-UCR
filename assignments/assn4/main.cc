/**
 * Course: CS014 Summer 2018
 *
 * First Name: Jay
 * Last Name: Jinjuwadia
 * Username: jjinj001
 * email address: jjinj001@ucr.edu
 *
 *
 * Assignment: assn4
 * Filename : main.cc;
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
#include "pq_zero.h"
#include "pq_one.h"
#include <iostream>
#include <string>

int main() {
    pq_zero<int> p;
    cout << "EMPTY TEST1:\n";
    if (p.empty()) {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }
    p.push(1, 1);
    cout << p.top() << endl;
    cout << "EMPTY TEST2:\n";
    if (!p.empty()) {
        cout << "PASSED\n";
    }
    else {
        cout << "FAILED\n";
    }
    p.push(4, 1);
    p.display();
    cout << p.top() << endl;
    p.push(2 , 1);
    p. display();
    cout << p.top() << endl;
    p.push(0, 1);
    cout << p.top() << endl;
    p.display();
    p.push(0, 2);
    p. display();
    p.push(0, 1);
    p. display();
    p.push(5, 1);
    p. display();
    p.push(4, 2);
    p. display();
    p.push(5, 2);
    p.display();
    p.push(10, 1);
    p. display();
    p.push(3, 1);
    p.display();
    p.push(20, 1);
    p. display();
    p.push(17, 1);
    p. display();
    p.push(30, 1);
    p. display();
    p.push(41, 1);
    p.display();
    p.push(3,2);
    p.display();
    p.push(6,1);
    p.display();
    p.push(4,1);
    p.display();
    p.push(2,1);
    p.display();
    
    vector<int> a;
    vector<float> b;
    a.push_back(1);
    a.push_back(9);
    a.push_back(2);
    a.push_back(3);
    a.push_back(1);
    a.push_back(2);
    a.push_back(10);
    a.push_back(8);
    a.push_back(7);
    a.push_back(5);
    a.push_back(13);
    a.push_back(70);
    a.push_back(25);
    a.push_back(20);
    a.push_back(4);
    for (unsigned i = 0; i < a.size();i++) {
        b.push_back(1);
    }
    pq_zero<int> l(a,b);
    l.display();
    pq_one<int> z;
    z.push(1, 1);
    z.push(4, 1);
    z.display();
    cout << z.top() << endl;
    z.push(2 , 1);
    z. display();
    cout << z.top() << endl;
    z.push(0, 1);
    cout << z.top() << endl;
    z.display();
    z.push(0, 2);
    z. display();
    z.push(0, 1);
    z. display();
    z.push(5, 1);
    z. display();
    z.push(4, 2);
    z. display();
    z.push(5, 2);
    z.display();
    z.push(10, 1);
    z. display();
    z.push(3, 1);
    z.display();
    z.push(20, 1);
    z. display();
    z.push(17, 1);
    z. display();
    z.push(30, 1);
    z. display();
    z.push(41, 1);
    z.display();
    z.push(3,2);
    z.display();
    z.push(6,1);
    z.display();
    z.push(4,1);
    z.display();
    z.push(2,1);
    z.display();
    pq_one<int> x(a,b);
    x.display();
    
    pq_zero<char> y;
    y.push('a',1);
    y.push('s',1);
    y.push('o',1);
    y.push('l',1);
    y.push('q',1);
    y.push('w',1);
    y.push('e',1);
    y.push('v',1);
    y.push('b',1);
    y.push('v',1);
    y.push('m',1);
    y.push('d',1);
    y.push('j',1);
    y.display();
    
    pq_one<char> w;
    w.push('a',1);
    w.push('s',1);
    w.push('o',1);
    w.push('l',1);
    w.push('q',1);
    w.push('w',1);
    w.push('e',1);
    w.push('v',1);
    w.push('b',1);
    w.push('v',1);
    w.push('m',1);
    w.push('d',1);
    w.push('j',1);
    w.display();
    
    pq_zero<string> r;
    r.push("Mary",1);
    r.push("John",1);
    r.push("Jude",1);
    r.push("Paul",1);
    r.push("Isaiah",1);
    r.push("Ryan",1);
    r.push("Johnny",1);
    r.push("Bert",1);
    r.push("Bob",1);
    r.push("Sarah",1);
    r.push("Terry",1);
    r.push("Sean",1);
    r.push("Robert",1);
    r.display();
    r.pop();
    r.display();
    pq_one<float> g;
    for (unsigned d = 0; d < 15;d++) {
        g.push(0.3,1);
    }
    g.display();
    return 0;
}
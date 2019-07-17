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
 * Filename : pq_one.h;
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#ifndef _PQ_ONE_H_
#define _PQ_ONE_H_
#include <vector>
#include <map>
#include <iostream>

using namespace std;
template< class Item >
class pq_one {
private:

void build_heap(vector<Item> &v1,vector<float> &v2 ,int n ) {
    int i = 0;
    for (int k = 0; k < v1.size(); k++) {
        priority[v1.at(k)] = v2.at(k);
        index[v1.at(k)] = k;
    }
    for (int m = 0; m < v1.size(); m++) {
        heap.push_back(v1.at(m));
    }
    for (int f = 1; f < heap.size() - 1; f++) {
        if (heap.at(heap.size()-1) == heap.at(i)) {
           if (priority[heap.at(heap.size()-1)] < priority[heap.at(i)]) {
               float t = priority[heap.at(i)];
               priority[heap.at(i)] = priority[heap.at(heap.size()-1)];
               priority[heap.at(heap.size()-1)] = t; 
           } 
           else if (priority[heap.at(heap.size()-1)] == priority[heap.at(i)]) {
               priority[heap.at(heap.size()-1)] +=1;
           }
        }
    }
    for (i = (n)/2; i >= 1; i--) {
        percolate_down(i);
    }
  


}


vector<Item> heap; // The heap expands/shrinks to fit data
typedef int indx; // index with heap
map<Item,indx> index; // records each Item’s place in heap
map<Item,float> priority; // records each Item’s priority
void percolate_up( indx i ) {
    if (i > 1) {
    Item temp = heap.at(i);
    int parent = (i)/2;
    if (temp < heap.at(parent)) {
        heap.at(i) = heap.at(parent);
        index[heap.at(i)] = parent;
        heap.at(parent) = temp;
       index[heap.at(parent)] = i;
       percolate_up(parent);
    }
    else if (temp == heap.at(parent)) {
        if (priority[heap.at(i)] < priority[heap.at(parent)]) {
             heap.at(i) = heap.at(parent);
            index[heap.at(i)] = parent;
             heap.at(parent) = temp;
            index[heap.at(parent)] = i;
        }
    
    }
    }
}
void percolate_down( indx i ) {
    if ((2*i + 1) < heap.size()) {
        Item temp = heap.at(i); 
        int child1 = 2*i;
        int child2 = 2*i + 1;
        if (heap.at(child1) <= heap.at(child2)) {
            if (heap.at(i) > heap.at(child1)) {
            heap.at(i) = heap.at(child1);
            index[heap.at(i)] = child1;
            heap.at(child1) = temp;
            index[heap.at(child1)] = i;
            percolate_down(child1);
            }
            else if (heap.at(i) == heap.at(child1)) {
            if (priority[heap.at(i)] > priority[heap.at(child1)]) {
             heap.at(i) = heap.at(child1);
            index[heap.at(i)] = child1;
             heap.at(child1) = temp;
            index[heap.at(child1)] = i;
            }
            }
            else {
                return;
            }
        }
        else {
            if (heap.at(i) > heap.at(child2)) {
            heap.at(i) = heap.at(child2);
            index[heap.at(i)] = child2;
            heap.at(child2) = temp;
            index[heap.at(child2)] = i;
            percolate_down(child2);
            }
            else if (heap.at(i) == heap.at(child2)) {
                if (priority[heap.at(i)] > priority[heap.at(child2)]) {
             heap.at(i) = heap.at(child2);
            index[heap.at(i)] = child2;
             heap.at(child2) = temp;
            index[heap.at(child2)] = i;
            }
            }
            else {
                return;
            }
        }
    }
}
public:
// These use the min-heap functions above.
pq_one() {
    Item dummy;
    priority[dummy] = 0;
    index[dummy]= 0;
    heap.push_back(dummy);
}
pq_one(Item t) {
    Item dummy;
    priority[dummy] = 0;
    index[dummy]= 0;
    heap.push_back(dummy);
    heap.push_back(t);
    index[heap.at(heap.size() -1)] = 1;
    priority[heap.at(heap.size()-1)] = 1;
    
}

pq_one(vector<Item> &v1, vector<float> &v2) {
    if (v1.size() != v2.size()) {
        cout << "Item to priority mismatch, enter valid vector fields\n";
        return;
    }
    Item dummy;
    priority[dummy] = 0;
    index[dummy]= 0;
    heap.push_back(dummy);
    build_heap(v1,v2, v2.size()-1);
}
int size( ) const {
    return heap.size();
}
bool empty( ) const {
   return heap.empty();
}
const Item& top( ) const {
    return heap.at(1);
}
void pop( ) {
    heap.pop_back();
}
void push( const Item& w, float prio ) {
    heap.push_back(w);
    priority[heap.at(heap.size() - 1)] = prio;
    index[heap.at(heap.size()-1)] = heap.size() - 1;
    for (int i = 1; i < heap.size() - 1; i++) {
        if (heap.at(heap.size()-1) == heap.at(i)) {
           if (priority[heap.at(heap.size()-1)] < priority[heap.at(i)]) {
               float t = priority[heap.at(i)];
               priority[heap.at(i)] = priority[heap.at(heap.size()-1)];
               priority[heap.at(heap.size()-1)] = t; 
           } 
           else if (priority[heap.at(heap.size()-1)] == priority[heap.at(i)]) {
               priority[heap.at(heap.size()-1)] +=1;
           }
        }
    }
    percolate_up(heap.size()-1);
    int s = index[w];
    percolate_down(s);

}
void display () {
    for (int i = 1; i < heap.size(); i++) {
        cout << heap.at(i) << " ";
    }
    cout << endl;
    cout << priority[heap.at(size() -1)] << endl;
}

};

#endif
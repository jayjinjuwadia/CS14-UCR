#ifndef _JUG_H_
#define _JUG_H_
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <cstdio>
#include <queue>
#include <list>
#include <map>
#include <cstdlib>
#include <fstream>
using namespace std;
struct J {
int A,B;
int dist;
bool visited;
J() {A = 0; B = 0; visited = false;}
J(int c, int d) {
    A = c;
    B = d;
}
bool operator < (const J& j) const {
        if (A != j.A) {
            return A < j.A;
        }
        return B < j.B;
}
bool operator ==(const J&j) const {
    if (A == j.A && B == j.B) {
        return true;
    }
    return false;
}
vector<J> neighbors;
};
class Jug
{
public:
int Ca;
int Cb;
int N;
private:
int fA;
int fB;
int eA;
int eB;
int pAB;
int pBA;
public:
list <pair <J, int> > path;
map <J, pair <J, int> > parent;
Jug(int Ca,int Cb,int N,int fA,int fB,int eA,int eB,int pAB, int pBA) {
    this->Ca = Ca;
    this->Cb = Cb;
    this->N = N;
    this->fA = fA;
    this->fB = fB;
    this->eA = eA;
    this->eB = eB;
    this->pAB = pAB;
    this->pBA = pBA;

}

// Solve() is used to check the input and find the solution if one exists
// returns -1 if the input is invalid.
// returns 0 if input is valid but a solution does not exist.
// returns 1 if solution is found and also prints solution
int Solve() {
    assert (Ca > 0 && Ca <= Cb);
    assert (N <= Cb && Cb <= 1000);
    J start(0,0);
    bfs(start);
    if (path.empty()) {
        return 0;
    }
    else if (path.front().first.A == -1 || path.front().first.B == -1) {
        return 0;
    }
   
        else    {
        int i = path.size()-1;
        while (!path.empty())   {
            J back = path.back().first;
            int i = path.back().second;
            path.pop_back();

            switch (i)   {
                case 0: printf("(%d, %d)\n", back.A, back.B);
                        break;
                case 1: printf("(%d, %d)\nFill jug A\n", back.A, back.B);
                        break;
                case 2: printf("(%d, %d)\nFill jug B\n", back.A, back.B);
                        break;
                case 3: printf("(%d, %d)\nEmpty jug A\n", back.A, back.B);
                        break;
                case 4: printf("(%d, %d)\nEmpty jug B\n", back.A, back.B);
                        break;
                case 5: printf("(%d, %d)\nPour from B into A\n", back.A, back.B);
                        break;
                case 6: printf("(%d, %d)\nPour from A into B\n", back.A, back.B);
                        break;
            }
        }
        printf("Sucess : %d\n", i);
        return 1;
    }
    
} 
void bfs(J start)   {
    
    queue <J> q;
    J goal(-1,-1);

    q.push(start);
    parent.insert(pair < J, pair <J, int> >(start, make_pair(start, 0)));

    while (!q.empty())    {
        J front = q.front();
        q.pop();
        if (front.A == 0 && front.B == N) {
            goal = front;
            break;
        }
        
        if (front.B < Cb)  {
            J child(front.A,Cb);
            if (parent.find(child) == parent.end()) {
                q.push(child);
                parent.insert(pair < J, pair <J, int> >(child, make_pair(front, 2)));
            }
        }
        
        if (front.A < Ca)  {
            J child(Ca, front.B);
            if (parent.find(child) == parent.end()) {
                q.push(child);
                parent.insert(pair < J, pair <J, int> >(child, make_pair(front, 1)));
            }
        }
        
        if (front.B > 0)  {
            J child(front.A,0);
            if (parent.find(child) == parent.end()) {
                q.push(child);
                parent.insert(pair < J, pair <J, int> >(child, make_pair(front, 4)));
            }
        }
        
        if (front.A > 0)  {
            J child(0, front.B);
            if (parent.find(child) == parent.end()) {
                q.push(child);
                parent.insert(pair < J, pair <J, int> >(child ,make_pair(front, 3)));
            }
        }

        if (front.B > 0)  {
            J child(min(front.A + front.B, Ca),max(0, front.A + front.B - Ca));
            if (parent.find(child) == parent.end()) {
                q.push(child);
                parent.insert(pair < J, pair <J, int> >(child, make_pair(front, 5)));
            }
        }

        if (front.A > 0)  {
            J child(max(0, front.A + front.B - Cb), min(front.A + front.B, Cb)); 
            if (parent.find(child) == parent.end()) {
                q.push(child);
                parent.insert(pair < J, pair <J, int> >(child, make_pair(front, 6)));
            }
        }
    }

    if (goal.A == -1 || goal.B == -1) {
        cout << "No solution found\n";
        return;
    }

    path.push_back(make_pair(goal, 0));
    while (parent[path.back().first].second != 0) {
        path.push_back(parent[path.back().first]);
    }
}

};

#endif
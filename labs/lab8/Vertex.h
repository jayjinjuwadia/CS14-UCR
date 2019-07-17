#ifndef _VERTEX_H_
#define _VERTEX_H_
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class Vertex {
    public:
    string label;
    int distance;
    vector<int> neighbors;
    Vertex() {
        distance = 0;
    }
    Vertex(int i, string str) {
        distance = i;
        label = str;
    }
    void addNeighbor(int i) {
        neighbors.push_back(i);
    }
};
#endif
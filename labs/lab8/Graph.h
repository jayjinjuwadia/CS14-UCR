#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "Vertex.h"
#include <iostream>
#include <list>
#include <cstdlib>
#include <cstdio>
#include <map>
class Graph {
    public:
    vector<Vertex> vertices;
    map<string, int> index;
    Graph(ifstream & ifs) {
        build_graph(ifs);
    }
    void build_graph(ifstream &ifs) {
        int nodemax = 0;
        int edgemax = 0;
        string vertexname;
        Vertex *v;
        ifs >> nodemax;
        ifs >> edgemax;
        map<string,int>::iterator it = index.begin();
        for (int i = 0; i < nodemax;i++ ) {
            ifs >> vertexname;
            v = new Vertex(0,vertexname);
            vertices.push_back(*v);
            index.insert(it,pair<string,int> (vertexname,i));
            it++;
        }
        int y = 0;
        int z = 0;
        string parent;
        string child;
        for (int j = 0; j < edgemax; j++) {
            ifs >> parent >> child;
            y = index.at(parent);
            z = index.at(child);
            vertices.at(y).addNeighbor(z);
        }

    }


    void builder_pro() {
        ofstream ofs;
        string filename;
        cout << "Enter output file name:\n";
        cin >> filename;
        ofs.open(filename.c_str());
        if (!ofs.is_open()) {
            cout << "Error opening output file.\n";
            exit(1);
        }
        char fag = 'a';
        ofs << "digraph G {\n";
        int c = 0;
        for (unsigned i = 0; i < vertices.size(); i++) {
            ofs << static_cast<char>((fag + i)) << "[color = lightblue, style = filled, label=" << vertices.at(i).label << vertices.at(i).distance <<"];\n";
           for (unsigned f = 0; f < vertices.at(i).neighbors.size(); f++) {
        
               c =vertices.at(i).neighbors.at(f);
    
               ofs << static_cast<char>((fag + i)) << "->" << static_cast<char>((fag + c)) << ";\n";
           }
        }
        ofs << "}\n";
        ofs.close();
    }
    void bfs () {
        for (unsigned i = 0; i < vertices.size(); i++) {
            vertices.at(i).distance = bfs(i);
        }
    }
    int bfs(int s) {
    if (s == 0) {
        return 0;
    }
    for (unsigned t = 0; t < vertices.at(0).neighbors.size();t++)    {
        if (s == vertices.at(0).neighbors.at(t)) {
            return 1;
        }
    }
    int count = 0;
    bool *visited = new bool[vertices.size()];
    for(unsigned i = 0; i < vertices.size(); i++)
        visited[i] = false;
 
    list<int> queue;
    bool breaker = false;
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    
   list<int> counts;
    while(!queue.empty())
    {
       
        count = 0;
        s = queue.front();
        queue.pop_front();
      
        for (unsigned it = 0; it < vertices.at(s).neighbors.size(); ++it)
        {
            count++;
            if (vertices.at(s).neighbors.at(it) == 0) {
                counts.push_back(count);
                breaker = true;
                break;
                
            }
            else if (!visited[vertices.at(s).neighbors.at(it)])
            {
                visited[vertices.at(s).neighbors.at(it)] = true;
                queue.push_back(vertices.at(s).neighbors.at(it));
            }
        }
        if (breaker == true) {
            break;
        }
        counts.push_back(count);
    }
    if (s == 0) {
    return counts.size();
    }
    else {
        return -1;
    }
}
    
};
#endif

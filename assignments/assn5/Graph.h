#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "Jug.h"

class Graph {
    public:
    map<J, bool> visit;
    vector<J> vertexlist;
    Graph(Jug J) {
        build_graph(J.Ca, J.Cb);
        builder_pro();
        J.Solve();
    }
   void build_graph(int Ca, int Cb) {
       J start(0,0);
       queue<J> q;
       q.push(start);
       while (!q.empty()) {
           
           visit.insert(make_pair(q.front(), true));
           vertexlist.push_back(q.front());
           if (q.front().A < Ca) {
               J child;
               child.A = Ca;
               child.B = q.front().B;
               vertexlist.at(vertexlist.size() - 1).neighbors.push_back(child);
               if (visit.find(child) == visit.end()) {
               q.push(child);
               }
           }
           if (q.front().B < Cb) {
               J child2;
               child2.B = Cb;
               child2.A = q.front().A;
               vertexlist.at(vertexlist.size() - 1).neighbors.push_back(child2);
               if (visit.find(child2) == visit.end()) {
               q.push(child2);
               }
           }
           if (q.front().A > 0) {
               J child3;
               child3.A = 0;
               child3.B = q.front().B;
               if (!(child3 == start)) {
               vertexlist.at(vertexlist.size() - 1).neighbors.push_back(child3);
               }
               if (visit.find(child3) == visit.end()) {
               q.push(child3);
               }
           }
          if (q.front().B > 0) {
               J child4;
               child4.A = q.front().A;
               child4.B = 0;
               if (!(child4 == start)) {
               vertexlist.at(vertexlist.size() - 1).neighbors.push_back(child4);
               }
               if (visit.find(child4) == visit.end()) {
               q.push(child4);
               }
           }
          if (q.front().A > 0 && q.front().B < Cb) {
              J child5;
              child5.A = q.front().A - (Cb - q.front().B);
              child5.B = q.front().A + q.front().B;
              if (child5.A < 0) {
                  child5.A = 0;
              }
              if (child5.B > Cb) {
                  child5.B = Cb;
              }
              if (!(child5 == start)) {
              vertexlist.at(vertexlist.size() - 1).neighbors.push_back(child5);
              }
              if (visit.find(child5) == visit.end()) {
               q.push(child5);
               }
          }

          if (q.front().A < Ca && q.front().B > 0) {
              J child6;
              child6.B = q.front().B - (Ca - q.front().A);
              child6.A = q.front().A + q.front().B;
              if (child6.A > Ca) {
                  child6.A = Ca;
              }
              if (child6.B < 0) {
                  child6.B = 0;
              }
              if (!(child6 == start)) {
              vertexlist.at(vertexlist.size() - 1).neighbors.push_back(child6);
              }
              if (visit.find(child6) == visit.end()) {
               q.push(child6);
               }
          }
          q.pop();
           }
          
       }
     void builder_pro() {
        ofstream ofs;
        string filename = "output.txt";
        ofs.open(filename.c_str());
        if (!ofs.is_open()) {
            cout << "Error opening output file.\n";
            exit(1);
        }
        ofs << "digraph G {\n rankdir = LR \n";
        for (unsigned i = 0; i < vertexlist.size(); i++) {
            for (unsigned j = 0; j < vertexlist.at(i).neighbors.size(); j++) {
           ofs << "\"(" << vertexlist.at(i).A << "," << vertexlist.at(i).B << ")\"" << "->" <<  "\"(" <<vertexlist.at(i).neighbors.at(j).A << "," <<vertexlist.at(i).neighbors.at(j).B << ")\""  << "[ label =  \"\" , color =  burlywood4 ];\n";
        }
        }
        ofs << "}\n";
        ofs.close();
     }
};
#endif
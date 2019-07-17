/*
 * cs014_16sum1 
 * lab3
 * main.cc for BST
 */

#include "BST.H"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
  
  if(argc != 2) {
    cerr << "Usage error: expected <executable> <mode>" << endl;
    exit(1);
  }
  
  string cmd = "";
  int key = -1;
  BST t;
  string mode = argv[1];
  
  // ofstream you will use to write to file output.dot
  // currently an empty output.dot gets written into pwd
 /* ofstream ofs("output.dot");
  if(!ofs) {
    cout << "output.dot could not be opened." << endl;
    exit(1);
  } */
  for(;;) {
    cin >> cmd;
    if(cmd == "insert") {
      cin >> key;
      t.insert(key);
    }
    else if(cmd == "remove") {
      cin >> key;
      t.remove(key);
    }
    /*else if (cmd == "traversal") {
      t.traversal();
      t.printl();
    }*/
    else if(cmd == "dotty") {
      t.dotty();
     //remove once mode used in program
      // implement code here that will produce the correct dot file
      // based on the user's preference (mode), i.e., preorder, postorder,
      // inorder, node height
      /* ofstream ofs;
      ofs.open("dotty.dot");
      if (!ofs.is_open()) {
        cout << "Error opening file\n";
        exit(1);
      }
      BinaryNode * ptr = t.getroot();
      if (ptr == NULL) {
        
      }
      else {
        ofs << "digraph G{\n" << "a [color = lightblue, style = filled, label=\"key=\"" << ptr->value << "];";
      
      }
      ofs.close(); */
    }
    else if(cmd == "display") t.display();
    else if(cmd == "end") break;
    else
      cout << cmd << ", not found, try again." << endl;
  }
  
  cout << "Good bye!" << endl;
  return 0;
}

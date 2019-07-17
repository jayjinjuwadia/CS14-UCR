#ifndef __NODE_H
#define __NODE_H

#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

class Node {

private:
  string str;
  int count;
  int depth;
public:
  Node* left;
  Node* right;
  string getStr() {
    return str;
  }
  int getDepth() {
    return depth;
  }

  int getCount() {
    return count;
  }
  void depthUp() {
    depth++;
  }
  void countup() {
    count++;
  }
  void depthDown() {
    depth--;
  }
public:
  Node ( string s ) { left = right = NULL; count = 1; str = s; depth = 0; };
  Node ( ) { left = right = NULL; count = 0; depth = 0;};
  ~Node ( ) {
  }
   Node* insert(string str, Node* t) {
    if (t == NULL) {
      t = new Node(str);
    }
    else if (str == t->str)  {
      t->countup();
    }
    else if (t->str.compare(str) > 0) {
      t->left = insert(str, t->left);
      t->depthUp();
    }
    else if (t->str.compare(str) < 0) {

      t->right = insert(str, t->right);
      t->depthUp();
    }
    else {t->str = str;}
    return t;
  }
  
   bool search(Node*t, string str) {
    if (t == NULL) {
      return false;
    }
    else if (t->str.compare(str) > 0) {
      return search(t->left, str);
    }
    else if (t->str.compare(str) < 0) {
      return search(t->right, str);
    }
    else {
      return true;
    }
  }


 int depthSearch(Node *t, string str) {
   if (t->str.compare(str) > 0) {
      return depthSearch(t->left, str);
    }
    else if (t->str.compare(str) < 0) {
      return depthSearch(t->right, str);
    }
    else {
      return t->getDepth();
    }
}
Node * find_min(Node *t) {
  if (t == NULL) {
    return NULL;
  }
  if (t->left == NULL) {
    return t;
  }
  return find_min(t->left);
}
  
 Node* remove(string str, Node* t) {
   if (t) {
     if (t->str.compare(str) < 0) {
     t->left = remove(str, t->left);
   }
   else if (t->str.compare(str) > 0) {
     t->right = remove(str, t->right);
   }
   else if(t->left != NULL && t->right != NULL && str == t->str) {
     t->str = this->Node::find_min(t->right)->str;
     t->right = remove(t->str, t->right);
   }
   else {
     Node * oldNode = t;
     t = (t->left != NULL) ? t->left
      : t->right;
      delete oldNode;
   }
 }
 else {
   cout << "value not found\n";
 }
 return t;
 }
  // Add any additional variables/functions here

};

#endif
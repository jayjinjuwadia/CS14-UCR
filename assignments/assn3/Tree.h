#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

using namespace std;

class Tree {

private:
  Node *root;
 
  
private:
  void postOrder(Node *t) {
    if (t == NULL) {
      return;
    }
    postOrder(t->left);
    postOrder(t->right);
    cout << t->getStr() << "(" << t->getCount() << ")" << " ";
  }
  void preOrder( Node * t) {
    if (t == NULL) {
      return;
    }
    cout << t->getStr() << "(" << t->getCount() << ")" << " ";
    preOrder(t->left);
    preOrder(t->right);
  }
  void inOrder(Node *t) {
    if (t == NULL) {
        return;
    }
    inOrder(t->left);
    cout << t->getStr() << "(" << t->getCount() << ")" << " ";
    inOrder(t->right);
  }
   Node* find_min(Node *t) {
    if (t == NULL) {
      return NULL;
    }
    if (t->left == NULL) {
      return t;
    }
    return find_min(t->left);
  }
   Node* find_max(Node *t) {
    if (t == NULL) {
      return NULL;
    }
    if (t->right == NULL) {
      return t;
    }
    return find_max(t->right);
  }
  
public:
  void insert( const string & str) {
    root = root->Node::insert(str,root);
  }
  bool search( const string & str) {
     return root->Node::search(root, str);
  }
  int depthSearch(const string&str) {
    return root->Node::depthSearch(root,str);
  }
  void inOrder( ) {
    inOrder(root);
    cout << endl;
  }
  void postOrder( ) {
    postOrder(root);
    cout << endl;
  }
  void preOrder( ) {
    preOrder(root);
    cout << endl;
  }
  string largest( ) {
    Node* t = find_max(root);
    return t->getStr();
  }
  string smallest( ) {
    Node *t = find_min(root);
    return t->getStr();
  }
  int height( const string & str) {
    if (!search(str)) {
      return -1;
    }
    else {
      return depthSearch(str);
    }
  }
  void remove( const string & str) {
    root = root->Node::remove(str,root);
  }
  Tree() {
    root = NULL;
  }
  Tree(const string &str) {
    root = new Node(str);
  }
  // Add any additional variables/functions here
  void printTreeSideways() {printTreeSideways(root);}
  void printTreeSideways(Node*t) {
    static int depth = 0;
    depth++;
    if (t == NULL) {
      return;
    }
    if (t->right != NULL) {
       printTreeSideways(t->right);
    }
    for (int i = 0; i != depth; i++) {
      cout << " ";
    }
    cout << t->getStr() << "(" << t->getCount() << ")\n" << endl;
    if (t->left != NULL) {
      printTreeSideways(t->left);
    }
      depth--;
      
  }
};

#endif
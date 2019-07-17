/*
 * cs014_16sum1
 * lab 3
 * BST.H
 */

#ifndef BST_H_
#define BST_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>
#include <list>

using namespace std;

class BST {

private:
  struct BinaryNode {

    int value;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode(int& v) : value(v), left(NULL), right(NULL) {}
    static BinaryNode* insert(int v, BinaryNode* t) {
      if(t == NULL){
	t = new BinaryNode(v);
      }
      else if (v == t->value) {
  cout << "Error: value already in tree\n";
      }
      else if (v < t->value)
	t->left = insert(v, t->left);
      else if (v > t->value)
	t->right = insert(v, t->right);
      else
	t->value = v;
      return t;
    }

    static BinaryNode* remove(int v, BinaryNode* t) {
      
      if(t) {
	 if(v < t->value)
	  t->left = remove(v, t->left);
	else if(t->value < v)
	  t->right = remove(v, t->right);
	else if(t->left != NULL && t->right != NULL && v == t->value) {
	  t->value = find_min(t->right)->value;
	  t->right = remove(t->value, t->right);
	}
	else {
	  BinaryNode* oldNode = t;
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
    
    static BinaryNode* find_min(BinaryNode* t) {
     if(t == NULL)
	return NULL;
      if(t->left == NULL)
	return t;
      return find_min(t->left);
    }
  };

public:
  BST(): root(NULL) {}
  ~BST() {}
 /* void traversal() {traversal(root); }
  void traversal(BinaryNode* t) {
    
     static int depth = 0;
    ++ depth;
    if ( t == NULL ) return;
    if ( t->right != NULL ) traversal(t->right);
    l.push(t->value);
    if ( t->left != NULL )
      traversal(t->left);
    --depth;
  }
  void printl () {
    lsize = 0;
    while (!l.empty()) {
      cout << l.front() << " ";
      lsize++;
      l.pop();
    }
    cout << endl;
    cout << lsize << endl;
  }*/
   void dotty() {
    string mode;
    cin >> mode;
    
    if (mode == "inorder") {
     
      ofs.open("inorder_color.dot");
      if (!ofs.is_open()) {
        cout << "Error opening file\n";
        exit(1);
      }
      
      ofs << "digraph G {\n";
      size = 0;
      inord = 1;   
      inorder(root);
    
     /* int height = 0;
      int inord2 = inord;
      while (inord2 != 1) {
        inord2 /= 2;
        height++;
      } 
    
      cout << height << endl;
      if (height == 1) {
        int j = size / 2;
        int dep2= inord/height;
        ofs << alpha[j] << "->" << alpha[j-dep2] << ";\n";
        ofs << alpha[j] << "->" << alpha[j+dep2] << ";\n";
      }
      if (height == 2) {
      int dep = inord / height;
      int i = size/2;
      while(dep != 0) {
        ofs << alpha[i] << "->" << alpha[i-dep] << ";\n";
        ofs << alpha[i] << "->" << alpha[i+dep] << ";\n";
        i -= dep;
        dep /=2;
        }
    
     dep = inord / height;
      i = size/2;
      i += dep;
      dep /=2;
      while(dep != 0) {
        ofs << alpha[i] << "->" << alpha[i-dep] << ";\n";
        ofs << alpha[i] << "->" << alpha[i+dep] << ";\n";
        i += dep;
        dep /= 2;
      }
      }
    }*/
      ofs << "}\n";
      ofs.close();
    }
    else if (mode == "preorder") {
       ofs.open("preorder_color.dot");
      if (!ofs.is_open()) {
        cout << "Error opening file\n";
        exit(1);
      }
      
      ofs << "digraph G {\n";
      preorder(root);
       ofs << "}\n";
      ofs.close();
    }
    else if (mode == "postorder") {
       ofs.open("postorder_color.dot");
      if (!ofs.is_open()) {
        cout << "Error opening file\n";
        exit(1);
      }
      ofs << "digraph G {\n";
      postorder(root);
       ofs << "}\n";
      ofs.close();
    }
    else {
      cout << "Invalid mode\n";
    }
    }
  
    /*
    int inord = 1;
    ofs << "digraph G {\n";
    BinaryNode* t = root;
    BinaryNode *r = root;
    if (t == NULL) {
      return;
    }
    else {
     
      ofs << alpha[size] << " [color = lightblue, style = filled, label=\"key=" << t->value << ", in=" << inord << "\"];\n";
      inord++;
      size++;
      while (t != NULL) {
      if (t->left != NULL) {
        ofs << alpha[size] << " [color = lightblue, style = filled, label=\"key=" << t->left->value << ", in=" << inord << "\"];\n";
        size++;
      }
      if (t->right != NULL) {
        ofs << alpha[size] << " [color = lightblue, style = filled, label=\"key=" << t->right->value << ", in=" << inord << "\"];\n";
        size++;
      }
      t = t->left;
      r = r->right;
      depth++;
    }
      } 
    }
*/

  void insert(int v) { root = BinaryNode::insert(v, root); }
  void remove(int v) { root = BinaryNode::remove(v, root); }
  void display() { display(root); }
  void display( BinaryNode* t ) {
    // in-order traversal with indented display.
    static int depth = 0;
    ++ depth;
    if ( t == NULL ) return;
    if ( t->right != NULL ) display(t->right);
    for( int i = 0; i != depth; ++i )
      cout << " ";
    cout << t->value << " " << endl;
    if ( t->left != NULL )
      display(t->left);
    --depth;
  }
private:
  BinaryNode* root;
  int size;
  int inord;
  ofstream ofs;
      void inorder(BinaryNode* t) {
      const char alpha2[] = "abcdefghijklmnopqrstuvwxyz";
      if (t == NULL) {
        return;
      }
      inorder(t->left);
      ofs << alpha2[size] << " [color = lightblue, style = filled, label=\"key=" << t->value << ", in=" << inord << "\"];\n";
      if (t->left != NULL) {
        ofs << alpha2[size] << "->" << alpha2[size - 1] << endl;
      }
      if (t->right != NULL) {
        ofs << alpha2[size] << "->" << alpha2[size + 1] << endl;
      }
      inord++;
      size++;
      inorder(t->right);
    }
    void preorder(BinaryNode* t) {
      const char alpha2[] = "abcdefghijklmnopqrstuvwxyz";
      if (t == NULL) {
        return;
      }
      ofs << alpha2[size] << " [color = lightblue, style = filled, label=\"key=" << t->value << ", in=" << inord << "\"];\n";
      if (t->left != NULL) {
        ofs << alpha2[size] << "->" << alpha2[size+1] << endl;
      }
      if (t->right != NULL) {
        ofs << alpha2[size] << "->" << alpha2[size+2] << endl;
      }
      inord++;
      size++;
      preorder(t->left);
      preorder(t->right);
      
    }
    void postorder(BinaryNode *t) {
      const char alpha2[] = "abcdefghijklmnopqrstuvwxyz";
      if (t == NULL) {
        return;
      }
      postorder(t->left);
      postorder(t->right);
      ofs << alpha2[size] << " [color = lightblue, style = filled, label=\"key=" << t->value << ", post=" << inord << "\"];\n";
      if (t->left != NULL) {
        ofs << alpha2[size] << "->" << alpha2[size-2] << endl;
      }
      if (t->right != NULL) {
        ofs << alpha2[size] << "->" << alpha2[size - 1]  << endl;
      }
      size++;
      inord++;
      
    }
};

#endif /* BST_H_ */


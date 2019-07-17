#include <iostream>
#include "Tree.h"

using namespace std;

void
printOrders ( Tree* tree ) {
  cout << "Preorder = ";
  tree->preOrder ( );
  cout << "Inorder = ";
  tree->inOrder ( );
  cout << "Postorder = ";
  tree->postOrder ( );
}

int 
main ( ) {

  Tree tree;

  tree.insert ( "hoppy" );
  tree.insert ( "gadget" );
  tree.insert ( "hoppy" );
  tree.insert ( "gadget" );
  tree.insert ( "reel" );
  tree.insert ( "trap" );
  tree.insert ( "madness" );
  tree.insert ( "aeon" );
  tree.insert ( "hoppy" );
  tree.insert ( "gadget" );
  tree.insert ( "hoppy" );
  tree.insert ( "gadget" );
  tree.insert ( "reel" );
  tree.insert ( "trap" );
  tree.insert ( "madness" );
  tree.insert ( "aeon" );
  tree.insert ( "alphabet" );
  tree.insert ( "alphabet" );
  tree.insert ( "basket" );
  tree.insert ( "basket" );
  tree.insert ( "hut" );
  tree.insert ( "hit" );
  tree.insert ( "House" );
  tree.insert ( "A+" );
  tree.insert ( "jungle" );
  tree.insert ( "ink" );
  tree.insert ( "jab" );

  tree.printTreeSideways ( );

  return 1;
}
#include <iostream>
using namespace std;

struct BinaryNode
{
  string name;

  BinaryNode *left;
  BinaryNode *right;

  BinaryNode( const string & n = "", BinaryNode *lt =NULL, BinaryNode *rt =NULL )
: name(n), left( lt ), right( rt ) { };
};

//return the tree.
//BinaryNode* foo();

BinaryNode* foo()
{
    BinaryNode *root = new BinaryNode("This");
    BinaryNode *node1 = new BinaryNode("is");
    BinaryNode *node2 = new BinaryNode("simple");
    root->left = node1;
    root->right = node2;

    return root;
}
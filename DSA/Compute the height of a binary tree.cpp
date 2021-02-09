#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

typedef int T;

struct BinaryNode{
  string name;
  BinaryNode *left, *right;
  BinaryNode( const string & n = "", BinaryNode *lt =NULL, BinaryNode *rt =NULL )
: name(n), left( lt ), right( rt ) { };
};

BinaryNode* foo()
{
    BinaryNode *root = new BinaryNode("This");
    BinaryNode *node1 = new BinaryNode("is");
    BinaryNode *node2 = new BinaryNode("simple");
    BinaryNode *node3 = new BinaryNode("FUCK U");
    BinaryNode *node4 = new BinaryNode("QHY");
    BinaryNode *node5 = new BinaryNode("I am your father");
    BinaryNode *node6 = new BinaryNode("QHY");
    root->left = node1;
    root->right = node2;
    node2->left= node3;
    node2->right = node4;
    node4->left = node5;
    node4->right = node6;

    return root;
}

int height(BinaryNode* root)
{
    if(root == NULL)
        return -1;

    if(root->left == NULL && root->right == NULL)
        return 0;

    int leftHeight = height(root->left) + 1;
    int rightHeight = height(root->right) + 1;
    return (leftHeight > rightHeight) ? (leftHeight) : (rightHeight);
}

int main()
{
    BinaryNode *root = foo();
    int h = height(root);
    cout << h;

    return 0;
}
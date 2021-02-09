#include <iostream>
using namespace std;

typedef int T;
struct BinaryNode{
  T data;
  BinaryNode *left, *right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode* r=NULL):data(d), left(l), right(r) {};
};


void clear(BinaryNode *root){
  if (root){
    clear(root->left);
    clear(root->right);
    delete root;
  }
}

BinaryNode* insert(BinaryNode* root, const T &x){
    if (root == NULL)
      return new BinaryNode(x);
    else if (x < root->data)
      root->left = insert(root->left,x);
    else 
      root->right = insert(root->right,x);
    return root;
}

int main(){
  BinaryNode* root = NULL;
  insert(root,2);
  insert(root,3);
  root = insert(root,1);
  cout << root -> data<<endl;
  clear(root);
  return 0;
}
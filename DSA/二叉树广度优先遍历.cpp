#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

struct BTNode
{
    char c;

    BTNode *left;
    BTNode *right;

    BTNode(char x = ' ', BTNode *l = NULL, BTNode *r = NULL): c(x), left(l), right(r) {}
};

// BTNode *CreateTree()
// {
//     BTNode *root = new BTNode('a');
//     BTNode *node1 = new BTNode('b');
//     BTNode *node2 = new BTNode('c');
//     BTNode *node3 = new BTNode('d');
//     BTNode *node4 = new BTNode('e');
//     BTNode *node5 = new BTNode('f');
//     BTNode *node6 = new BTNode('g');
//     root->left = node1;
//     root->right = node2;
//     node2->left = node3;
//     node2->right = node4;
//     node1->left = node5;
//     node1->right = node6;

//     return root;
// }

BTNode *CreateBT(string pre, string in, int n)
{
    BTNode *root = new BTNode(pre[0], NULL, NULL);
    
    int i;
    for(i = 0; i < n; i++)
        if(in[i] == pre[0])
            break;

    if(i == 0)
        root->left = NULL;
    else
        root->left = CreateBT(pre.substr(1, i), in.substr(0, i), i);

    if(n - i - 1 == 0)
        root->right = NULL;
    else
        root->right = CreateBT(pre.substr(i + 1, n - i - 1), in.substr(i + 1, n - i - 1), n - i - 1);

    return root;
}

void levelOrder(BTNode *root)
{
    queue<BTNode *> q;
    
    q.push(root);

    while(!q.empty())
    {
        BTNode *p = q.front();
        q.pop();
        cout << p->c;

        if(p->left != NULL)
            q.push(p->left);
        if(p->right != NULL)
            q.push(p->right);
    }
}

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;

    BTNode *t = CreateBT(s1, s2, s1.size());
    levelOrder(t);
    // BTNode *t = CreateTree();
    // levelOrder(t);

    return 0;
}
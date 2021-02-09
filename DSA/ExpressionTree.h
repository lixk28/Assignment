#include <iostream>
#include <stack>
#include <queue>
#include <cstddef>
#include <string>
using namespace std;

struct Node
{
    char op;
    Node *left;
    Node *right;
};

class Expression
{
    private:
        string exp;
        bool val;
        Node *tree;
        
        string getPostfixExp(string &_exp); //将中缀表达式转换为后缀表达式
        bool calculateValue();    //计算表达式的值
        Node *createTree();  //创建表达式树
        void deleteTree(Node *node);  //销毁表达式树

    public:
        Expression(string &_exp);   //将输入的中缀表达式转换为后缀表达式，并创建表达式树
        ~Expression();

        bool getValue();    //得到表达式的值
        Node *getTree();    //得到表达式树的根节点
        string getExpression();     //得到表达式树对应的中缀表达式

        bool operator == (Expression &_exp);
};







#include "ExpressionTree.h"
// Implementation of Expression

string Expression::getPostfixExp(string &_exp)  //将中缀表达式转换为后缀表达式
{
    
}

bool Expression::calculateValue()   //计算后缀表达式的值
{
    bool result;
    //calculate

    return result;
}

Node *Expression::createTree()  //根据表达式创建表达式树
{
    
}

void Expression::deleteTree(Node *node) //销毁表达式树
{
    if(node != NULL)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
        node = NULL;
    }
}



Expression::Expression(string &_exp)    //constructot
{
    exp = getPostfixExp(_exp);
    val = calculateValue();
    tree = createTree();
}

Expression::~Expression()   //destructor
{
    deleteTree(tree);
}

bool Expression::operator == (Expression &_exp)  //比较两个表达式的值
{
    if(val == _exp.val)
        return true;
    else
        return false;
}

string Expression::getExpression() {return exp;}
bool Expression::getValue() {return val;}
Node *Expression::getTree() {return tree;}






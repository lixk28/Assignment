#include <iostream>
#include "ExpressionTree.h"

int main()
{
    string exp1, exp2;
    cout << "Please enter two expressions:\n";
    cin >> exp1 >> exp2;

    Expression e1(exp1), e2(exp2);
    cout << "The value of exp1: " << e1.getValue() << endl;
    cout << "The value of exp2: " << e2.getValue() << endl;
    
    if(e1 == e2)
        cout << "exp1 is equal to exp2." << endl;
    else
        cout << "exp1 is not equal to exp2." << endl;

    return 0;
}
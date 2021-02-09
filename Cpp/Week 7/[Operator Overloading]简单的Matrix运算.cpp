#include <iostream>
using namespace std;

class Matrix  //定义Matrix类  
{
public:
    Matrix();                                           //默认构造函数
    ~Matrix();                                          //析构函数
    Matrix(const Matrix &);                             //拷贝构造函数
    Matrix(int, int);                                   //含参数构造函数
    Matrix operator+(const Matrix &)const;              //重载运算符“+”
    Matrix& operator=(const Matrix &);                  //重载运算符“=”
    Matrix transpose()const;                            //矩阵的转置
    void display()const;                                //输出数据函数   
private:
    int row;                                            //矩阵的行
    int col;                                            //矩阵的列
    int** mat;                                          //用于储存矩阵
};

Matrix::Matrix()
{
    row = 0;
    col = 0;
    mat = NULL;
}

Matrix::Matrix(const Matrix &m)
{
    row = m.row;
    col = m.col;

    mat = new int *[row];
    for(int i = 0; i < row; i++)
        mat[i] = new int[col];

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            mat[i][j] = m.mat[i][j];
}

Matrix::Matrix(int a ,int b)
{   
    row = a;
    col = b;

    mat = new int *[row];
    for(int i = 0; i < row; i++)
        mat[i] = new int[col];

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> mat[i][j];
}

Matrix::~Matrix()
{
    if(mat != NULL)
    {
        for(int i = 0; i < row; i++)
            delete[] mat[i];
    }
    delete[] mat;
    mat = NULL;
}

Matrix Matrix::operator+(const Matrix &m) const
{
    Matrix temp;
    temp.row = row;
    temp.col = col;

    temp.mat = new int *[row];
    for(int i = 0; i < row; i++)
        temp.mat[i] = new int[col];

    for(int i = 0; i < m.row; i++)
        for(int j = 0; j < m.col; j++)
            temp.mat[i][j] = m.mat[i][j] + mat[i][j];

    return temp;
}

Matrix& Matrix::operator=(const Matrix &m)
{
    row = m.row;
    col = m.col;

    if(mat == NULL)
    {
        mat = new int *[row];
        for(int i = 0; i < row; i++)
            mat[i] = new int[col];
    }

    for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                mat[i][j] = m.mat[i][j];

    return *this;
}

Matrix Matrix::transpose() const
{
    Matrix m;
    m.row = col;
    m.col = row;
    
    m.mat = new int *[col];
    for(int i = 0; i < col; i++)
        m.mat[i] = new int[row];

    for(int i = 0; i < col; i++)
        for(int j = 0; j < row; j++)
            m.mat[i][j] = mat[j][i];

    return m;
}

void Matrix::display() const
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << mat[i][j] << " ";
            if(j == col - 1)
                cout << endl;
        }    
    }    
}


int main() {
 int row, col;
 cout << "input the row and the col for Matrix a, b" << endl;
 cin >> row >> col;
 Matrix a(row, col), b(row, col), c(a), d;
 cout << endl << "Matrix a:" << endl;
 a.display();
 cout << endl << "Matrix b:" << endl;
 b.display();
 c = a + b;//用重载运算符“+”实现两个矩阵相加 
 cout << endl << "Matrix c = Matrix a + Matrix b :" << endl;
 c.display();
 cout << endl << "Matrix a transpose to Matrix d:" << endl;
 d = a.transpose();
 d.display();
 return 0;
}
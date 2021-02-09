#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Stack {
private:
  struct node {
    int num;
    node* next;
    node() { num = 0; next = NULL; }
    node(int n, node* p = NULL) { num = n; next = p; }
  };

  node* data;
public:
  Stack();                        // 构造一个空栈
  Stack(const Stack&);            // 深拷贝
  ~Stack();                       // 注意内存回收

  Stack operator=(const Stack&);  // 深拷贝
  void push(int);                 // 入栈
  void pop();                     // 出栈
  int top() const;                // 查看栈顶元素,
  bool empty() const;             // 判断栈是否为空
  void clear();                   // 清空栈

  friend std::ostream& operator<<(std::ostream& os, const Stack& s);
};

Stack::Stack()
{
    data = new node;
    data->num = 0;
    data->next = NULL;
}

Stack::Stack(const Stack& s)
{
    data = new node;
    data->next = NULL;
    node *temp1 = data;
    node *temp2 = s.data->next;

    while(temp2 != NULL)
    {
        node *newNode = new node;
        newNode->num = temp2->num;
        newNode->next = NULL;

        temp1->next = newNode;
        temp1 = newNode;
        temp2 = temp2->next;
    }
}

Stack::~Stack()
{
    node *temp1 = data->next;
    while(temp1 != NULL)
    {
        node *temp2 = temp1;
        temp1 = temp1->next;
        delete temp2;
    }
    delete data;
}

Stack Stack::operator=(const Stack& s2) // 深拷贝
{
    Stack s1(s2);
    return s1;
}

void Stack::push(int n) // 入栈
{
    node *newTop = new node;
    newTop->num = n;
    newTop->next = data->next;
    data->next = newTop;
}

void Stack::pop() // 出栈
{
    if(!empty())
    {
        node *temp = data->next;
        data->next = temp->next;
        delete temp;
    }
}

int Stack::top() const  // 查看栈顶元素
{
    if(!empty())
        return data->next->num;
}

bool Stack::empty() const  // 判断栈是否为空
{
    if(data->next == NULL)
        return true;
    else
        return false;
}

void Stack::clear() // 清空栈
{
    node* temp1 = data->next;
    while(temp1 != NULL)
    {
        node *temp2 = temp1;
        temp1 = temp1->next;
        delete temp2;
    }
    data->next = NULL;
}

std::ostream& operator<<(std::ostream& os, const Stack& s)
{
    Stack::node *temp = s.data->next;
    os << "[";
    while(temp != NULL)
    {
        if(temp->next == NULL)
            os << temp->num << "]";
        else
            os << temp->num << ",";
        temp = temp->next;
    }
    return os;
}

void TestPushAndPop(Stack& s) {
  static int num = 0;
  for (int i = 0; i < 5; i++) {
    s.push(num++);
    cout << "push " << num << endl;
  }

  for (int i = 0; i < 7; i++) {
    if (s.empty()) {
      cout << "stack is empty!" << endl;
    } else {
      cout << "pop " << s.top() << endl;
      s.pop();
    }
  }

  for (int i = 0; i < 5; i++) {
    s.push(num++);
    cout << "push " << num << endl;
  }
}


int main() {
    cout << "----- Stack s1 -----" << endl;
    Stack s1;
    TestPushAndPop(s1);

    cout << "----- Stack s2 -----" << endl;
    Stack s2(s1);
    TestPushAndPop(s2);

    cout << "s1: " << s1 << endl
         << "s2: " << s2 << endl;


    stringstream ss;
    string str_s1, str_s2;
    ss << s1 << endl << s2;
    ss >> str_s1 >> str_s2;

    cout << "s1: " << str_s1 << endl
         << "s2: " << str_s2 << endl;

    return 0;
}
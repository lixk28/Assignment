#include <stddef.h>

class Stack {
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

  void push(int);                 // 入栈
  void pop();                     // 出栈
  int top() const;                // 查看栈顶元素，若栈为空，返回0
  bool empty() const;             // 判断栈是否为空
  void clear();                   // 清空栈
};

Stack::Stack()
{
  data = new node;
  data->next = NULL;
}

Stack::Stack(const Stack& s)
{
  data = new node;
  data->next = NULL;
  node* temp1 = data;
  node* temp2 = s.data->next;

  while(temp2 != NULL)
  {
    node* newNode = new node;
    newNode->num = temp2->num;
    newNode->next = NULL;

    temp1->next = newNode;
    temp1 = newNode;
    temp2 = temp2->next;
  }
}

Stack::~Stack()
{
  node* temp1 = data->next;
  while(temp1 != NULL)
  {
    node* temp2 = temp1;
    temp1 = temp1->next;
    delete temp2;
  }
  delete data;
}

void Stack::push(int n)
{
  node *temp = new node;
  temp->num = n;
  temp->next = data->next;
  data->next = temp;
}

void Stack::pop()
{
  if(!empty())
  {
    node* temp = data->next;
    data->next = data->next->next;
    delete temp;
  }
}

int Stack::top() const
{
  if(!empty())
    return data->next->num;
}  

bool Stack::empty() const
{
  if(data->next == NULL)
    return true;
  else
    return false;
}

void Stack::clear()
{
  node *temp1 = data->next;
  while(temp1 != NULL)
  {
    node* temp2 = temp1;
    temp1 = temp1->next;
    delete temp2;
  }
  data->next = NULL;
}

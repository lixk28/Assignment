#include <iostream>
#include <cstring>
using namespace std;

class Student {
public:
  Student();
  Student(int i , char* s = "No Name", int a = 0);
  void set(int i, char* s, int a);
  void print() const;
private:
  int id;
  char name[50]; 
  int age; 
};

Student::Student()
{
    id = 0;
    age = 0;
}

Student::Student(int i, char *s, int a)
{
    id = i;
    for(int i = 0; i < 50; i++)
        name[i] = '\0';
    for(int i = 0; i < strlen(s); i++)
        name[i] = s[i];
    age = a;
}

void Student::set(int i, char *s, int a)
{
    id = i;
    for(int i = 0; i < 50; i++)
        name[i] = '\0';
    for(int i = 0; i < strlen(s); i++)
        name[i] = s[i];
    age = a;
}

void Student::print() const
{
    cout << name << " (" << id << ") " << "is " << age << " years old." << endl;
}

int main()
{
  //freopen("D:\\1-Teaching\\��������II\\9.8.in", "r", stdin);
  //freopen("D:\\1-Teaching\\��������II\\9.8.out", "w", stdout);
  Student std1, std2(123, "Larry Jordan", 18), std3(124);
  std1.set(100, "Steven Gates", 61);
  std1.print();
  std2.print();
  std3.print();
  return 0;
}

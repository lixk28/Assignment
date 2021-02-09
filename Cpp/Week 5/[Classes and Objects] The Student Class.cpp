#include <iostream>
#include <cstring>

using namespace std;

class Student
{
public:
  int id;
  char name[50]; // Data field
  int age; // Data field
  Student();
  Student(int, char*, int);
  //void set(int, char*, int);
  //void print();
};

Student::Student()
{
    id = 0;
    age = 0;
}

Student::Student(int i, char *s, int a)
{
    id = i;
    age = a;
    for(int i = 0; i < 50; i++)
        name[i] = '\0';
    for(int i = 0; i < strlen(s); i++)
        name[i] = s[i];
}

void set(Student &std, int i, char* s, int a)
{
    std.id = i;
    std.age = a;
    for(int i = 0; i < 50; i++)
        std.name[i] = '\0';
    for(int i = 0; i < strlen(s); i++)
        std.name[i] = s[i];
}

void print(Student std)
{
    cout << std.name << " (" << std.id << ") " << "is " << std.age << " years old." << endl;
}

int main()
{
  
  Student std1, std2(123, "Larry Jordan", 18), std3(124);
  set(std1, 100, "Steven Gates", 61);
  print(std1);
  print(std2);
  print(std3);
  return 0;
}

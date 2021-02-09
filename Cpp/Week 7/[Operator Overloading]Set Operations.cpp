//
//  main.cpp
//  C++
//
//  Created by 李天培 on 16/2/25.
//  Copyright © 2016年 lee. All rights reserved.
//
 
#include <iostream>
#include <algorithm>
 
#define MAX_MEMBERS 100
 
class Set {
private:
    int members[MAX_MEMBERS];
    int size;
public:
    // Create an empty set.
    Set();
    // Create an set with some element.
    Set(int* m, int s);
    // Copy Constructor
    Set(Set const &s);
    
    // append a element to set.
    // If element in the set, return false.
    // Or insert in set and return true.
    bool append(int e);
    
    // remove a element by its value from set.
    // If element in the set, then remove it and return true.
    // Or return false.
    bool remove(int e);
    
    // return true if the set is empty, or return false.
    bool isEmptySet();
    
    // return true if the element e is in the set, or return false.
    bool isInSet(int e);
    
    // & is intersection of two set
    Set operator&(const Set &s);
    // | is union of two set
    Set operator|(const Set &s);
    // A - B is the complement of B with respect to A
    Set operator-(const Set &s);
    // A + B is their symmetric difference. A + B = (A - B) | (B - A)
    Set operator+(const Set &s);
    
    // return set.
    int* getMembers();
    
    // return size of set.
    int getSize();
    
};

Set::Set()
{
    size = 0;
    for(int i = 0; i < MAX_MEMBERS; i++)
        members[i] = 0;
}

Set::Set(int *m, int s)
{
    size = s;
    for(int i = 0; i < size; i++)
        members[i] = m[i];
}

Set::Set(Set const &s)
{
    size = s.size;
    for(int i = 0; i < size; i++)
        members[i] = s.members[i];
}

bool Set::append(int e)
{
    for(int i = 0; i < size; i++)
        if(e == members[i])
            return false;
    
    members[size] = e;
    size++;
    return true;
}

bool Set::remove(int e)
{
    int flag = -1;
    for(int i = 0; i < size; i++)
    {
        if(e == members[i])
            flag = i;
    }
    if(flag == -1)
        return false;
    for(int i = flag; i < size; i++)
        members[i] = members[i + 1];
    size--;
    return true;
}

bool Set::isEmptySet()
{
    if(size == 0)
        return true;
    else 
        return false;
}

bool Set::isInSet(int e)
{
    for(int i = 0; i < size; i++)
        if(e == members[i])
            return true;

    return false;
}

Set Set::operator&(const Set &s)
{
    Set temp;
    int k = 0;
    for(int i = 0; i < size; i++)
    {
        int flag = members[i];
        for(int j = 0; j < s.size; j++)
        {
            if(flag == s.members[j])
            {
                temp.members[k++] = flag;
                temp.size++;
            }
        }
    }
    return temp;
}

Set Set::operator|(const Set &s)
{
    Set temp;

    Set x(s);
    Set a = (*this) - x;
    Set b = x - (*this);
    Set c = (*this) & x;
    temp.size = a.size + b.size + c.size;

    int i = 0;
    for(int j = 0; j < a.size; j++)
        temp.members[i++] = a.members[j];
    for(int k = 0; k < c.size; k++)
        temp.members[i++] = c.members[k];
    for(int n = 0; n < b.size; n++)
        temp.members[i++] = b.members[n];
    
    return temp;
}

Set Set::operator-(const Set &s)
{
    Set temp;
    int k = 0;
    for(int i = 0; i < size; i++)
    {
        int flag = members[i];
        int j = 0;
        for(j; j < s.size; j++)
        {
            if(flag == s.members[j])
                break;
        }
        if(j == s.size)
        {
            temp.members[k++] = flag;
            temp.size++;
        }
    }
    return temp;
}
    
    
Set Set::operator+(const Set &s)
{
    Set a = s;
    Set temp = ((*this) - s) | (a - (*this));
    return temp;
}
    
int* Set::getMembers()
{
    return members;
}
    
int Set::getSize()
{
    return size;
}

 
void display(int* members, int size) {
    std::sort(members, members + size);
    std::cout << "{";
    for (int i = 0; i < size; i++) {
        if (i < size - 1) std::cout << members[i] << ", ";
        else std::cout << members[i];
    }
    std::cout << "}" << std::endl;
}
 
int main(int argc, const char * argv[]) {
    int test[6];
    std::cin >> test[0]
    >> test[1]
    >> test[2]
    >> test[3]
    >> test[4]
    >> test[5];
    // Constructor 1
    Set s1 = Set();
    display(s1.getMembers(), s1.getSize());
    std::cout << "is empty set: " << s1.isEmptySet() << std::endl;
    // append func
    std::cout << "append: " << s1.append(test[0]) << std::endl;
    std::cout << "append: " << s1.append(test[4]) << std::endl;
    display(s1.getMembers(), s1.getSize());
    // repeat append
    std::cout << "append: " << s1.append(test[0]) << std::endl;
    display(s1.getMembers(), s1.getSize());
 
    std::cout << "is empty set: " << s1.isEmptySet() << std::endl;
 
    // Constructor 2
    Set s2 = Set(test, 5);
    // remove func
    std::cout << "remove: " << s2.remove(test[0]) << std::endl;
    display(s2.getMembers(), s2.getSize());
    // repeat append
    std::cout << "remove: " << s2.remove(test[0]) << std::endl;
    display(s2.getMembers(), s2.getSize());
 
    std::cout << test[5] << " is in set: " << s2.isInSet(test[5]) << std::endl;
    std::cout << test[2] << " is in set: " << s2.isInSet(test[2]) << std::endl;
 
    display(s1.getMembers(), s1.getSize());
    display(s2.getMembers(), s2.getSize());
 
    Set s3;
    s3 = s1 & s2;
    display(s3.getMembers(), s3.getSize());
 
    s3 = s1 | s2;
    display(s3.getMembers(), s3.getSize());
 
    s3 = s1 - s2;
    display(s3.getMembers(), s3.getSize());
 
    s3 = s2 - s1;
    display(s3.getMembers(), s3.getSize());
 
    s3 = s1 + s2;
    display(s3.getMembers(), s3.getSize());
 
    return 0;
}
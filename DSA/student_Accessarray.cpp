/*
 * @Author: Xuekun Li
 * @Date: 2020-11-10 21:56:12
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-11-10 23:41:48
 * @Description: Try to code your bug.
 */

#include <iostream>
#include <vector>
#include <string>
//#include <iterator>

#include <algorithm>

using namespace std;

struct Customer {
  string name;
  string phone;
  string address;

  Customer(string _name, string _phone, string _address): name(_name), phone(_phone), address(_address) {}
};

bool Compare(const Customer &c1, const Customer &c2)
{
    if(c1.name < c2.name)
        return true;
    else
        return false;
}

bool isEqual(const Customer &c1, const Customer &c2)
{
    if(c1.name == c2.name && c1.phone == c2.phone && c1.address == c2.address)
        return true;
    else
        return false;
}

int getIndex(const vector<Customer> &table, const Customer &c)
{
    int i = 0;
    for(auto x: table)
    {
        if(!isEqual(x, c))
            i++;
        else
            break;
    }
    return i;
}

vector<int> accessArray(const vector<Customer> &table)
{
    vector<int> indexArray;
    vector<Customer> sortedTable = table;
    std::sort(sortedTable.begin(), sortedTable.end(), Compare);
    for(auto i: sortedTable)
    {
        int index = getIndex(table, i);
        indexArray.push_back(index);
    }

    return indexArray;
}


void print(vector<int> v)
{
    for(auto i: v)
        cout << i << endl;
}



int main()
{
    vector<Customer> table;
    Customer c1("Wang", "123456", "address1");
    Customer c2("Gao", "23456", "address2");
    Customer c3("Li", "55688", "address3");
    Customer c4("Hao", "56788", "address4");

    table.push_back(c1);
    table.push_back(c2);
    table.push_back(c3);
    table.push_back(c4);

    vector<int> indexArray = accessArray(table);

    print(indexArray);

    return 0;
}

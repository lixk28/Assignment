/*
 * @Author: Xuekun Li
 * @Date: 2020-11-10 23:43:48
 * @LastEditor: Xuekun Li
 * @LastEditTime: 2020-11-11 19:18:56
 * @Description: Try to code your bug.
 */

#include "md5.h"
#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

struct Customer
{
    string username;
    string password;
};

struct Info
{
    Customer user;
    Info *next;

    Info() { next = NULL; }
};

unsigned int getHashAddress(string str)
{
    unsigned int seed = 131;
	unsigned int hash = 0;

	for (unsigned int i = 0; i < str.length(); i++)
		hash = (hash * seed) + str[i];

	return hash % 100009;
}

void Insert(Info HashTable[], unsigned int HashAddress, const string &_username, const string &_password) 
{
    Info *node = new Info;
    (node->user).username = _username;
    (node->user).password = _password;

    node->next = HashTable[HashAddress].next;
    HashTable[HashAddress].next = node;
}

bool Search(Info HashTable[], unsigned int HashAddress, const string &_username, const string &_password)
{
    Info *curr = HashTable[HashAddress].next;
    while(curr != NULL)
    {
        if((curr->user).username == _username && (curr->user).password == _password)
            break;
        else
            curr = curr->next;
    }
    if(curr == NULL)
        return false;
    else
        return true;
}



int main()
{
    int n;
    cin >> n;
    Info *HashTable = new Info[100009]; 

    while(n--)
    {
        string _username, _password;
        cin >> _username >> _password;
        unsigned int HashAddress = getHashAddress(_username);
        Insert(HashTable, HashAddress, _username, _password);
    }

    int m;
    cin >> m;
    Customer customers[10000];
    unsigned int HashAddresses[10000] = {0};
    for (int i = 0; i < m; i++)
    {
        string _username, _password;
        cin >> _username >> _password;
        customers[i].username = _username;
        customers[i].password = _password;

        HashAddresses[i] = getHashAddress(_username);
    }

    for (int i = 0; i < m; i++)
    {
        if(Search(HashTable, HashAddresses[i], customers[i].username, md5(customers[i].password)))
            cout << customers[i].username << ":OK" << endl;
        else
            cout << customers[i].username << ":Invalid user name or password" << endl;
    }

    for (int i = 0; i < 100009; i++)
    {
        Info *head = HashTable[i].next;
        while(head != NULL)
        {
            Info *temp = head;
            head = head->next;
            delete temp;
        }
        HashTable[i].next = NULL;
    }
    delete[] HashTable;

    return 0;
}
#include <iostream>
#include <string.h>

template< typename T >
class Set
{
public:
 Set() ;
 Set( int maxSize ) ;
 ~Set() ;
 Set( const Set& ) ;
 Set operator+( const Set& s ) ;
 Set operator-( const Set& s ) ;
 void operator=( const Set& s ) ;
 bool insert( T newItem ) ;
 bool erase( T targetItem ) ;
 void print() const ;
 T* getData() const ;
 int getCount() const ;
 int getMaxSize() const ;
private:
 int count ;
 int maxSize ;
 T* data ;
} ;

template <typename T>
Set<T>::Set() 
{
    count = 0;
    maxSize = 0;
    data = NULL;
}

template <typename T>
Set<T>::Set(int m)
{
    count = 0;
    maxSize = m;
    data = new T[m];
}

template <typename T>
Set<T>::Set( const Set& )
{
    count = Set.count;
    maxSize = Set.maxSize;
    for(int i = 0; i < count; i++)
        data[i] = Set.data[i];
}

template <typename T>
Set<T>::~Set()
{
    delete[] data;
}

template <typename T>
Set<T> Set<T>::operator+( const Set<T>& s )
{
    int m = maxSize + s.maxSize;
    Set sum(m);

    int k = 0;
    for(int i = 0; i < count; i++)
    {
        int flag = 0;
        for(int j = 0; j < s.count; j++)
        {
            if(data[i] == s.data[j])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            sum.data[k++] = data[i];
            sum.count++;
        }
    }
}

template <typename T>
Set<T> Set<T>::operator-( const Set<T>& s )
{
    int m = maxSize;
    Set dif(m);

    int k = 0;
    for(int i = 0; i < count; i++)
    {
        int flag = 0;
        for(int j = 0; j < s.count; j++)
        {
            if(data[i] == s.data[j])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            dif.data[k++] = data[i];
            dif.count++;
        }
    }
}

template <typename T>
void Set<T>::operator=( const Set& s )
{
    count = s.count;
    maxSize = s.maxSize;
    for(int i = 0; i < count; i++)
        data[i] = s.data[i];
}

template <typename T>
bool Set<T>::insert( T newItem )
{
    if(count < maxSize)
    {
        data[count] = newItem;
        count++;
        return true;
    }
    else
        return false;
}

template <typename T>
bool Set<T>::erase( T targetItem )
{
    for(int i = 0; i < count; i++)
        if(data[i] == targetItem)
        {
            for(int j = i; j < count - 1; j++)
                data[j] = data[j + 1];
        }

}

template <typename T>
void Set<T>::print() const
{
    for(int i = 0; i < count; i++)
        cout << data[i] << " ";
    cout << endl;
}

template <typename T>
T* Set<T>::getData() const { return data; }
template <typename T>
int Set<T>::getCount() const { return count; }
template <typename T>
int Set<T>::getMaxSize() const { return maxSize; }



using namespace std ;

//test operator + and operator - and intersection
void test1()
{
	Set<int> s1( 10 ), s2( 10 ), s_plus, s_minus, s_intersection ;
	
	s1.insert( 1 ) ;
	s1.insert( 2 ) ;
	s1.insert( 2 ) ;
	s1.insert( 4 ) ;
	cout << "Items in s1 are : " ;
	s1.print() ;
	
	s2.insert( 3 ) ;
	s2.insert( 3 ) ;
	s2.insert( 1 ) ;
	s2.insert( 2 ) ;
	cout << "Items in s2 are: " ;
	s2.print() ;
	
	s_plus = s1 + s2 ;
	cout << "Items in s_plus are: " ;
	s_plus.print() ;
	
	s_minus = s1 - s2 ;
	cout << "Items in s_minus are: " ;
	s_minus.print() ;
	
	s_intersection = s1 - ( s1 - s2 ) ;
	cout << "Items in s_intersection are: " ;
	s_intersection.print() ;
}

void test2()
{
	Set<double> s1( 100 ), s2( 100 ), s_plus, s_minus, s_intersection ;
	
	
	for ( int i = 0; i < s1.getMaxSize(); i++ )
	{
		s1.insert( i % 17 ) ;
	}
	cout << "Items in s1 are : " ;
	s1.print() ;
	for ( int i = 0; i < s2.getMaxSize(); i++ )
	{
		s2.insert( i % 15 ) ;
	}
	cout << "Items in s2 are: " ;
	s2.print() ;
	
	s_plus = s1 + s2 ;
	cout << "Items in s_plus are: " ;
	s_plus.print() ;
	
	s_minus = s1 - s2 ;
	cout << "Items in s_minus are: " ;
	s_minus.print() ;
	
	s_intersection = s1 - ( s1 - s2 ) ;
	cout << "Items in s_intersection are: " ;
	s_intersection.print() ;
}

void test3()
{
	Set<char> s1( 1000 ), s2( 1000 ), s_plus, s_minus, s_intersection ;
	const char str1[] = "adsfasdfasdfasdfdshfhasdfashjglcnvyerwqjtoiruetwertbnsdfosiftgwertiu324u54owert" ;
	const char str2[] = "adsfhahdfuqwernfqwjerfqwhtfihvagiutewrfbnsduasdfqwerqwgb ahb.,p[phvbfgiopsudfgsdafjfas" ;
	
	for ( int i = 0; i < strlen( str1 ); i++ )
	{
		s1.insert( str1[i] ) ;
	}
	cout << "Items in s1 are : " ;
	s1.print() ;
	for ( int i = 0; i < strlen( str2 ); i++ )
	{
		s2.insert( str2[i] ) ;
	}
	cout << "Items in s2 are: " ;
	s2.print() ;
	
		s_plus = s1 + s2 ;
	cout << "Items in s_plus are: " ;
	s_plus.print() ;
	
	s_minus = s1 - s2 ;
	cout << "Items in s_minus are: " ;
	s_minus.print() ;
	
	s_intersection = s1 - ( s1 - s2 ) ;
	cout << "Items in s_intersection are: " ;
	s_intersection.print() ;
}

int main()
{
	test1() ;
	test2() ;
	test3() ;
	return 0 ;
}
#include<stdio.h>

void quicksort(int *a,int begin,int end)
{
    if(begin >= end)
        return;
    
    int i=begin;
    int j=end;
    int key=a[begin];

    while(i<j)
    {
        while(i<j && a[j]>=key)
            j--;
        a[i]=a[j];

        while(i<j && a[i]<=key)
            i++;
        a[j]=a[i];
    }
    a[i]=key;
    quicksort(a,begin,i-1);
    quicksort(a,i+1,end);
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    quicksort(a,0,n-1);

    printf("%d",a[n-2]);

    return 0;
}
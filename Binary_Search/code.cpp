#include<iostream>
using namespace std;

int BinSrch(int a[], int i, int l, int x)
{
    if(i==l)
    {
        if(a[i]==x)
            return i;
        else
            return -1;
    }
    else
    {
        int mid=(i+l)/2;
        if(x==a[mid])
            return mid;
        else if(x<a[mid])
           return BinSrch(a,i,mid-1,x);
        else
           return BinSrch(a,mid+1,l,x);
    }
}

int main()
{
    int n,x,l;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter all sorted elements: ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter searching element: ";
    cin>>x;
    l=BinSrch(a,0,n-1,x);
    if(l==-1)
        cout<<"Item not found"<<endl;
    else
        cout<<"Item found in "<<l+1<<"th position."<<endl;
    return 0;
}
#include<iostream>
using namespace std;

void Interchange(int a[],int i,int j)
{
    int p;
    p=a[i];
    a[i]=a[j];
    a[j]=p;
}

int Partition(int a[], int m, int p)
{
    int v,i,j;
    v=a[m];
    i=m;
    j=p;
    while(i<j)
    {
        while(i<p && a[i]<=v)
            i=i+1;
        while(j>m && a[j]>=v)
            j=j-1;
        if(i<j)
            Interchange(a,i,j);
    }
    Interchange(a, m, j);
    return j;
}

void QuickSort(int a[], int p, int q)
{
    int j;
    if(p<q)
    {
        j=Partition(a,p,q);
        QuickSort(a,p,j-1);
        QuickSort(a,j+1,q);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter all elements: ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    QuickSort(a,0,n-1);
    cout<<"After sorting elements: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
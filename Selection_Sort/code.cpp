#include<iostream>
using namespace std;
void SelectionSort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int j=i;
        for(int k=j+1;k<n;k++)
        {
            if(a[k]<a[j])
                j=k;
        }
        swap(a[i],a[j]);
    }
}
int main()
{
    int n;
    cout<<"Enter the size :";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    SelectionSort(a,n);
    cout<<"After sorting: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
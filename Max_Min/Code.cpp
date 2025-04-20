#include<iostream>
using namespace std;
void MaxMin(int i,int j,int a[],int &max,int &min)
{
    if(i==j)
    {
        max=min=a[i];
    }
    else if(i==j-1)
    {
        if(a[i]>a[j])
        {
            max=a[i];
            min=a[j];
        }
        else
        {
            max=a[j];
            min=a[i];
        }
    }
    else
    {
        int mid=(i+j)/2;
        int max1,min1;
        MaxMin(i,mid,a,max,min);
        MaxMin(mid+1,j,a,max1,min1);
        if(max<max1)
            max=max1;
        if(min>min1)
            min=min1;
    }
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n],max,min;
    cout<<"Enter all value of the array: ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    MaxMin(0,n-1,a,max,min);
    cout<<"Maximum number is: "<<max<<endl;
    cout<<"Minimum number is: "<<min<<endl;
    return 0;
}
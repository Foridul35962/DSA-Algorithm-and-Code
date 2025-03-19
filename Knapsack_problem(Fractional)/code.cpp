#include<iostream>
using namespace std;
float Knapsack(int p[], int w[], int m, int n)
{
    float x[n],sum=0;
    int b;
    for(int i=0;i<n;i++)
    {
        x[i]=(float)p[i]/w[i];
    }
    while(m!=0)
    {
        int l=-1;
        for(int i=0;i<n;i++)
        {
            if(x[i]>l)
            {
                l=x[i];
                b=i;
            }
        }
        if(m>=w[b])
        {
            sum+=p[b];
            m-=w[b];
            x[b]=0;
        }
        else
        {
            sum+=m*x[b];
            m=0;
        }
        if(m==0)
            break;
    }
    return sum;
}
int main()
{
    int n;
    float sum;
    cout<<"Enter item size: ";
    cin>>n;
    int p[n],w[n],c;
    cout<<"Enter the profit of items: ";
    for(int i=0;i<n;i++)
        cin>>p[i];
    cout<<"Enter the weight of items: ";
    for(int i=0;i<n;i++)
        cin>>w[i];
    cout<<"Enter the capacity of bag: ";
    cin>>c;
    sum=Knapsack(p,w,c,n);
    cout<<"Ans: "<<sum<<endl;
    return 0;
}
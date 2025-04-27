#include <iostream>
using namespace std;
int knapsack(int c, int w[], int p[], int n)
{
    // Base Case
    if (n == 0 || c == 0)
        return 0;

    if (w[n - 1] > c)
        return knapsack(c,w,p,n - 1);

    else
        return max(p[n - 1]+ knapsack(c - w[n - 1],w,p, n - 1),
                   knapsack(c, w, p, n - 1));
}

int main()
{
    int n;
    cout<<"Enter the number of object: ";
    cin>>n;
    int p[n],w[n],c;
    cout<<"Enter the value of profit: ";
    for(int i=0;i<n;i++)
        cin>>p[i];
    cout<<"Enter the value of weight: ";
    for(int i=0;i<n;i++)
        cin>>w[i];
    cout<<"Enter the value of bag capacity: ";
    cin>>c;
    cout<<"Result: "<<knapsack(c,w,p,n)<<endl;
    return 0;
}

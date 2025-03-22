#include<bits/stdc++.h>
using namespace std;

void JSD(vector<array<int,3>>&v)
{
    int sum=0;
    map<int,int>m;
    vector<int>c;
    for(auto u:v)
    {
        for(int i=u[2];i>0;i--)
        {
            if(m[i]==0)
            {
                m[i]++;
                sum+=u[1];
                c.push_back(u[0]);
                break;
            }
        }
    }
    cout<<"we take the jobs number: ";
    for(auto u:c)
        cout<<u<<" ";
    cout<<endl;
    cout<<"Total profit: "<<sum<<endl;
}
int main()
{
    int n;
    cout<<"Enter the size of jobs: ";
    cin>>n;
    vector<array<int,3>>v;
    for(int i=0;i<n;i++)
    {
        int a[3];
        a[0]=i+1;
        cout<<"Enter the "<<i+1<<" job profit and deadlines: ";
        cin>>a[1]>>a[2];
        v.push_back({a[0],a[1],a[2]});
    }
    sort(v.begin(),v.end(),[](const array<int,3> &a, const array<int,3> &b)
    {
        return a[1]>b[1];
    });
    JSD(v);
    return 0;
}
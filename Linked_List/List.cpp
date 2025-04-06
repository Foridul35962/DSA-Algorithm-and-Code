#include<iostream>
#include<list>
using namespace std;
void display(list<int>&ls)
{
    list<int>::iterator it=ls.begin();
    while(it!=ls.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
}
int main()
{
    list<int>ls;
    ls.push_back(5);
    ls.push_back(2);
    ls.push_back(1);
    ls.push_back(8);
    display(ls);
    ls.sort();
    cout<<"After sorting: ";
    display(ls);
    ls.pop_back();
    display(ls);
    return 0;
}
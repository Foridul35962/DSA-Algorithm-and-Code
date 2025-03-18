#include<iostream>
using namespace std;
void TowerOfHanoi(int n, char x, char y, char z)
{
    if(n>=1)
    {
        TowerOfHanoi(n-1,x,z,y);
        cout<<"move top disk from tower "<<x<<" to top of tower "<<y<<endl;
        TowerOfHanoi(n-1,z,y,x);
    }
}
int main()
{
    int n;
    cout<<"Enter the disk number: ";
    cin>>n;
    TowerOfHanoi(n,'A','B','C');
    return 0;
}
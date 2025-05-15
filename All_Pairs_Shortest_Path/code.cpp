#include <iostream>
using namespace std;

class ShortestPath
{
private:
    int n;
    int **a;

public:
    ShortestPath() : n(0), a(nullptr) {}
    ~ShortestPath();
    void getdata();
    void all_paths();
    void display();
};

ShortestPath::~ShortestPath()
{
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}

void ShortestPath::getdata()
{
    cout<<"Enter the number of vertices: ";
    cin>>n;
    a= new int* [n];
    for(int i=0;i<n;i++)
        a[i]= new int[n];
    cout<<"Enter the adjacency matrix :"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
}

void ShortestPath::all_paths()
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=min(a[i][j], a[i][k]+a[k][j]);
            }
        }
    }
}

void ShortestPath::display()
{
    cout<<"The Shortest Path is:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    ShortestPath obj;
    obj.getdata();
    obj.all_paths();
    obj.display();
    return 0;
}
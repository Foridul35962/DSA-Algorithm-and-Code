#include<iostream>
using namespace std;

class Segment_Tree
{
private:
    int n;
    int* a;
    int* tree;
public:
    Segment_Tree(): n(0), tree(nullptr), a(nullptr){}
    ~Segment_Tree();
    void getdata();
    void build_tree(int node, int st, int end);
    void display();
    int get_n();
};

Segment_Tree::~Segment_Tree()
{
    delete[] tree;
    delete[] a;
}

void Segment_Tree::getdata()
{
    cout<<"Enter the number of value: ";
    cin>>n;
    tree= new int[n*4];
    a= new int[n];
    cout<<"Enter all values: ";
    for(int i=0;i<n;i++)
        cin>>a[i];
}

int Segment_Tree::get_n()
{
    return n;
}

void Segment_Tree::build_tree(int node, int st, int end)
{
    if(st==end)
    {
        tree[node]=a[st];
        return;
    }
    int mid=(st+end)/2;
    build_tree(2*node, st, mid);
    build_tree(2*node+1, mid+1, end);
    tree[node]=(tree[2*node]+tree[2*node+1]);
}

void Segment_Tree::display()
{
    cout<<"Segment tree is: ";
    for(int i=1;i<n*2;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    Segment_Tree obj;
    obj.getdata();
    obj.build_tree(1,0,obj.get_n()-1);
    obj.display();
    return 0;
}
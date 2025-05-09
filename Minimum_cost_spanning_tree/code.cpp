#include<iostream>
using namespace std;
class MST
{
private:
    int n;
    int** graph;    //**for 2D array
public:
    MST(): n(0), graph(nullptr){}   //constractor
    ~MST();         //deconstractor
    void getdata();
    int minkey(int key[],bool mstset[]);
    void print(int parent[]);
    void primsMST();
};
MST::~MST()
{
    for(int i=0;i<n;i++)
        delete[] graph[i];
    delete[] graph;
}
void MST::getdata()
{
    cout<<"Enter the number of vertices: ";
    cin>>n;
    graph=new int*[n];
    for(int i=0;i<n;i++)
        graph[i]=new int[n];
    cout<<"Enter the adjacency matrix for vertices:"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];
}
void MST::primsMST()
{
    int parent[n];
    int key[n];
    bool mstset[n];
    for(int i=0;i<n;i++)
    {
        key[i]=INT_MAX;
        mstset[i]=false;
    }
    parent[0]=-1;
    key[0]=0;
    for(int i=0;i<n-1;i++)
    {
        int u=minkey(key,mstset);
        mstset[u]=true;
        for(int i=0;i<n;i++)
        {
            if(graph[u][i] && mstset[i]== false && graph[u][i]<key[i])
            {
                parent[i]=u;
                key[i]=graph[u][i];
            }
        }
    }
    print(parent);
}
int MST::minkey(int key[], bool mstset[])
{
    int min=INT_MAX, min_index;
    for(int i=0;i<n;i++)
    {
        if(mstset[i]==false && key[i]<min)
        {
            min=key[i];
            min_index=i;
        } 
    }
    return min_index;
}
void MST::print(int parent[])
{
    cout << "Edge \tWeight\n";
    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<" - "<<i<<"\t"<<graph[parent[i]][i]<<endl;
    }
}
int main()
{
    MST obj;
    obj.getdata();
    obj.primsMST();
    return 0;
}
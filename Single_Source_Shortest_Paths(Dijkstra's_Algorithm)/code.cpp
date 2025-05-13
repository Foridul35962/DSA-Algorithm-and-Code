#include<iostream>
using namespace std;

class ShortestPath
{
private:
    int n;
    int src;
    int** graph;
public:
    ShortestPath(): n(0), graph(nullptr){}
    ~ShortestPath();
    void getdata();
    void greedy_dijsktra();
    int min_dist(int dist[], bool visited[]);
    void display(int dist[]);
};

ShortestPath::~ShortestPath()
{
    for(int i=0;i<n;i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
}

void ShortestPath::getdata()
{
    cout<<"Enter the number of all vertices: ";
    cin>>n;
    graph= new int*[n];
    for(int i=0;i<n;i++)
    {
        graph[i]= new int[n];
    }
    cout<<"Enter the adjecent martix for graph:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    cout<<"Enter the source vertice: ";
    cin>>src;
}

void ShortestPath::greedy_dijsktra()
{
    int dist[n];
    bool visited[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    dist[src]=0;
    for(int i=0;i<n;i++)
    {
        int m= min_dist(dist,visited);
        visited[m]=true;
        for(int j=0;j<n;j++)
        {
            if(!visited[j]&& graph[m][j]&& dist[m]!=INT_MAX && dist[m]+graph[m][j]<dist[j])
            {
                dist[j]=dist[m]+graph[m][j];
            }
        }
    }
    display(dist);
}

int ShortestPath::min_dist(int dist[], bool visited[])
{
    int min=INT_MAX, ind;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false && dist[i]<=min)
        {
            min=dist[i];
            ind=i;
        }
    }
    return ind;
}

void ShortestPath::display(int dist[])
{
    cout<<"Vertex\t\t dist from source vertex"<<endl;
    for(int i=0;i<n;i++)
    {
        char str=65+i;
        cout<<str<<"\t\t\t"<<dist[i]<<endl;
    }
}

int main()
{
    ShortestPath obj;
    obj.getdata();
    obj.greedy_dijsktra();
    return 0;

//       {0, 1, 2, 0, 0, 0},
//       {1, 0, 0, 5, 1, 0},
//       {2, 0, 0, 2, 3, 0},
//       {0, 5, 2, 0, 2, 2},
//       {0, 1, 3, 2, 0, 1},
//       {0, 0, 0, 2, 1, 0}

}
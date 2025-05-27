#include<iostream>
using namespace std;
class Color
{
private:
    int n,m;
    int** graph;
public:
    Color(): n(0), graph(nullptr){}
    ~Color();
    void getdata();
    bool graphColoring();
    bool graphColoringUtil(int color[], int v);
    bool isSafe(int v, int color[], int c);
    void printSolution(int color[]);
};

void Color::getdata()
{
    cout<<"Enter the number of vertices: ";
    cin>>n;
    graph= new int*[n];
    for(int i=0;i<n;i++)
    {
        graph[i]= new int[n];
    }
    cout<<"Enter the adjacency matrix for the graph:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    cout<<"Enter the number of color: ";
    cin>>m;
}

Color::~Color()
{
    for(int i=0;i<n;i++)
        delete[] graph[i];
    delete[] graph;
}

bool Color::graphColoring()
{
    int color[n];
    for (int i = 0; i < n; i++)
        color[i] = 0;
    if (graphColoringUtil(color, 0) == false) {
        cout << "Solution does not exist";
        return false;
    }
    printSolution(color);
    return true;
}

bool Color::graphColoringUtil(int color[], int v)
{
    if (v == n)
        return true;
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, color, c)) {
            color[v] = c;
            if (graphColoringUtil(color, v + 1)
                == true)
                return true;
            color[v] = 0;
        }
    }
    return false;
}

bool Color::isSafe(int v, int color[], int c)
{
    for (int i = 0; i < n; i++)
        if (graph[v][i] && c == color[i])
            return false;

    return true;
}

void Color::printSolution(int color[])
{
    cout << "Solution Exists: Following are the assigned colors"<<endl;
    for (int i = 0; i < n; i++)
        cout<<color[i]<<" ";
    cout << endl;
}

int main()
{
    Color obj;
    obj.getdata();
    obj.graphColoring();
    return 0;
}

// graph= {
//         { 0, 1, 1, 1 },
//         { 1, 0, 1, 0 },
//         { 1, 1, 0, 1 },
//         { 1, 0, 1, 0 },
//     };
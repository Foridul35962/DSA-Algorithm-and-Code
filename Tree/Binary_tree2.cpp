#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node(int data)
    {
        val=data;
        left=NULL;
        right=NULL;
    }
};

static int idx=-1;
Node* build_tree(vector<int>v)
{
    idx++;
    if(v[idx]==-1)
        return NULL;
    Node* root= new Node(v[idx]);
    root->left=build_tree(v);
    root->right=build_tree(v);
    return root;
}

int hight_tree(Node* root)
{
    if(root==NULL)
        return 0;
    int left=hight_tree(root->left);
    int right=hight_tree(root->right);
    return max(left,right)+1;
}

int count_vertices(Node* root)
{
    if(root==NULL)
        return 0;
    int left=count_vertices(root->left);
    int right=count_vertices(root->right);
    return left+right+1;
}

int sum(Node* root)
{
    if(root==NULL)
        return 0;
    return root->val+sum(root->left)+sum(root->right);
}

int main()
{
    vector<int>v;
    int n;
    cout<<"Enter number of all vertices: ";
    cin>>n;
    n=(2*n)+1;
    cout<<"Enter the value of vertices(pre_order with null edges): ";

    /*the value of vertices be like (1 2 -1 -1 3 4 -1 -1 5 -1 -1) for 5 vertices.*/

    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    Node* root= build_tree(v);
    cout<<"Hight of the tree is: "<<hight_tree(root)<<endl;
    cout<<"This tree has "<<count_vertices(root)<<"th vertices."<<endl;
    cout<<"Sum of all vertices is: "<<sum(root)<<endl;
    return 0;
}
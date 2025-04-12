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
        left=right=NULL;
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

void pre_order(Node* root)
{
    if(root==NULL)
        return;
    cout<<root->val<<" ";
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(Node* root)
{
    if(root==NULL)
        return;
    in_order(root->left);
    cout<<root->val<<" ";
    in_order(root->right);
}

void post_order(Node* root)
{
    if(root==NULL)
        return;
    post_order(root->left);
    post_order(root->right);
    cout<<root->val<<" ";
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
    cout<<"What type of traversal you want to see: "<<endl;
    cout<<"1. Pre-order traversal"<<endl;
    cout<<"1. Pre-order traversal"<<endl;
    cout<<"2. In-order traversal"<<endl;
    cout<<"3. Post-order traversal"<<endl;
    cout<<"Enter your choice: ";
    cin>>n;
    switch (n)
    {
    case 1:
        pre_order(root);
        break;
    case 2:
        in_order(root);
        break;
    case 3:
        post_order(root);
        break;
    default:
        cout<<"You Enter Wrong choice."<<endl;
        break;
    }
    return 0;
}
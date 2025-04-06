#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
class List
{
private:
    Node* head;
    Node* tail;
public:
    List()
    {
        head=NULL;
        tail=NULL;
    }
    void push(int val);
    void display();
    void reverse();
};

void List::push(int val)
{
    Node* newNode= new Node(val);
    if(head==NULL)
    {
        head=tail=newNode;
    }
    else
    {
        tail->next=newNode;
        tail=newNode;
    }
}

void List::display()
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void List::reverse()
{
    Node* pre=NULL;
    Node* cur=head;
    Node* next=NULL;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=pre;

        pre=cur;
        cur=next;
    }
    head=pre;
}

int main()
{
    List obj;
    while(1)
    {
        int n;
        cout<<"What do you want:"<<endl;
        cout<<"1. push data."<<endl;
        cout<<"2. Display all data"<<endl;
        cout<<"3. Reverse data"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice number: ";
        cin>>n;
        if(n==1)
        {
            int val;
            cout<<"Enter value: ";
            cin>>val;
            obj.push(val);
        }
        else if(n==2)
            obj.display();
        else if(n==3)
            obj.reverse();
        else if(n==4)
            break;
    }
    return 0;
}
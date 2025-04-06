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
    Node* head;
    Node* tail;
public:
    List()
    {
        head=tail=NULL;
    };
    void push_front(int val);
    void push_back(int val);
    void dis();
    void pop_front();
    void pop_back();
    void pop(int pos);
    void insert(int val, int pos);
};

void List::push_front(int val)
{
    Node* newNode = new Node(val);
    if(head==NULL)
    {
        head=tail=newNode;
        return;
    }
    else
    {
        newNode ->next=head;
        head=newNode;
    }
}

void List::push_back(int val)
{
    Node* newNode= new Node(val);
    if(head==NULL)
    {
        head=tail=newNode;
    }
    else
    {
        tail->next=newNode;
        tail= newNode;
    }
}

void List::insert(int val, int pos)
{
    if(pos<0)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    else if(pos==0)
    {
        push_front(val);
        return;
    }
    else
    {
        Node* temp=head;
        for(int i=0;i<pos-2;i++)
        {
            if(temp==NULL)
            {
                cout<<"Invalid data"<<endl;
                return;
            }
            temp=temp->next;
        }
        Node* newNode= new Node(val);
        newNode->next= temp->next;
        temp->next=newNode;
    }
}

void List::pop_front()
{
    if(head==NULL)
    {
        cout<<"Linked List is empty."<<endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
}

void List::pop_back()
{
    if(head==NULL)
    {
        cout<<"Linked List is empty."<<endl;
        return;
    }
    Node* temp=head;
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    delete tail;
    tail=temp;
}

void List::pop(int pos)
{
    if(head==NULL)
    {
        cout<<"Linked List is empty."<<endl;
        return;
    }
    if(pos==1)
    {
        pop_front();
        return;
    }
    Node* temp=head;
    for(int i=0;i<pos-2;i++)
    {
        temp=temp->next;
    }
    Node* dlt=temp->next;
    temp->next=dlt->next;
    delete dlt;
}

void List::dis()
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main()
{
    List obj;
    cout<<"Welcome to Linked List\n"<<endl;
    while(1)
    {
        int n;
        cout<<"What do you want:"<<endl;
        cout<<"1. push data."<<endl;
        cout<<"2. pop data"<<endl;
        cout<<"3. Display all data"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice number: ";
        cin>>n;
        cout<<endl;
        if(n==1)
        {
            int val;
            cout<<"Where are you want to push your data:"<<endl;
            cout<<"1. Push front."<<endl;
            cout<<"2. Push back."<<endl;
            cout<<"3. Insert by position."<<endl;
            cout<<"Enter your choice number: ";
            cin>>n;
            cout<<"Enter value: ";
            cin>>val;
            if(n==1)
            {
                obj.push_front(val);
            }
            else if (n==2)
            {
                obj.push_back(val);
            }
            else if(n==3)
            {
                cout<<"Enter the position: ";
                int pos;
                cin>>pos;
                obj.insert(val,pos);
            }
            else
            {
                cout<<"You enter wrong choice."<<endl;
            }
        }
        else if(n==2)
        {
            cout<<"Where are you want to pop your data:"<<endl;
            cout<<"1. pop front."<<endl;
            cout<<"2. pop back."<<endl;
            cout<<"3. pop by position."<<endl;
            cout<<"Enter your choice number: ";
            cin>>n;
            if (n==1)
            {
                obj.pop_front();
            }
            else if(n==2)
            {
                obj.pop_back();
            }
            else if(n==3)
            {
                int pos;
                cout<<"Enter the position: ";
                cin>>pos;
                obj.pop(pos);
            }
            else
            {
                cout<<"You enter wrong choice."<<endl;
            }
        }
        else if(n==3)
        {
            obj.dis();
        }
        else if(n==4)
        {
            break;
        }
        else
        {
            cout<<"You enter wrong choice."<<endl;
        }
        cout<<endl;
    }
    return 0;
}
#include<iostream>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int data)
    {
        val=data;
        next=NULL;
        prev=NULL;
    }
};

class List
{
private:
    Node* head=NULL;
    Node* tail=NULL;

public:
    void push_back(int pos);
    void push_front(int pos);
    void insert(int val, int pos);
    void pop_back();
    void pop_front();
    void pop(int pos);
    void display();
};

void List::push_front(int pos)
{
    Node* newNode= new Node(pos);
    if(head==NULL)
    {
        head=tail=newNode;
        return;
    }
    else
    {
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}

void List::push_back(int pos)
{
    Node* newNode= new Node(pos);
    if(head==NULL)
    {
        head=tail=newNode;
        return;
    }
    else
    {
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }
}

void List::insert(int val, int pos)
{
    if(pos<0)
    {
        cout<<"Invalid Position."<<endl;
        return;
    }
    else if(head==NULL)
    {
        push_back(val);
        return;
    }
    Node* newNode= new Node(val);
    Node* temp=head;
    int cnt=1;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==pos)
        {
            break;
        }
        temp=temp->next;
    }
    Node* newtemp=temp->next;
    newNode->next=newtemp;
    newtemp->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
}

void List::display()
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" <-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void List::pop_back()
{
    Node* temp=tail->prev;
    tail->prev=NULL;
    temp->next=NULL;
    delete tail;
    tail=temp;
}

void List:: pop_front()
{
    Node* temp=head->next;
    head->next=NULL;
    temp->prev=NULL;
    delete head;
    head=temp;
}

void List::pop(int pos)
{
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==pos)
        {
            break;
        }
        temp=temp->next;
    }
    Node* preNode=temp->prev;
    Node* postNode=temp->next;
    temp->next=NULL;
    temp->prev=NULL;
    preNode->next=postNode;
    postNode->prev=preNode;
    delete temp;
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
            obj.display();
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
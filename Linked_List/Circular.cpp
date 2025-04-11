#include<iostream>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node(int data)
    {
        val=data;
        next=NULL;
    }
};

class List
{
private:
    Node* head=NULL;
    Node* tail= NULL;
public:
    void push_back(int val);
    void push_front(int val);
    void insert(int val, int pos);
    void pop_back();
    void pop_front();
    void pop(int pos);
    void display();
};

void List::push_back(int val)
{
    Node* newNode= new Node(val);
    if(head==NULL)
    {
        head=tail=newNode;
        tail->next=head;
    }
    else
    {
        tail->next=newNode;
        tail=newNode;
        tail->next=head;
    }
}

void List::push_front(int val)
{
    Node* newNode= new Node(val);
    if(head==NULL)
    {
        head=tail=newNode;
        tail->next=head;
    }
    else
    {
        newNode->next=head;
        head=newNode;
        tail->next=head;
    }
}

void List::pop_front()
{
    if(head==NULL)
    {
        cout<<"Linked List is empty."<<endl;
        return;
    }
    else if(head==tail)
    {
        delete head;
        head=tail=NULL;
    }
    else
    {
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        tail->next=head;
    }
}

void List::pop_back()
{
    if(head==NULL)
    {
        cout<<"Linked List is empty."<<endl;
        return;
    }
    else if(head==tail)
    {
        delete head;
        head=tail=NULL;
    }
    else
    {
        Node* temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        tail->next=NULL;
        temp->next=head;
        delete tail;
        tail=temp;
    }
}

void List::display()
{
    Node* temp=head->next;
    cout<<head->val<<" -> ";
    while(temp!=head)
    {
        cout<<temp->val<<" -> ";
        temp=temp->next;
    }
    cout<<temp->val<<endl;
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
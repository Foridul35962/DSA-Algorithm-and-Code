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
    void middle_brute_force();
    void middle_fast_slow();
    void display();
};

void List::push(int val)
{
    Node* newNode= new Node(val);
    if (head==NULL)
    {
        head=tail=newNode;
    }
    else
    {
        tail->next=newNode;
        tail=newNode;
    }
}

void List::middle_brute_force()
{
    Node* temp=head;
    int cnt=0;
    int l=0;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
    }
    cnt=cnt/2;
    cnt++;
    temp=head;
    while(temp!=NULL)
    {
        l++;
        if(l==cnt)
        {
            cout<<"Middle_brute_force of Linked List is: "<<temp->data<<endl;
            break;
        }
        temp=temp->next;
    }
}

void List::middle_fast_slow()
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"Middle of Linked List: "<<slow->data<<endl;
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

int main()
{
    List obj;
    while(1)
    {
        int n;
        cout<<"What do you want:"<<endl;
        cout<<"1. push data."<<endl;
        cout<<"2. Display all data"<<endl;
        cout<<"3. Middle_brute_force of data"<<endl;
        cout<<"4. Middle_fast_slow of data"<<endl;
        cout<<"5. Exit"<<endl;
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
            obj.middle_brute_force();
        else if(n==4)
            obj.middle_fast_slow();
        else if(n==5)
            break;
    }
    return 0;
}
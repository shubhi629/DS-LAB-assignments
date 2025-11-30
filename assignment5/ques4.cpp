#include<iostream>
using namespace std;

class node{
    public:
int data;
node* next;

node(int value){
    data=value;
next = NULL;
}
};

class list{
    public:
node* head;
node* tail;
int count=0;
list(){
    head=tail=NULL;
}

void push(int value){
    node* newnode= new node(value);

    if(head==NULL){
        head=tail=newnode;

    }
    else{
    newnode->next = head;
    head=newnode;
}
count++;
}

void print(){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void reverse(){
    node*  prev = NULL;
    node* curr=head;
    node* next = NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

    }
    head=prev;
}
};

int main(){
list l;
l.push(5);
l.push(8);
l.push(9);
l.print();

l.reverse();
l.print();
}
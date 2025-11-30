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
int middle(){
    int x = count%2 ;

    node* temp = head;
    for(int i =0;i<x;i++){
        temp = temp->next;
    }

    cout<<"middle node = "<<temp->data<<endl;
}

void print(){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
};

int main(){
list l;
l.push(5);
l.push(8);
l.push(9);
l.print();
l.middle();
}
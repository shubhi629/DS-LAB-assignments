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
int del(int key){
int count=0;

while(head != NULL && head->data==key ){
    node* temp = head;
    head=head->next;
    delete temp;
    count++;
}

node* curr=head;
node* prev = NULL;

while(curr!=NULL){
    if(curr->data==key){
        prev->next=curr->next;
        delete curr;
        curr=prev->next;
        count++;
    }else{
        prev=curr;
        curr=curr->next;
    }
}
return count;
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
l.push(1);
l.push(2);
l.push(1);
l.push(3);
l.push(1);
l.push(4);
l.push(1);
l.push(2);
l.print();
l.del(1);
l.print();
}
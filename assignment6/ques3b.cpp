#include<iostream>
using namespace std;

struct node{
    int data;
    node* prev;
    node* next;

    node(int val){
        data=val;
        prev=next=nullptr;
    }
};

class doublylinkedlist{
    node*head;

    public:
    doublylinkedlist(){
        head=nullptr;
    }

    void createnode(int val){
        node* newnode=new node(val);
        if(head==NULL){
            head=newnode;
            return ;
        }
        node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
    }

    int sizeoflist(){
        int count=0;
        if(head==NULL){
            cout<<"list is empty\n";
            return 0;
        }
        node*temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
};

int main(){
    doublylinkedlist dll;
    dll.createnode(10);
    dll.createnode(20);
    dll.createnode(30);
    dll.createnode(40);
    dll.createnode(50);

    cout<<"size of doubly linked list is: "<<dll.sizeoflist();

    return 0;
}
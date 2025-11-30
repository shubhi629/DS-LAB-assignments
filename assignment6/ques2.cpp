#include<iostream>
using namespace std;

struct node{
    int data;
    node*next;

    node(int val){
        data=val;
        next=nullptr;
    }
};
class circularlinkedlist{
    node*head;

    public:
    circularlinkedlist(){
        head=nullptr;
    }
    //insert at the end
    void insert(int val){
        node*newnode=new node(val);
        //if nodes are not present
        if(head==nullptr){
            head=newnode;
            newnode->next=head;
            return;
        }
        node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }

    void display(){
        if(head==nullptr){
            cout<<"list is empty\n";
            return;
        }
        node*temp=head;
       do{
        cout<<temp->data<<"->";
        temp=temp->next;
       }while(temp!=head);
       
        cout<<head->data<<endl;
    }
};

int main(){
    circularlinkedlist list;
  list.insert(20);
    list.insert(100);
    list.insert(40);
    list.insert(80);
    list.insert(60);

    cout<<"circular linked list: ";
    list.display();
    return 0;
}
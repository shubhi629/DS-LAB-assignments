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
class linkedlist{
    node*head;

    public:
    linkedlist(){
        head=nullptr;
    }
    //insert at the end
    void insert(int val){
        node*newnode=new node(val);
        //if nodes are not present
        if(head==nullptr){
            head=newnode;
            return;
        }
        node*temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newnode;
    }

    bool iscircular(){
        if(head==nullptr) return false;

        node*slow=head;
        node*fast=head;

        while(fast!=nullptr &&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){ //cycle detected
                return true;
            }
        }
        return false;//no cycle
    }

    void display(){
        node*temp=head;
        while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
       }
       cout<<"NULL\n";
    }
};

int main(){
    linkedlist list;
    int n;
    cout<<"enter no of nodes: ";
    cin>>n;

    cout<<"enter "<<n<<"values: ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        list.insert(val);
    }
    

    if(list.iscircular()){
        cout<<"list is circular\n";
    }
    else{
        cout<<"list is not circular\n";
        cout<<"linked list: ";
        list.display();
    }
    return 0;
}
#include<iostream>
using namespace std;

//node structure
struct node{
    int data;
    node* next;

    //constructor
    node(int val){
        data=val;
        next=nullptr;
    }
};

//singlylinkedlist
class singlylinkedlist{
    node*head;

    public:
    //constructor
    singlylinkedlist(){
        head=nullptr;
    }

    //a.insert at beginning
    void push_front(int val){
        node*newnode=new node(val);
        newnode->next=head;
        head=newnode;
    }

    //b.insert at last
    void push_back(int val){
        node* newnode=new node(val);
        if(!head) {//linked list is empty
            head=newnode;
            return;
        }
        node*temp=head;
        while(temp->next){//till temp->next is not null
            temp=temp->next;
        }
        temp->next=newnode;
    }

    //c.insert a newnode before/after a specific node value
    void insertbefore(int key,int val){
        if(!head){
            cout<<"list is empty\n";
            return;
        }
        if(head->data==key){//insert before first node
            push_front(val); 
            return;
        }
        node* temp=head;
        while(temp->next!=NULL && temp->next->data!=key){
            temp=temp->next;
        }
        if(temp->next==nullptr){
            cout<<"node"<<key<<"is not found\n";
            return;
        }

        node*newnode=new node(val);
        newnode->next=temp->next;
        temp->next=newnode;
    }

    //insert after the key
    void insertafter(int key,int val){
         if(!head){
            cout<<"node"<<key <<" is not found\n";
            return;
        }
        node*temp=head;
        while(temp&&temp->data!=key){
            temp=temp->next;
        }

        node* newnode=new node(val);
        newnode->next=temp->next;
        temp->next=newnode;
    }
    //d.
    void pop_front(){
        if(!head){
            cout<<"list is empty\n";
            return;
        }
        node*temp=head;
        head=head->next;
        delete temp;
    }

    //e.
    void pop_back(){
        if(!head){ //no node 
            cout<<"list is empty\n";
            return;
        }
        if(!head->next){//only head is present
            delete head;
            head=nullptr;
            return;
        }
        node*temp=head;
        while(temp->next->next){//since we have to delete temp->next so we will check condition until temp->next->next exists
            temp=temp->next;
        }
        delete temp->next;
        temp->next=nullptr;
    }

    //f.delete node at a specific node
    void deletenode(int key){
        if(!head){
            cout<<"list is empty\n";
            return;
        }
        if(head->data==key){
            pop_front();
            return;
        }
        node*temp=head;
        while(temp->next&&temp->next->data!=key){
            temp=temp->next;
        }
        if(!temp->next){
            cout<<"node"<<key<<"is not found\n";
            return;
        }
        node* del=temp->next;
        temp->next=temp->next->next;
        delete del;
    }

    //g.search  a specific node
    void search(int key){
        node*temp=head;
        int pos=1;
        
        bool found=false;
        while(temp){//temp!=NULL
            if(temp->data==key){
                cout<<"node"<<key<<"found at pos"<<pos<<endl;
                found=true;
                break;
            }
            temp=temp->next;
            pos++;
        }
        if(!found){
            cout<<"node"<<key<<"not found\n";
        }
    }
    //h.display
    void display(){
        if(!head){
            cout<<"list is empty\n";
        }
        node*temp=head;
        while(temp){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
};

int main(){
    singlylinkedlist list;
    int val,choice,key;

    do{
        cout << "\n------ MENU ------\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.push_front(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.push_back(val);
                break;
            case 3:
                cout << "Enter key (before which to insert): ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                list.insertbefore(key, val);
                break;
            case 4:
                cout << "Enter key (after which to insert): ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                list.insertafter(key, val);
                break;
            case 5:
                list.pop_front();
                break;
            case 6:
                list.pop_back();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> val;
                list.deletenode(val);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> val;
                list.search(val);
                break;
            case 9:
                list.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

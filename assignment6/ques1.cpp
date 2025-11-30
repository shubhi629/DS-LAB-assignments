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

    void insertbeginning(int val){
        node*newnode=new node(val);
        if(!head){
            head=newnode;
            newnode->next=head;
            return;
        }

        //if the nodes are already present
        node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newnode->next=head;
            temp->next=newnode;
            head=newnode;
    }

    void insertend(int val){
        node*newnode=new node(val);
       if(!head){
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

    void insertafter(int key,int val){
        if(!head){
            cout<<"list is empty\n";
            return;
        } 
        node*temp=head;
       do
       {
            if(temp->data==key){
                node*newnode=new node(val);
                newnode->next=temp->next;
                temp->next=newnode;
                return;
            }
            temp=temp->next;
       } while (temp!=head);
       cout<<"node"<<key<<"is not found"<<endl;
    }

    void insertbefore(int key,int val){
        if(!head){
           cout<<"list is empty\n";
            return;
        } 

        
        node*temp=head;
        if(temp->data==key){
            insertbeginning(val);
            return;
        }
        do{
            if(temp->next->data==key){
                node*newnode=new node(val);
                newnode->next=temp->next;
                temp->next=newnode;
                return;
            }
            temp=temp->next;
        }while (temp!=head);
       cout<<"node"<<key<<"is not found"<<endl;
    }

    //delete at a specific node
    void deletenode(int key){
        //deleting head node
        if(head->data == key){
    if(head->next == head){ delete head; head = nullptr; return; }
    node* temp = head;
    while(temp->next != head) temp = temp->next;    // find last
    temp->next = head->next;                        // last->next = second
    node* del = head;
    head = head->next;                              // new head = second
    delete del;
    return;
}

        //deleting the non head node
       node* temp = head;
        while (temp->next != head && temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == head) {
            cout << "Node " << key << " not found\n";
            return;
        }

        node* del = temp->next;
        temp->next = del->next;
        delete del;
    }     


    void search(int key){
        if(!head){
            cout<<"list is empty\n";
            return;
        }
        node*temp=head;
        int pos=1;
        do{
            if(temp->data==key){
                cout<<"node "<<key<<"found at position "<<pos<<endl;
            return ;
            }
            temp=temp->next;
            pos++;
        }while(temp!=head);
        cout<<"node"<<key<<"is not found\n";
    }

    void display(){
      if(!head){
            cout<<"list is empty\n";
            return;
        }
        node*temp=head;
        do{
            cout<<temp->data<<"->";
            temp=temp->next;
        }  while(temp!=head);
        cout<<"(back to head)"<<endl;
    }
};

int main(){
    circularlinkedlist cll;
    int choice,val,key;

    do {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Node\n";
        cout << "4. Insert Before a Node\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search a Node\n";
        cout << "7. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                cll.insertbeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                cll.insertend(val);
                break;
            case 3:
                cout << "Enter key (after which to insert): ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                cll.insertafter(key, val);
                break;
            case 4:
                cout << "Enter key (before which to insert): ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                cll.insertbefore(key, val);
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> key;
                cll.deletenode(key);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> key;
                cll.search(key);
                break;
            case 7:
                cll.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

#include<iostream>
using namespace std;
class queue{
int arr[100];
int front , rear;

public:
queue(){
    front=rear=-1;
}

void equeue(int x){
    if(rear==99){
        cout<<"the queue is full ";
    }
    else if(front==-1){
        front= rear=0;
    }else{
       rear++;
    }

    arr[rear]=x;
}

void dequeu(){
    if(front == rear ){
        cout<<"the queue is empty ";
    }
    else{
        front++;
    }
}

void print(){
    if(front == -1||  front > rear){
        cout<<"the queue is full";
    }else{
        for(int i =front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

};

int main(){
queue q;
q.equeue(4);
q.equeue(7);
q.equeue(8);
q.dequeu();
q.equeue(0);
q.equeue(1);
q.equeue(3);
q.equeue(99);
q.dequeu();
q.print();
}
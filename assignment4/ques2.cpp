#include<iostream>
using namespace std;
class queue{
int arr[10];
int front , rear;

public:
queue(){
    front=rear=-1;
}

bool isfull(){
    return ((front ==0 && rear == 9)|| (front == rear +1));
}

bool isempty(){
    return (front== -1);
}

void enqueue(int x){
    if(isfull()){
        cout<<"cant add the number ";
    }else if(front == -1){
        front = 0;
        rear=0;
    }else if(rear == 9 && front != 0){
        rear =0;
    }else{
        rear++;
       
    }
     arr[rear]=x;

}

void dequeue(){
    if(isempty()){
        cout<<"cant remove as it is empty ";
    }
    else if(front==rear){
        front =-1;
        rear = -1;
    }else if(front == 9){
        front = 0;
    }
    else{
        front++;
    }
}

void print(){
    if(front == -1){
        cout<<"queue is empty ";
    }
           if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else { // circular case
            for (int i = front; i < 10; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

};

int main(){
queue q;
q.enqueue(5);
q.enqueue(6);
q.enqueue(7);
q.enqueue(8);

q.enqueue(9);

q.enqueue(10);
q.enqueue(11);
q.enqueue(12);
q.enqueue(13);
q.enqueue(14);
q.print();

}

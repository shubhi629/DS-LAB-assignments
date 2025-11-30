#include<iostream>
using namespace std;
typedef struct{
int element[100];
int top;
}stack;

stack init(){
    stack s;
    s.top=-1;
    return s;
}

int isfull(stack s){
    return (s.top == 99);
}

int isempty(stack s){
    return (s.top == -1);
}

void push(stack &s , int n){
    if(isfull(s)){
        cout<<"the stack is full";
    }else{
        s.element[++s.top]=n;
    }
}

void pop(stack &s){
    if(isempty(s)){
        cout<<"the stock is  empty";
    }else{
        --s.top;
    }
}

void print(stack &s){
    if(isempty(s)){
        cout<<"is empty";
    }
    else{
        for(int i =s.top;i>=0;i--){
            cout<<s.element[i]<<" ";
        }
    }
}

int main(){
    stack s=init();
    push(s,6);
        push(s,3);
            push(s,1);
                push(s,7);
                    push(s,8);
                    cout<<"STACK BEFORE POPING"<<endl;

                    print(s);
cout<<endl;
                    pop(s);
                    cout<<"STACK AFTER ONE REMOVAL";
                    print(s);
           cout<<endl;
                    pop(s);
                    pop(s);
                    push(s,0);
                    cout<<"end mein stack";
                    print(s);

}
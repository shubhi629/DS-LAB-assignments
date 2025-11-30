#include<iostream>
using namespace std;

typedef struct{
char element[100];
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

void push(stack &s , char n){
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
            cout<<s.element[i];
        }
    }
}

int main(){
stack s=init();
push(s,'d');
push(s,'a');
push(s,'t');
push(s,'a');
push(s,'s');
push(s,'t');
push(s,'r');
push(s,'u');
push(s,'c');
push(s,'t');
push(s,'r');
push(s,'e');
print(s);
}
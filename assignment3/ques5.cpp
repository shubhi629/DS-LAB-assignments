#include<iostream>
using namespace std;
#include<string>
class stack{
int top;
int arr[100];

public:
stack(){
    top=-1;
}

void push(int x){
    if(top==99){
        cout<<"it is full";
    }else{
        arr[++top]=x;
    }
}

int pop(){
    if(top == -1){
        cout<<"stack is full ";
        return -1;
    }else{
        return arr[top--];
    }
}

int value(){
    return arr[top];
}
};

int evaluate(string expr){
    stack s;
    for(int i =0;i<expr.length();i++){
        char c = expr[i];

        if(c==' '){
            continue;
        }else if(isdigit(c)){
          s.push(c-'0');
        }else{
            int a = s.pop();
            int b=s.pop();

            cout<<"A = "<<a<<" B = "<<b<<endl;
switch(c){
case '+' : s.push(b+a); break;
case '-' : s.push(b-a); break;
case '*' : s.push(b*a); break;
case '/' : s.push(b/a); break;
}

        }
    }
    return s.value();
}

int main(){
    string ex;
    cout<<"enter the string : ";
  getline(cin,ex);

    cout<<"the ans is = "<<evaluate(ex)<<endl;
}
// #include<iostream>
// using namespace std;
// #include<stack>
// #include<queue>

// class mystack{
// queue<int> q1,q2;
// public:
// void push(int x){
// q2.push(x);
// while(!q1.empty()){
//     q2.push(q1.front());
//     q1.pop();
// } 

// swap(q1,q2);
// }

// int pop(){
//     int ans = q1.front();
//     q1.pop();
//     return ans;
// }

// int peek(){
//     return q1.front();
// }

// bool empty(){
//     return q1.empty();
// }
// };

// int main(){
// mystack s;
// s.push(6);
// s.push(5);
// s.push(4);
// s.push(3);
// s.push(1);

// while(!s.empty()){
//     cout<<s.pop()<<" ";
// }
// }

// #include<iostream>
// using namespace std;
// #include<stack>
// #include<queue>

// class mystack{
// queue<int> q;
// public:
// void push(int x){
//     q.push(x);

//     int size = q.size();

//     for(int i =0;i<size-1;i++){
//         q.push(q.front());
//         q.pop();
//     }
// }

// int pop(){
//     int ans=q.front();
//     q.pop();
//     return ans;
// }

// int peek (){
//     return q.front();
// }

// bool empty(){
//     return q.empty();
// }
// };

// int main(){
// mystack s;
// s.push(5);
// s.push(4);
// s.push(3);
// s.push(2);
// s.push(1);


// while(!s.empty()){
// cout<<s.pop()<<" ";
// }
// }


#include<iostream>
using namespace std;
#include<queue>
#include<stack>

class mystack{
queue <int> q1;
public:

void push(int x){
    q1.push(x);
int s = q1.size();

for(int i =0;i<s-1;i++){
    q1.push(q1.front());
    q1.pop();
}
}

int pop(){
    int ans=q1.front();
    q1.pop();
    return ans;
}

int peek(){
    return q1.front();

}

int empty(){
    return q1.empty();
}
};

int main(){
   mystack s1;
   s1.push(4);
   s1.push(7);
   s1.push(0);
   s1.pop();
   s1.push(1);

   while(!s1.empty()){
    cout<<s1.pop()<<" ";
   }
}
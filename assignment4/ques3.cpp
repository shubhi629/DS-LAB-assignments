#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void interleavequeue(queue<int> &q){  
    if(q.size() %2 !=0 ){
        cout<<"the wrong size is added "<<endl;
        return ;
    }

    int halfsize = q.size()/2;

    stack <int> s;

    for (int i =0;i<halfsize;i++){   // putting first part of the queue in the stock
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){          // elements ko vapis queue mein but in reverse order
        q.push(s.top());
        s.pop();
    }

    for(int i =0;i<halfsize;i++){   // enqueue the 2nd part of the queue
        q.push(q.front());
        q.pop();
    }

    for(int i =0;i<halfsize;i++){    // put the first half in the queue
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){            //Interleave elements from the stack and queue
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

void print(queue <int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    cout<<endl;
}

int main(){
    queue <int> q;
    q.push(4);
     q.push(7);
      q.push(11);
       q.push(20);
        q.push(5);
         q.push(9);

         cout<<" ORIGINAL QUEUE"<<endl;
         print(q);

         interleavequeue(q);
         cout<<"INTERLEAVE QUEUE : "<<endl;
         print(q);

}
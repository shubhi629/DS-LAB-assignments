#include<iostream>
#include<vector>
using namespace std;
#include<list>
#include<queue>

class graph{
    public:
int v;
list<int> *l;

graph(int v){
    this->v=v;
    l=new list<int>[v];
}

void add(int u , int v){
l[u].push_back(v);
l[v].push_back(u);
}

void print(){
    for(int i =0;i<v;i++){
        cout<<i<<" -> ";

        for(int n : l[i]){
            cout<<n<<" ";
        }
        cout<<endl;
    }
}

void breadth_first_search(){
    queue<int> q;
    vector<bool> vis(v,false);
    q.push(0);
    vis[0]=true;

    while(q.size()>0){
        int u = q.front();
        q.pop();
        cout<<u<<" ";

        for(int v : l[u]){
            if(!vis[v]){
                vis[v]=true;
                q.push(v);
            }
        }
    }
    cout<<endl;
}
};
int main(){
    graph g(4);
    g.add(0, 1);
    g.add(1, 2);
    g.add(1, 3);
    g.add(2, 3);

    g.print();
cout<<"Breadth First Search : "<<endl;
    g.breadth_first_search();
}
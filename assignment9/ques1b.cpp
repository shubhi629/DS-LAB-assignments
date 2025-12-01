#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class graph{
public:
    int v;
    list<int> *l;

    graph(int v){
        this->v = v;
        l = new list<int>[v];
    }

    void add(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int i = 0; i < v; i++){
            cout << i << " -> ";
            for(int n : l[i]){
                cout << n << " ";
            }
            cout << endl;
        }
    }

    void dfs_helper(int u, vector<int> &vis){
        cout << u << " ";
        vis[u] = true;

        for(int nbr : l[u]){
            if(!vis[nbr]){
                dfs_helper(nbr, vis);
            }
        }
    }

    void dfs(){
        int source = 0;
        vector<int> vis(v, false);
        dfs_helper(source, vis);
    }
};

int main(){
    graph g(7);

    g.add(0, 1);
    g.add(1, 3);
    g.add(1, 2);
    g.add(2, 5);
    g.add(4, 5);
    g.add(4, 6);
    g.add(5, 6);
    g.add(1, 4);

    g.print();

    cout << "Depth First Search : ";
    g.dfs();
}
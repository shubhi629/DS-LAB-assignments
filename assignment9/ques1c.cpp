

#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class graph{
public:
    int v;
    list<pair<int,int>> *l;

    graph(int v){
        this->v = v;
        l = new list<pair<int,int>>[v];
    }

    void add(int u, int v, int w){
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }

    void print(){
        for(int i = 0; i < v; i++){
            cout << i << " -> ";
            for(auto n : l[i]){
                cout << "(" << n.first << "," << n.second << ") ";
            }
            cout << endl;
        }
    }

    void prims(int src){
        vector<bool> isMST(v, false);
        vector<int> parent(v, -1);
        int cost = 0;

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({0, {src, -1}});

        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int par = pq.top().second.second;
            pq.pop();

            if(isMST[node]) continue;

            isMST[node] = true;
            cost += wt;
            parent[node] = par;

            for(auto nbrPair : l[node]){
                int nbr = nbrPair.first;
                int w = nbrPair.second;

                if(!isMST[nbr]){
                    pq.push({w, {nbr, node}});
                }
            }
        }

        cout << "\nEdges in MST:\n";
        for(int i = 0; i < v; i++){
            if(parent[i] != -1){
                cout << parent[i] << " - " << i << endl;
            }
        }

        cout << "Total cost = " << cost << endl;
    }
};

int main(){
    graph g(7);

    g.add(0, 1, 4);
    g.add(0, 2, 3);
    g.add(1, 2, 1);
    g.add(1, 3, 2);
    g.add(2, 3, 4);
    g.add(3, 4, 2);
    g.add(4, 5, 6);
    g.add(5, 6, 3);
    g.add(4, 6, 1);

    g.print();

    cout << "\nPrim's Algorithm:\n";
    g.prims(0);

    return 0;
}
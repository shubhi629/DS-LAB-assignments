#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            if (rank[a] < rank[b]) parent[a] = b;
            else if (rank[b] < rank[a]) parent[b] = a;
            else {
                parent[b] = a;
                rank[a]++;
            }
        }
    }
};

class graph {
public:
    int v;
    vector<vector<int>> edges; // {wt, u, v}

    graph(int v) {
        this->v = v;
    }

    void addEdge(int u, int v, int wt) {
        edges.push_back({wt, u, v});
    }

    void kruskal() {
        sort(edges.begin(), edges.end()); // sort by wt

        DSU dsu(v);
        int totalWeight = 0;

        cout << "Edges in MST (Kruskal):\n";

        for (auto e : edges) {
            int wt = e[0];
            int u = e[1];
            int v = e[2];

            if (dsu.find(u) != dsu.find(v)) {
                dsu.unite(u, v);
                totalWeight += wt;

                cout << u << " -- " << v << " (wt = " << wt << ")\n";
            }
        }

        cout << "Total Weight of MST = " << totalWeight << endl;
    }
};

int main() {
    graph g(6);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, 3);

    g.kruskal();
}
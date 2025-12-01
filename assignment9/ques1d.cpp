#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// -----------------------------
// GRAPH CLASS
// -----------------------------
class Graph {
public:
    int V; // number of vertices
    vector<vector<pair<int,int>>> adj; 
    // each element: {neighbor, weight}

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add edge (u -> v with weight w)
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // undirected graph
    }

    // -----------------------------
    // DIJKSTRA ALGORITHM
    // -----------------------------
    void dijkstra(int src) {
        // Distance array → initialize with infinity
        vector<int> dist(V, 1e9);

        // Min Heap (priority_queue)
        // Stores: {distance, node}
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src}); // {distance, source}

        while (!pq.empty()) {
            int currDist = pq.top().first;  // smallest dist
            int node = pq.top().second;
            pq.pop();

            // If we already found a shorter path, skip
            if (currDist > dist[node]) continue;

            // Check all neighbors
            for (auto edge : adj[node]) {
                int nbr = edge.first;
                int wt = edge.second;

                // relax the edge
                if (dist[node] + wt < dist[nbr]) {
                    dist[nbr] = dist[node] + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        // Print final shortest distances
        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " → " << dist[i] << endl;
        }
    }
};

// -----------------------------
// MAIN FUNCTION
// -----------------------------
int main() {
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.dijkstra(0); // source node = 0
}
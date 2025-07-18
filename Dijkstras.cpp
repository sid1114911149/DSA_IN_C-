#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int n, vector<vector<pii>> &adj, int src) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();
        if (currentDist > dist[u]) continue;

        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "To node " << i << " => ";
        if (dist[i] == INT_MAX)
            cout << "Unreachable\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<pii>> adj(n); 

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    dijkstra(n, adj, source);

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii; // (weight, vertex)

void primsAlgorithm(int n, vector<vector<pii>> &adj) {
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;
            int wt = it.second;

            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;
    cout << "Edges in MST:\n";
    for (int v = 1; v < n; ++v) {
        cout << parent[v] << " - " << v << " (Weight: " << key[v] << ")\n";
        totalWeight += key[v];
    }
    cout << "Total Weight of MST: " << totalWeight << endl;
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
        adj[v].push_back({u, wt});
    }

    primsAlgorithm(n, adj);
    return 0;
}

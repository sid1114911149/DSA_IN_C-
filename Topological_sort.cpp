#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<int> topoSortKahn(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u])
            indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    if (topo.size() != V) {
        cout << "Graph has a cycle!" << endl;
        return {};
    }

    return topo;
}
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int v : adj[node]) {
        if (!visited[v])
            dfs(v, adj, visited, st);
    }
    st.push(node);
}

vector<int> topoSortDFS(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i, adj, visited, st);
    }

    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    // Using DFS
    vector<int> result = topoSortDFS(V, adj);
    cout << "Topological Sort (DFS): ";
    for (int x : result) cout << x << " ";
    cout << endl;

    // Using Kahn's BFS
    vector<int> resultBFS = topoSortKahn(V, adj);
    cout << "Topological Sort (BFS/Kahn): ";
    for (int x : resultBFS) cout << x << " ";
    cout << endl;

    return 0;
}

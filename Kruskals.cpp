#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, wt;
    Edge(int _u, int _v, int _wt) : u(_u), v(_v), wt(_wt) {}
};
bool compare(Edge a, Edge b) {
    return a.wt < b.wt;
}

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) return false;

        if(rank[px] < rank[py])
            parent[px] = py;
        else if(rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<Edge> edges;

    cout << "Enter edges (u v weight):\n";
    for(int i = 0; i < e; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.emplace_back(u, v, wt);
    }

    sort(edges.begin(), edges.end(), compare);

    DSU dsu(n);
    vector<Edge> mst;
    int totalWeight = 0;

    for(auto &edge : edges) {
        if(dsu.unite(edge.u, edge.v)) {
            mst.push_back(edge);
            totalWeight += edge.wt;
        }
    }

    cout << "\nEdges in Minimum Spanning Tree:\n";
    for(auto &edge : mst) {
        cout << edge.u << " - " << edge.v << " (Weight: " << edge.wt << ")\n";
    }

    cout << "Total Weight of MST: " << totalWeight << endl;
    return 0;
}

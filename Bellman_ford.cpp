#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    int n, e;
    vector<vector<int>> edges;
    cout << "Enter No of vertices, Edges: ";
    cin >> n >> e;

    int u, v, w, src;
    cout << "Enter Edges (start, dest, weight):" << endl;
    for(int i = 0; i < e; i++){
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    cout << "Enter Source: ";
    cin >> src;

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for(int i = 0; i < n - 1; i++){
        for(auto it : edges){
            u = it[0];
            v = it[1];
            w = it[2];
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    for(auto it : edges){
        u = it[0];
        v = it[1];
        w = it[2];
        if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
            cout << "Graph contains negative weight cycle" << endl;
            return 1;
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for(int i = 0; i < n; i++){
        if(dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}

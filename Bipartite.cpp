#include<iostream>
#include<vector>
using namespace std;

bool isBipartite(vector<vector<int>> &adj, vector<int> &color, int idx, int col) {
    if(color[idx] != -1) {
        return color[idx] == col;
    }
    color[idx] = col;
    col = col ^ 1;
    for(int i = 0; i < adj[idx].size(); i++) {
        if(!isBipartite(adj, color, adj[idx][i], col)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter no of Nodes in Graph: ";
    cin >> n;
    
    vector<vector<int>> adj(n); 
    
    for(int i = 1; i <= n; i++) {
        int ch, k;
        cout << "Enter No of children of " << i << ": ";
        cin >> ch;
        cout << "Enter values: ";
        for(int j = 0; j < ch; j++) {
            cin >> k;
            adj[i - 1].push_back(k);
        }
    }

    vector<int> color(n, -1);
    bool value = true;

    for(int i = 0; i < n; ++i) {
        if(color[i] == -1) {
            if(!isBipartite(adj, color, i, 0)) {
                value = false;
                break;
            }
        }
    }

    if(value) {
        cout << "Given graph is Bipartite..\n";
    } else {
        cout << "Given graph is NOT Bipartite..\n";
    }

    return 0;
}

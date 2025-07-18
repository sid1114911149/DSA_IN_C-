#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int inf = 1e9 + 7;
int main()
{
    int n, e;
    cout << "Enter No of Vertices,Edges:";
    cin >> n >> e;
    cout << "Enter Edges(start,dest,weight):";
    vector<vector<int>> edges;
    vector<vector<int>> adj(n, vector<int>(n, inf));
    int u, v, w;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u][v] = w;
        adj[v][u]=w;
    }
    for(int i=0;i<n;i++){
        adj[i][i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (adj[j][k] > adj[j][i] + adj[i][k])
                {
                    adj[j][k] = adj[j][i] + adj[i][k];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] != inf)
                cout << adj[i][j] << ' ';
            else
                cout << "inf" << ' ';
        }
        cout << endl;
    }
    return 0;
}
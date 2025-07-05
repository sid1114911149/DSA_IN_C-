#include <iostream>
#include <stack>
#include <queue>
using namespace std;
bool iscycle(vector<vector<int>> &adj, vector<bool> &st, vector<bool> &visited, int src)
{
    st[src] = true;
    if (!visited[src])
    {
        visited[src]=true;
        for (auto &it : adj[src])
        {
            if (!visited[it] && iscycle(adj, st, visited, it))
            {
                return true;
            }
            if(st[it]){
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n;
    cout << "Enter No of Nodes:";
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        int ch, k;
        cout << "Enter No of Neighbors of " << i << ":";
        cin >> ch;
        cout << "Enter Negihbors:";
        for (int j = 0; j < ch; j++)
        {
            cin >> k;
            adj[i].push_back(k);
        }
    }
    vector<bool> visited(n, false);
    vector<bool> st(n, false);
    bool cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && iscycle(adj, st, visited, i)){
            cycle=true;
        }
    }
    if(cycle){
        cout<<"Cycle is Present..\n";
    }else{
        cout<<"Cycle is not Present..\n";
    }
    return 0;
}
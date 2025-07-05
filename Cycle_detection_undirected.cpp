#include<iostream>
#include <stack>
#include <queue>
#include <stdlib.h>
using namespace std;
bool iscycle(vector<vector<int>> &adj,vector<bool> &visited,int parent,int src){
    visited[src]=true;
    for(auto &it:adj[src]){
        if(it!=parent){
            if(visited[it]){
                return true;
            }
            if(!visited[it] && iscycle(adj,visited,src,it)){
                visited[it]=true;
            }
        }
    }
    return false;
}
int main(){
    int n;
    cout<<"Enter No of Nodes:";
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        int ch,k;
        cout<<"Enter No of Negihbours of Node "<<i<<":";
        cin>>ch;
        cout<<"Enter neighbors:";
        for(int j=0;j<ch;j++){
            cin>>k;
            adj[i].push_back(k);
        }
    }
    vector<bool> visited(n,false);
    bool cycle=iscycle(adj,visited,0,0);
    if(cycle){
        cout<<"Cycle is Present..\n";
    }else{
        cout<<"Cycle is not Present..\n";
    }
    return 0;
}
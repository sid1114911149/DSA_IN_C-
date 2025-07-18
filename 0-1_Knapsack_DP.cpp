#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
vector<vector<int>> dp;
static bool compare(pair<int,int> &a,pair<int,int> &b){
    return a.first<b.first;
}
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int capacity,n;
    cout<<"Enter No of Items:";
    cin>>n;
    cout<<"Enter Capacity:";
    cin>>capacity;
    vector<int> wt(n),val(n);
    dp=vector<vector<int>>(n+1,vector<int>(capacity+1,-1));
    for(int i=0;i<n;i++){
        cout<<"Enter weight and Profit of the Item:";
        cin>>wt[i]>>val[i];
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=capacity;i++){
        dp[0][i]=0;
    }
   for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max( val[i - 1] + dp[i - 1][w - wt[i - 1]] , dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout<<dp[n][capacity]<<endl;
    return 0;
}
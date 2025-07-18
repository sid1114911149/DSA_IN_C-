#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
    string str1,str2;
    cout<<"Enter Strings:";
    cin>>str1>>str2;
    int n1=str1.size();
    int n2=str2.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=max(dp[i-1][j-1]+1,max(dp[i-1][j],dp[i][j-1]));
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<"Length of The Longest Common Subsequence is:"<<dp[n1][n2]<<endl;
    return 0;
}
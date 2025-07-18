#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the Array:";
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        nums[i]=rand()%1000;
    }
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    sort(dp.begin(),dp.end());
    cout<<"Given Array:";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }cout<<endl;
    cout<<"Length of the Longest Strictly Increasing Subsequence is:"<<dp[n-1];
    return 0;
}
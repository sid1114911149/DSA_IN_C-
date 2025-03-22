#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int longest_seq(vector<int> & v,int k){
    int n=v.size(),i=0,ans=0,zero_count=0;
    for(int j=0;j<n;j++){
        if(v[j]==0){
            zero_count++;
        }
        while(zero_count>k){
            if(v[i]==0)
                zero_count--;
            i++;    
        }
        ans=max(ans,j-i+1);
    }
    return ans;
}
int main(){
    vector<int> v={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k=3;
    int longest_subsequence=longest_seq(v,k);
    cout<<"Length of Longest subarray Containing Consecutive One's is:"<<longest_subsequence<<endl;
    return 0;
}
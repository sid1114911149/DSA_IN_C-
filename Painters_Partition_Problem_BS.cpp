#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
bool isfeasible(vector<int> &v, int mid, int m) {
    int painters = 1, partition = 0;
    for(int i = 0; i < v.size(); i++) {
        if (partition + v[i] > mid) { 
            painters++;
            partition = v[i]; 
            if (painters > m) return false; 
        } else {
            partition += v[i]; 
        }
    }
    return true;
}

int Minimum_Partitions(vector<int> &v,int m){
    int sum=0;
    int n=v.size();
    for(int i=0;i<n;i++){
        sum+=v[i];
    }
    int start=0,end=sum,mid,ans=INT_MAX;
    while(start<=end){
        mid=start+(end-start)/2;
        if(isfeasible(v,mid,m)){
            ans=min(ans,mid);
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> v={12,34,67,90};
    int m=2;
    cout<<Minimum_Partitions(v,m)<<endl;
    return 0;
}
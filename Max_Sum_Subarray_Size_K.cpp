#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> Max_sum_subaray(vector<int> &v,int k){
    vector<int> temp,temp2;
    int n=v.size(),sum=0,sum2=0,idx;
    if(n<k){
        cout<<"No Possible Subarray..\n";
        return temp;
    }
    for(int i=0;i<k;i++){
        temp.push_back(v[i]);
        temp2.push_back(v[i]);
        sum+=v[i];
    }
    sum2=sum,idx=k-1;
    for(int i=k;i<n;i++){
        sum2=sum2-v[i-k]+v[i];
        temp2.erase(temp2.begin());
        temp2.push_back(v[i]);
        if(sum2>sum){
            sum=sum2;
            temp=temp2;
        }
    }
    return temp;
}
int main(){
    vector<int> v={1,2,4,6,-3,8};
    int k=3;
    vector<int> temp=Max_sum_subaray(v,k);
    if(temp.size()>0){
        for(auto it:temp){
            cout<<it<<" ";
        }cout<<endl;
    }else{
        cout<<"NO subarray with  size "<<k<<endl;
    }    
    return 0;
}
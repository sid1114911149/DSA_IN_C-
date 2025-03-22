#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool two_pointer(vector<int> &v,int &idx,int &target){
    int i=0,n=v.size();
    int j=n-1;
    while(i<j){
        if(i==idx || v[i]+v[j]<target){
            i++;
        }else if(j==idx || v[i]+v[j]>target){
            j--;
        }else if(v[i]+v[j]==target){
            cout<<v[i]<<" "<<v[j]<<" ";
            return true;
        }
    }
    return false;
}
bool find_target_sum(vector<int> &v,int &target){
    int n=v.size(),newTarget;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        newTarget=target-v[i];
        if(two_pointer(v,i,newTarget)){
            cout<<v[i]<<" is the Reqiured set to generate Given sum "<<target<<endl;
            return true;
        }
    }
    return false;
}
int main(){
    vector<int> v={12,3,7,1,6,9};
    int target=24;
    if(!find_target_sum(v,target)){
        cout<<"There is no set to generate Given sum "<<target<<endl;
    }
    target=5;
    if(!find_target_sum(v,target)){
        cout<<"There is no set to generate Given sum "<<target<<endl;
    }
    return 0;
}
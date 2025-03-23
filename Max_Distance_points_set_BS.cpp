#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isFeasible(vector<int> &v,int mid,int k){
    int pos=v[0],elements=1;
    for(int i=1;i<v.size();i++){
        if(v[i]-pos>=mid){
            pos=v[i];
            elements++;
            if(elements==k){
                return true;
            }
        }
    }
    return false;
}
int find_set(vector<int> &v,int k){
    sort(v.begin(),v.end());
    int n=v.size(),result=-1;
    int left=1,right=v[n-1],mid;
    while(left<right){
        mid=(right+left)/2;
        if(isFeasible(v,mid,k)){
            result=max(result,mid);
            left=mid+1;
        }else{
            right=mid;
        }
    }
    return result;
}
int main(){
    vector<int> v={1,2,8,4,9};
    int k=3;
    cout<<"Larget Minimum Distance is:"<<find_set(v,k)<<endl;
    return 0;
}
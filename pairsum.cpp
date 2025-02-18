#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
vector<int> pairsum(int arr[],int target,int size){
    vector<int> v;
    int i=0,j=size-1,sum=0;
    while(i<j){
        sum=arr[i]+arr[j];
        if(sum==target){
            v.push_back(i);
            v.push_back(j);
            return v;
        }
        if(sum>target){
           j--;
        }
        if(sum<target){
           i++;
        }
    }
    return v;
}
int main(){
    int n=5,target=7;
    int arr[5]={1,2,3,-4,5};
    vector<int> v;
    v=pairsum(arr,target,n);
    cout<<"Pair of Elements in the given Array that produce the given target is:"<<v[0]<<" "<<v[1]<<endl;
    return 0;
}
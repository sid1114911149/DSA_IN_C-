#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;
int majority(int arr[],int size){
    int floor=size/2;
    int freq=1,ans=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]==arr[i-1]){
            freq++;
        }else{
            freq=1;
            ans=arr[i];
        }
        if(freq==floor){
            return ans;
        }
    }
    return ans;
}
int main(){
    int arr[6]={2,1,3,1,2,1};
    sort(arr,arr+6);
    cout<<"Majority Element in the Given Array is:"<<majority(arr,6)<<endl;
    return 0;
}
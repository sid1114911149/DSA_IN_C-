#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;
int majority(int arr[],int size){
    int freq=0,ans=0;
    for(int i=0;i<size;i++){
        if(freq==0){
           ans=arr[i];
        }
        if(ans==arr[i]){
            freq++;
        }else{
            freq--;
        }
    }
    return ans;
}
int main(){
    int arr[7]={2,2,1,1,1,2,2};
    cout<<"Majority Element in the Given Array is:"<<majority(arr,7)<<endl;
    return 0;
}
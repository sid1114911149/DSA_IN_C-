#include<iostream>
#include<limits.h>
using namespace std;
int main(){
    int n=5,sum=INT_MIN,currsum=0;
    int arr[5]={1,2,3,-4,5};
    for(int i=0;i<5;i++){
        currsum+=arr[i];
        if(currsum<0){
            currsum=0;
        }
        if(currsum>sum){
            sum=currsum;
        }
    }
    cout<<"Maximum subarray Sum of the Given Array is:"<<sum<<endl;
    return 0;
}
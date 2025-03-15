#include<iostream>
using namespace std;
int find_min_missing(int arr[],int n){
    int N=1e6+2;
    bool idx[N];
    for(int i=0;i<N;i++){
        idx[i]=false;
    }
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            idx[arr[i]]=true;
        }
    }
    int i=0;
    while(idx[i]==true){
        i++;
    }
    return i;
}
int main(){
    int arr[]={0,-9,1,3,2,5};
    int n=6;
    cout<<"First NON Negative Number Misiing is: "<<find_min_missing(arr,n)<<endl;
    return 0;
}
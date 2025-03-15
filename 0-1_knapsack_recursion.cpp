#include<iostream>
#include<string>
using namespace std;
int MaxProfit(int items[],int profit[],int capacity,int idx,int n){
    if(idx>= n || capacity<= 0 ){
        return 0;
    }
    int prof1;
    int prof2;
    if(items[idx]<=capacity){
        prof1=MaxProfit(items,profit,capacity-items[idx],idx+1,n)+profit[idx];
    }else{
        prof1=0;
    }
    prof2=MaxProfit(items,profit,capacity,idx+1,n);
    return (prof1>prof2)?prof1:prof2;
}
int main(){
    int n,capacity;
    cout<<"Enter no of items:";
    cin>>n;
    int items[n],profit[n];
    cout<<"Enter Weights of Each item:";
    for(int i=0;i<n;i++){
        cin>>items[i];
    }
    cout<<"Enter Profits of Each item:";
    for(int i=0;i<n;i++){
        cin>>profit[i];
    }
    cout<<"Enter Capacity :";
    cin>>capacity;
    cout<<"Maximum Profit can be Obtained using 0/1 Knapsack is:"<<MaxProfit(items,profit,capacity,0,n)<<endl;
    return 0;
}
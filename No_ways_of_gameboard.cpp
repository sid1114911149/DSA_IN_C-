#include<iostream>
#include<string>
using namespace std;
int count=0;
void solver(int idx,int n,int m){
    if(idx>n){
        return;
    }
    if(idx==n){
        count++;
        return ;
    }
    //maximum no of steps can be taken is 3
    for(int i=1;i<=m;i++){
        solver(idx+i,n,m);
    }
    return ;
}
int main(){
    int n,m;
    cout<<"Enter the Size of the board:";
    cin>>n;
    cout<<"Enter maximum no of steps can be taken in each step:";
    cin>>m;
    solver(0,n,m);
    cout<<"Total no of ways to solve the board is:"<<count<<endl;
    return 0;
}
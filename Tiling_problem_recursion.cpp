#include<iostream>
#include<string>
using namespace std;
int solver(int n,int m){
    if(m==0){
        return 0;
    }if(m==1){
        return 1;
    }
    return solver(n,m-1)+solver(n,m-2);
}
int main(){
    int n,m;
    cout<<"Enter the N and M:";
    cin>>n>>m;
    cout<<"total no of ways to place the tiles in the Space is: "<<solver(n,m)<<endl;
    return 0;
}
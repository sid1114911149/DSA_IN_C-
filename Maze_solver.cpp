#include<iostream>
#include<string>
using namespace std;
int solver(int n,int i,int j){
    if(i>=n || j>=n){
        return 0;
    }
    if(i==n-1 && j== n-1){
        return 1 ;
    }
    return solver(n,i+1,j)+solver(n,i,j+1);
}
int main(){
    int n;
    cout<<"Enter the size of the maze:";
    cin>>n;
    cout<<"total no of ways to solve the given Maze is: "<<solver(n,0,0)<<endl;
    return 0;
}

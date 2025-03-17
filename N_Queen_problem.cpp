#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool issafe(vector<vector<int>>& board,int c,int r,int n){
    for(int i=0;i<n;i++){
        if(board[i][c]==1 || board[r][i]==1){
            return false;
        }
    }
    int i=r,j=c;
    while(i>=0 && i<n && j>=0 &&j<n){
        if(board[i][j]==1)
            return false;
        i+=1;
        j+=1;    
    }
    i=r,j=c;
    while(i>=0 && i<n && j>=0 &&j<n){
        if(board[i][j]==1)
            return false;
        i-=1;
        j-=1;    
    }
    i=r,j=c;
    while(i>=0 && i<n && j>=0 &&j<n){
        if(board[i][j]==1)
            return false;
        i+=1;
        j-=1;    
    }
    i=r,j=c;
    while(i>=0 && i<n && j>=0 &&j<n){
        if(board[i][j]==1)
            return false;
        i-=1;
        j+=1;    
    }
    return true;
}
bool Place_queens(vector<vector<int>>& board,int c,int n){
    if(c==n){
       for(int i=0;i<n;i++){
            cout<<"|";
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<"|";
            }
            cout<<endl;
       }
       return true;
    }
    for(int i=0;i<n;i++){
        if(issafe(board,c,i,n)){
            board[i][c]=1;
            if(Place_queens(board,c+1,n)){
                return true;
            }else{
                board[i][c]=0;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cout<<"Enter Size of the Board:";
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));
    Place_queens(board,0,n);
    return 0;
}
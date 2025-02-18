#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter value of n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"  ";
        }
        cout<<"*";
        if(i==1){
            cout<<endl;
            continue;
        }    
        for(int j=1;j<=4*i-5;j++){
            cout<<" ";
        }
        cout<<"*";
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=0;j<n-i;j++){
            cout<<"  ";
        }
        cout<<"*";
        if(i==1){
            cout<<endl;
            continue;
        }    
        for(int j=1;j<=4*i-5;j++){
            cout<<" ";
        }
        cout<<"*";
        cout<<endl;
    }
    return 0;
}
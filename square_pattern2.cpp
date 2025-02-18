#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter value of n:";
    cin>>n;
    for(int i=1;i<=n*n;i+=n){
        for(int j=0;j<n;j++){
            cout<<j+i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
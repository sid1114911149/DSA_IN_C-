#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter value of n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            cout<<"  ";
        }
        for(int j=i;j<=n;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
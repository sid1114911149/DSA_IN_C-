#include<iostream>
using namespace std;
int solver(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }
    return solver(n-1)+(n-1)*solver(n-2);
}
int main(){
    int n;
    cout<<"Enter Total no of People:";
    cin>>n;
    cout<<"Total no of Ways to Pair up the Give n Guests is : "<<solver(n)<<endl;
    return 0;
}
#include<iostream>
#include<string>
using namespace std;
void reverse(string str,int idx){
    if(idx>str.size()/2){
        cout<<str<<endl;
        return ;
    }
    int n=str.size();
    char ch=str[idx];
    str[idx]=str[n-idx-1];
    str[n-idx-1]=ch;
    reverse(str,idx+1);
    return ;
}
int main(){
    reverse("siddardha",0);
    return 0;
}
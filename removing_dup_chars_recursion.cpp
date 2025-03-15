#include<iostream>
#include<string>
using namespace std;
string remove(string str,int idx,int n){
    if(idx==n){
        return " ";
    }
    char ch=str[idx];
    string newstr=remove(str,idx+1,n);
    if(ch==newstr[0]){
        return newstr;
    }else{
        return ch+newstr;
    }
}
int main(){
    cout<<remove("aaaabbbeeecdddd",0,15)<<endl;
    return 0;
}

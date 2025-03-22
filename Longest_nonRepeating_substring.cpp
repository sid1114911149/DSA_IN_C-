#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int Max(int a,int b){
    return a>b?a:b;
}
int longest_sub(string &str){
    int n=str.size(),currmax=0,max=0;
    vector<bool> v(256,false);
    for(int i=0;i<n;i++){
        if(!v[str[i]-'0']){
            currmax++;
            v[str[i]-'0']=true;
        }else{
            currmax=1;
        }
        max=Max(currmax,max);
    }
    return max;
}
int main(){
    string str="abcabcbb";
    cout<<"Length of the Longest Substring Without repeating Character in "<<str<<" is:"<<longest_sub(str);
    return 0;
}
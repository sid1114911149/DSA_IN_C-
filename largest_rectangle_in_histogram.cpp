#include<iostream>
#include<stack>
#include<vector>
#include<stdlib.h>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}
long long int find_MaxRect(vector<int> &v){
    int n=v.size();
    stack<int> s;
    int i=v[0],j=v[n-1],l=0;
    long long int currmax=0,Max=0;
    while(l<n){
        if(s.empty() || s.top()<=v[l]){
            s.push(v[l]);
        }else{
            int k=1;
            while(!s.empty() && s.top()>v[l]){
                currmax=max(currmax,s.top()*k);
                k++;
                s.pop();
            }
            s.push(v[l]);
        }
        if(Max<currmax){
            Max=currmax;
        }
        l++;
    }
    return Max;
}
int main(){
    vector<int> v={2, 1, 5, 6, 2, 3};
    cout<<"Given Vector is:";
    for(auto it:v){
        cout<<it<<" ";
    }cout<<endl;
    cout<<"Largest Rectangle Formed in Given Histogram is :"<<find_MaxRect(v)<<endl;
    return 0;
}
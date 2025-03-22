#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
vector<int > count_span(vector<int> & v){
    int n=v.size();
    stack<pair<int,int>> stock;
    vector<int> span;
    int days=1;
    for(int i=0;i<n;i++){
        days=1;
        if(stock.empty()){
            stock.push(make_pair(v[i],days));
        }else{
            if(stock.top().first<=v[i]){
                while(!stock.empty() && stock.top().first<=v[i]){
                    days+=stock.top().second;
                    stock.pop();
                }
            }
            stock.push(make_pair(v[i],days));    
        }
        span.push_back(days);
    }
    return span;
}
int main(){
    vector<int> v={100,80,60,70,60,75,85};
    vector<int> span=count_span(v);
    for(auto it:v){
        cout<<it<<' ';
    }cout<<endl;
    for(auto it:span){
        cout<<it<<' ';
    }cout<<endl;
    return 0;
}
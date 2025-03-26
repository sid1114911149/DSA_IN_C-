#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define vi vector<int>
priority_queue<int,vi,greater<int>> pqmin;
priority_queue<int,vi> pqmax;
void insert(int data){
    if(pqmin.size()==pqmax.size()){
        if(pqmin.size()==0){
            pqmax.push(data);
        }else{
            if(data<pqmax.top()){
                pqmax.push(data);
            }else{
                pqmin.push(data);
            }
        }
    }else{
        if(pqmax.size()>pqmin.size()){
            if(data>=pqmax.top()){
                pqmin.push(data);
            }else{
                int temp=pqmax.top();
                pqmax.pop();
                pqmax.push(data);
                pqmin.push(temp);
            }
        }else{
            if(data<=pqmin.top()){
                pqmax.push(data);
            }else{
                int temp=pqmin.top();
                pqmin.pop();
                pqmin.push(data);
                pqmax.push(temp);
            }
        }
    }
    return ;
}
double median(){
    if(pqmin.size()==pqmax.size()){
        return (pqmax.top()+pqmin.top())/2;
    }else{
        if(pqmin.size()>pqmax.size()){
            return pqmin.top();
        }else{
            return pqmax.top();
        }
    }
}
int main(){
    insert(10);
    cout<<median()<<endl;
    insert(8);
    cout<<median()<<endl;
    insert(19);
    cout<<median()<<endl;
    return 0;
}
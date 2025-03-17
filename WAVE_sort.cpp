#include<iostream>
#include<vector>
using namespace std;
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void Sort(vector<int> &v){
    if(v.size()<=1){
        cout<<"Vector is already Sorrted..\n";
        return ;
    }
    for(int i=1;i<v.size()-1;){
        if(v[i]>v[i-1]){
            swap(v[i],v[i-1]);
        }
        if(v[i]>v[i+1] && i<=v.size()-2){
            swap(v[i],v[i+1]);
        }
        i+=2;
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    return;
}
int main(){
    vector<int> v={1,3,4,7,5,6,2};
    Sort(v);
    return 0;
}
//TIME COMPLEXITY OF DNF SORT IS O(N)
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
        cout<<"Vector is Already Sorted..\n";
        return ;
    }
    int low=0,high=v.size()-1,mid=low;
    while(mid<=high){
        if(v[mid]==0){
            swap(v[mid],v[low]);
            mid++;
            low++;
        }else if(v[mid]==1){
            mid++;
        }else{
            swap(v[mid],v[high]);
            high--;
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    return ;
}
int main(){
    vector<int> v={0,1,1,0,0,1,2,2,1,2};
    Sort(v);
    return 0;
}
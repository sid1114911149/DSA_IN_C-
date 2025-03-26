#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    int arr[10]={1,2,-3,-6,8,3,-15,10,9,-16};
    int k=5;
    map<int,int> m;
    int prefix_sum=0;
    for(int i=0;i<10;i++){
        prefix_sum+=arr[i];
        m[prefix_sum]++;
    }
    cout<<m[k]<<endl;
    return 0;
}
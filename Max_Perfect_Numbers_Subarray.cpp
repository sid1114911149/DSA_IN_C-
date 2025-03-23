#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool check_perf(int a){
    int sum=0;
    for(int i=1;i<=a/2;i++){
        if(a%i==0){
            sum+=i;
        }
    }
    if(sum==a){
        return true;
    }
    return false;
}
vector<int> Perfect_subaray(vector<int> &v,int k){
    vector<int> temp,temp2;
    int n=v.size(),idx,count=0,count2=0;
    if(n<k){
        cout<<"No Possible Subarray..\n";
        return temp;
    }
    for(int i=0;i<k;i++){
        temp.push_back(v[i]);
        if(check_perf(v[i])){
            count++;
        }
    }
    temp2=temp;
    count2=count;
    idx=k-1;
    for(int i=k;i<n;i++){
        int a=temp2[0];
        temp2.erase(temp2.begin());
        temp2.push_back(v[i]);
        if(check_perf(a)){
            count2--;
        }
        if(check_perf(temp2.back())){
            count2++;
        }
        if(count2>count){
            count=count2;
            temp=temp2;
        }
    }
    return temp;
}
int main(){
    vector<int> v={1,2,4,2,-3,8};
    int k=4;
    vector<int> temp=Perfect_subaray(v,k);
    cout<<"subarray with Maximum No of Perfect Numbers of size "<<k<<" is :";
    if(temp.size()>0){
        for(auto it:temp){
            cout<<it<<" ";
        }cout<<endl;
    }else{
        cout<<"NO subarray with Perfect Numbers of size "<<k<<endl;
    }    
    return 0;
}
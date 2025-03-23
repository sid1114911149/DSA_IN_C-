#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long int getSum(vector<int>&v){
    long int sum=0;
    string str;
    for(int i=0;i<v.size();i++){
       str=str+to_string(v[i]);
    }
    return stoi(str);
}
vector<int> Max_sum_subaray(vector<int> &v,int k){
    vector<int> temp;
    int n=v.size(),sum=0,sum2=0,idx;
    if(n<k){
        cout<<"No Possible Subarray..\n";
        return temp;
    }
    for(int i=0;i<k;i++){
        temp.push_back(v[i]);
        sum+=v[i];
    }
    if(getSum(temp)%3==0){
       return temp;
    }
    sum2=sum,idx=k-1;
    for(int i=k;i<n;i++){
        sum=sum-v[i-k]+v[i];
        temp.erase(temp.begin());
        temp.push_back(v[i]);
        if(getSum(temp)%3==0){
           return temp;
        }
    }
    return temp;
}
int main(){
    vector<int> v={1,2,4,6,7,8};
    int k=4;
    vector<int> temp=Max_sum_subaray(v,k);
    if(temp.size()>0){
        for(auto it:temp){
            cout<<it<<" ";
        }cout<<endl;
    }else{
        cout<<"NO subarray with a combination of  Numbers divisible by 3 of size "<<k<<endl;
    }    
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool check_palin(vector<int> &v){
    int n=v.size();
    string str="";
    for(int i=0;i<n;i++){
        str=str+to_string(v[i]);
    }
    string str2=str;
    reverse(str2.begin(),str2.end());
    if(str==str2){
        return true;
    }
    return false;
}
vector<int> Palindromic_subaray(vector<int> &v,int k){
    vector<int> temp,temp2;
    int n=v.size(),idx;
    if(n<k){
        cout<<"No Possible Subarray..\n";
        return temp;
    }
    for(int i=0;i<k;i++){
        temp.push_back(v[i]);
    }
    if(check_palin(temp)){\
        temp2=temp;
        return temp2;
    }
    idx=k-1;
    for(int i=k;i<n;i++){
        temp.erase(temp.begin());
        temp.push_back(v[i]);
        if(check_palin(temp)){
            temp2=temp;
            return temp2;
        }
    }
    return temp2;
}
int main(){
    vector<int> v={1,2,4,2,-3,8};
    int k=3;
    vector<int> temp=Palindromic_subaray(v,k);
    if(temp.size()>0){
        for(auto it:temp){
            cout<<it<<" ";
        }cout<<endl;
    }else{
        cout<<"NO palindromic subarray of size "<<k<<endl;
    }    
    return 0;
}
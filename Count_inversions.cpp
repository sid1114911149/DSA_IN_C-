#include<iostream>
#include<vector>
using namespace std;
long long int merge(vector<int> &v,int l,int h,int mid){
    long long int count=0;
    vector<int> left,right;
    int lsize=mid-l+1;
    int rsize=h-mid;
    for(int i=0;i<lsize;i++){
        left.push_back(v[l+i]);
    }
    for(int i=0;i<rsize;i++){
        right.push_back(v[mid+i+1]);
    }
    for(int i=l,j=0,k=0;i<=h;i++){
        if((j<lsize && left[j]<right[k]) || k>=rsize){
            v[i]=left[j];
            j++;
        }else{
            if(j<lsize && left[j]>right[k]){
                count+=lsize-j;
            }
            v[i]=right[k];
            k++;
        }
    }
    return count;
}
long long int divide(vector<int> &v,int l,int h){
    long long int count=0;
    if(l<h){
        int mid=l+(h-l)/2;
        count+=divide(v,l,mid);
        count+=divide(v,mid+1,h);
        count+=merge(v,l,h,mid);
    }
    return count;
}
int main(){
    vector<int> v={3,5,6,9,1,2,7,8};
    long long int count=divide(v,0,v.size()-1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }cout<<endl;
    cout<<"Total no of Inversions in the given vector is:"<<count<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
bool isfeasible(vector<int> &v, int mid, int m) {
    int students = 1, pages = 0;
    for(int i = 0; i < v.size(); i++) {
        if (pages + v[i] > mid) { // If adding this book exceeds 'mid', allocate to next student
            students++;
            pages = v[i]; // Start new allocation with this book
            if (students > m) return false; // More students needed than available
        } else {
            pages += v[i]; // Add book to current student’s allocation
        }
    }
    return true;
}

int Minimum_pages(vector<int> &v,int m){
    int sum=0;
    int n=v.size();
    for(int i=0;i<n;i++){
        sum+=v[i];
    }
    int start=0,end=sum,mid,ans=INT_MAX;
    while(start<=end){
        mid=start+(end-start)/2;
        if(isfeasible(v,mid,m)){
            ans=min(ans,mid);
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> v={12,34,67,90};
    int m=2;
    cout<<Minimum_pages(v,m)<<endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int peakIndexInMountainArray(vector<int>& arr) {
    int l = 0, h = arr.size() - 1;
    
    while (l < h) {
        int mid = l + (h - l) / 2; // Prevents overflow
        
        if (arr[mid] < arr[mid + 1]) { 
            // We are in the increasing part of the mountain, move right
            l = mid + 1;
        } else { 
            // We are in the decreasing part or at the peak, move left
            h = mid;
        }
    }
    return l; // or return h; both are the same at the end
}
int main(){
    vector<int> arr={1,5,12,18,21,23,31,25,20,17,8,0};
    cout<<"Peak index in the give Array is: "<<peakIndexInMountainArray(arr)<<endl;
    return 0;
}
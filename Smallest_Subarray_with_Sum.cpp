#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

vector<int> Smallest_subarray(vector<int> &v, int sum) {
    int n = v.size();
    int start = 0, end = 0, current_sum = 0, min_len = INT_MAX;
    vector<int> result;

    while (end < n) {
        // Expand the window by adding the current element
        current_sum += v[end];

        // Shrink the window from the left if the sum is greater than 'sum'
        while (current_sum > sum) {
            // Update the result if the current window is smaller
            if (end - start + 1 < min_len) {
                min_len = end - start + 1;
                result.assign(v.begin() + start, v.begin() + end + 1);
            }
            current_sum -= v[start]; // Remove the leftmost element
            start++; // Move the window forward
        }

        // Move to the next element
        end++;
    }

    if (result.empty()) {
        cout << "No Possible Subarray..\n";
    }

    return result;
}

int main() {
    vector<int> v = {1, 2, 4, 6, -3, 8};
    int k = 8;

    vector<int> temp = Smallest_subarray(v, k);
    if(temp.size()>0){
        for(auto it:temp){
            cout<<it<<" ";
        }cout<<endl;
    }else{
        cout<<"NO subarray with size of "<<k<<endl;
    }    
    
    return 0;
}

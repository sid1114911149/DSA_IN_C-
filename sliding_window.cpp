#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> slidingWindowMax(vector<int>& nums, int k) {
    deque<int> dq;  // Stores indices of array elements
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove elements from the front that are out of this window
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        // Remove elements from the back that are smaller than the current element
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        // Insert current element index
        dq.push_back(i);

        // Store the max for this window (when we have at least k elements)
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    vector<int> maxValues = slidingWindowMax(nums, k);

    cout << "Given array: ";
    for (int Val : nums) {
        cout << Val << " ";
    }
    cout << endl;

    // Print results
    cout << "Sliding Window Maximum: ";
    for (int maxVal : maxValues) {
        cout << maxVal << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to store elements along with their array index and element index
struct HeapNode {
    int value;   // The element value
    int arrIdx;  // Index of the array the element belongs to
    int elemIdx; // Index of the element in the array

    // Min-heap comparator
    bool operator>(const HeapNode &other) const {
        return value > other.value;
    }
};

// Function to merge k sorted arrays using a min-heap
vector<int> mergeKSortedArrays(vector<vector<int>> &arrays) {
    priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> minHeap;
    vector<int> result;

    // Insert the first element of each array into the heap
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    // Process the min-heap
    while (!minHeap.empty()) {
        HeapNode node = minHeap.top();
        minHeap.pop();

        result.push_back(node.value);

        // If there are more elements in the same array, push the next element into the heap
        if (node.elemIdx + 1 < arrays[node.arrIdx].size()) {
            minHeap.push({arrays[node.arrIdx][node.elemIdx + 1], node.arrIdx, node.elemIdx + 1});
        }
    }

    return result;
}

int main() {
    vector<vector<int>> arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    vector<int> mergedArray = mergeKSortedArrays(arrays);

    cout << "Merged Sorted Array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

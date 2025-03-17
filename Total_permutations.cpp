#include <iostream>
#include <vector>
using namespace std;

void permutations(vector<int>& arr, vector<vector<int>>& v, vector<int>& newarr, int n) {
    if (n == 0) {
        v.push_back(newarr);
        return;
    }

    for (int i = 0; i < n; i++) {
        int ch = arr[i];
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                temp.push_back(arr[j]);
            }
        }

        newarr.push_back(ch);
        permutations(temp, v, newarr, n - 1);
        newarr.pop_back(); 
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> v;
    vector<int> newarr;
    int n = arr.size();

    permutations(arr, v, newarr, n);
    for (auto& it : v) {
        for (int num : it) {
            cout << num << ",";
        }
        cout << endl;
    }

    return 0;
}

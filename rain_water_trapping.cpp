#include <iostream>
#include <stack>
#include <vector>

using namespace std;

long long int find_water(vector<int> &v) {
    int n = v.size();
    long long int total = 0;
    stack<int> s;  // Stack to store indices

    for (int i = 0; i < n; i++) {
        while (!s.empty() && v[i] > v[s.top()]) {
            int bottom = s.top();
            s.pop();

            if (s.empty()) break;  // No left boundary

            int left = s.top();  // Left boundary
            int width = i - left - 1;  // Width between left and right
            int height = min(v[left], v[i]) - v[bottom];  // Height of water trapped

            total += (long long) width * height;
        }
        s.push(i);
    }

    return total;
}

int main() {
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Total trapped water: " << find_water(v) << endl;
    return 0;
}

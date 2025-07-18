#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int MatrixChainMultiplication(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int l = 2; l < n; ++l) {
        for (int i = 1; i < n - l + 1; ++i) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][n-1];
}
int main() {
    vector<int> arr = {40, 20, 30, 10, 30};
    int result = MatrixChainMultiplication(arr);
    cout << "Minimum number of multiplications is: " << result << endl;
    return 0;
}

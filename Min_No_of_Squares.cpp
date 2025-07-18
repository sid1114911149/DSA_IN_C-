#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> dp;

int Findans(int n) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; ++i) {
        ans = min(ans, 1 + Findans(n - i * i));
    }

    dp[n] = ans;
    return dp[n];
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;
    
    dp = vector<int>(n + 1, -1);

    int ans = Findans(n);
    cout << "Minimum number of squares summing to " << n << " is: " << ans << endl;

    return 0;
}

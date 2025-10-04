class Solution {
    const int MOD = 1e9 + 7;
public:

    int zigZagArrays(int n, int l, int r) {
    int m = r - l + 1;
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(r + 2, 0)));

    // Base case: sequences of length 1
    for (int x = l; x <= r; x++) {
        dp[1 % 2][0][x] = 1;  // next down
        dp[1 % 2][1][x] = 1;  // next up
    }

    for (int i = 1; i < n; i++) {
        int cur = i % 2, nxt = (i + 1) % 2;
        fill(dp[nxt][0].begin(), dp[nxt][0].end(), 0);
        fill(dp[nxt][1].begin(), dp[nxt][1].end(), 0);

        // prefix and suffix sums for optimization
        vector<int> pre(r + 2, 0), suf(r + 3, 0);

        // For dir = 1 (need up next) → x < y
        for (int x = l; x <= r; x++) {
            pre[x] = (pre[x - 1] + dp[cur][1][x]) % MOD;
        }
        for (int y = l; y <= r; y++) {
            dp[nxt][0][y] = pre[y - 1]; // sum of dp[cur][1][x] for x < y
        }

        // For dir = 0 (need down next) → x > y
        for (int x = r; x >= l; x--) {
            suf[x] = (suf[x + 1] + dp[cur][0][x]) % MOD;
        }
        for (int y = l; y <= r; y++) {
            dp[nxt][1][y] = suf[y + 1]; // sum of dp[cur][0][x] for x > y
        }
    }

    long long ans = 0;
    for (int x = l; x <= r; x++) {
        ans = (ans + dp[n % 2][0][x] + dp[n % 2][1][x]) % MOD;
    }
    return ans;
    }
};
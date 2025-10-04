class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int m = r - l + 1;

        // dp[dir][x] = number of zigzag arrays ending with value x
        // dir = 0 → next must go down, dir = 1 → next must go up
        vector<vector<int>> dp(2, vector<int>(r + 3, 0)), newdp(2, vector<int>(r + 3, 0));

        // base case: length 1 arrays
        for (int x = l; x <= r; x++) {
            dp[0][x] = 1; // can start going down next
            dp[1][x] = 1; // or up next
        }

        // build up to length n
        for (int len = 2; len <= n; len++) {
            // reset newdp
            fill(newdp[0].begin(), newdp[0].end(), 0);
            fill(newdp[1].begin(), newdp[1].end(), 0);

            // prefix sums for dp[1][x] (for dir=1 → need up next)
            vector<int> prefix(r + 3, 0);
            for (int x = l; x <= r; x++)
                prefix[x] = (prefix[x - 1] + dp[1][x]) % MOD;

            // suffix sums for dp[0][x] (for dir=0 → need down next)
            vector<int> suffix(r + 4, 0);
            for (int x = r; x >= l; x--)
                suffix[x] = (suffix[x + 1] + dp[0][x]) % MOD;

            // transition
            for (int y = l; y <= r; y++) {
                // coming from smaller x (x < y)
                newdp[0][y] = prefix[y - 1];    // next must go down
                // coming from larger x (x > y)
                newdp[1][y] = suffix[y + 1];    // next must go up
            }

            dp.swap(newdp);
        }

        long long ans = 0;
        for (int x = l; x <= r; x++) {
            ans = (ans + dp[0][x] + dp[1][x]) % MOD;
        }
        return ans;
    }
};

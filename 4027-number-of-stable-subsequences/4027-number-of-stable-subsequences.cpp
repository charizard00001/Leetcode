const int mod = 1e9 + 7;
class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        vector<int> dp(4, 0);
        // 0 : oe
        // 1 : eo
        // 2 : 00
        // 3 : ee
        int odd = 0;
        int even = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; ++i){
            if(nums[i] & 1){
                // dp[2] += (odd + dp[1]);
                dp[2] = (dp[2] + odd) % mod;
                dp[2] = (dp[2] + dp[1]) % mod;
                odd++;
                // dp[1] += (even + dp[0] + dp[3]);
                dp[1] = (dp[1] + even) % mod;
                dp[1] = (dp[1] + dp[0]) % mod;
                dp[1] = (dp[1] + dp[3]) % mod;
            }
            else{
                // dp[3] += (even + dp[0]);
                dp[3] = (dp[3] + even) % mod;
                dp[3] = (dp[3] + dp[0]) % mod;
                even++;
                // dp[0] += (odd + dp[1] + dp[2]);
                dp[0] = (dp[0] + odd) % mod;
                dp[0] = (dp[0] + dp[1]) % mod;
                dp[0] = (dp[0] + dp[2]) % mod;
            }
        }
        int ans = 0;
        ans += odd;
        ans += even;
        for(int i = 0 ; i < 4 ; ++i) ans = (ans + dp[i]) % mod;
        return ans % mod;         
    }
};
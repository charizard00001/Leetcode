class Solution {
    int N;
public:
    int find_min(int prev, int i, vector<int> &nums, vector<vector<int>> &dp){
        // basecase
        if(i == N) return nums[prev];
        if(i == N - 1) return max(nums[prev], nums[i]);

        if(dp[i][prev] != -1) return dp[i][prev];
        
        // leave A[i]
        int maxm = max(nums[i + 1], nums[prev]);
        int ans_1 = maxm + find_min(i, i + 2, nums, dp);

        // leave A[i + 1]
        maxm = max(nums[i], nums[prev]);
        int ans_2 = maxm + find_min(i + 1, i + 2, nums, dp);

        // leave A[prev]
        maxm = max(nums[i + 1], nums[i]);
        int ans_3 = maxm + find_min(prev, i + 2, nums, dp);
        
        return dp[i][prev] = min({ans_1, ans_2, ans_3});
    }
    
    int minCost(vector<int>& nums) {
        N = nums.size();
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        return find_min(0, 1, nums, dp);
    }
};
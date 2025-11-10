class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int K) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(K + 1, -1)));
        dp[0][0][0] = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(i == 0 && j == 0) continue;
                int score = (grid[i][j] == 0 ? 0 : (grid[i][j] == 1 ? 1 : 2));
                int cost_add = (grid[i][j] == 0 ? 0 : 1); 
                for(int k = 0 ; k <= K ; ++k){
                    int prev_k = k - cost_add;
                    if(prev_k >= 0){
                        int best = -1;
                        if(i > 0 && dp[i - 1][j][prev_k] != -1) best = max(best, dp[i - 1][j][prev_k]);
                        if(j > 0 && dp[i][j - 1][prev_k] != -1) best = max(best, dp[i][j - 1][prev_k]);
                        if(best != -1) dp[i][j][k] = best + score;
                    }
                }
            }
        }
        // int ans = -1;
        // for(int k = 0 ; k <= K ; ++k){
        //     ans = max(ans, dp[n - 1][m - 1][k]);
        // }
        // return ans;
        return *max_element(dp[n - 1][m - 1].begin(), dp[n - 1][m - 1].end());
    }
};
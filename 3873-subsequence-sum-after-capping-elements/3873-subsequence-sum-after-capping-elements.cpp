class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> org_nums(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int n = nums.size();
        vector<bool> ans(n, false);
        vector<vector<bool>> dp(n , vector<bool>(k + 1, false));
        for(int s = 0 ; s <= k ; ++s){
            for(int i = n - 1 ; i >= 0 ; --i){
                if(s == 0){
                    dp[i][s] = true;
                }
                else if(i == n - 1){
                    dp[i][s] = (s == nums[i] ? true : false);
                }
                else{
                    dp[i][s] = dp[i][s] || dp[i + 1][s];
                    if(s - nums[i] >= 0) dp[i][s] = dp[i][s] || dp[i + 1][s - nums[i]];
                }
            }
        }
        for(auto &a : org_nums) cout << a << " ";
        cout << endl;
        vector<int> t(n, 0);
        for(int i = 0 ; i < n ; ++i){
            auto it = upper_bound(org_nums.begin(), org_nums.end(), i + 1);
            if(it != org_nums.end()){
                t[i] = n - (it - org_nums.begin());
            }
            else{
                t[i] = 0;
            }
            cout << t[i] << " ";  
        }
        for(int x = 1 ; x <= n ; ++x){
            if(k % x == 0 && k / x <= t[x - 1]){
                ans[x - 1] = true; continue;
            }
            for(int s = 1 ; s <= k ; ++s){
                if(t[x - 1] < n && t[x - 1] >= 0 && dp[t[x - 1]][s]){
                    if((k - s) % x == 0){
                        int m = (k - s) / x;
                        if(m <= t[x - 1]){
                            ans[x - 1] = true;
                        }
                    }
                }

            }
        }
        return ans;
    }
};
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if(n == 1){
            if(nums[0] == 0) return 0;
            return 1;
        }
        for(int i = 0 ; i < 32 ; ++i){
            int count = 0;
            for(int j = 0 ; j < n ; ++j){
                if((nums[j] >> i) & 1){
                    count++;
                }
            }
            if(count != 0){
                if(count & 1){
                    ans = max(ans, n);
                }
                else{
                    ans = max(ans, n - 1);
                }
            }
        }
        return ans;
    }
};
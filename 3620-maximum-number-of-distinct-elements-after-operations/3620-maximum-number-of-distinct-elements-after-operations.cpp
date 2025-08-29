class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int ans = 0;
        int prev = INT_MIN;
        sort(nums.begin(), nums.end());

        for(auto &a : nums){
            int minm = a - k;
            int maxm = a + k;

            if(minm > prev){
                prev = minm;
                ans++;
            }
            else if(maxm > prev){
                prev++;
                ans++;
            }
        }
        return ans;
    }
};
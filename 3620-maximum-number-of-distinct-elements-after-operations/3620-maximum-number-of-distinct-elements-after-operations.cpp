class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        if(k == 0){
            set<int> S(nums.begin(), nums.end());
            return S.size();
        }
        else{
            int minm = INT_MIN;
            int ans = 0;
            sort(nums.begin(), nums.end());
            int n = nums.size();
            for(int i = 0 ; i < n ; ++i){
                if(nums[i] - k < minm){
                    if(minm < nums[i] + k){
                        minm++;
                        ans++;
                    }
                }
                else if(nums[i] - k == minm){
                    minm++;
                    ans++;
                }
                else{
                    minm = nums[i] - k;
                    ans++;
                }
            }
            return ans;
        }
    }
};
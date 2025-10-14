class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        vector<pair<int, int>> P;
        int n = nums.size(), i = 0;
        while(i < n - 1){
            int j = i;
            while(j < n - 1 && nums[j] < nums[j + 1]) j++;
            P.push_back(make_pair(i, j));
            i = j + 1;
        }
        int len = P.size();
        int ans = 1;
        for(int i = 0 ; i < len ; ++i){
            ans = max(ans, (P[i].second - P[i].first + 1)/2);
            if(i < len - 1){
                if(P[i].second + 1 == P[i + 1].first){
                    ans = max(ans, min(P[i].second - P[i].first + 1, P[i + 1].second - P[i + 1].first + 1));
                }
            }
        }
        return ans >= k;
    }
};
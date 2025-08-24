// each group should have k elements and all need to be distinct
// n % k == 0
// grps = n/k
// max_freq <= grps otherwise false

class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int total = nums.size();
        if(total % k != 0) return false;
        int groups = total / k;
        unordered_map<int, int> freq;
        int max_freq = 1;
        for(auto &a : nums) {
            freq[a]++;
            max_freq = max(max_freq, freq[a]);
        }
        return max_freq <= groups;

    }
};
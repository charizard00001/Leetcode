class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> M; int N = nums.size();
        for(int i = 0 ; i < N ; ++i){
            M[nums[i]] = i;
        }
        for(auto &o : operations){
            int old_key = o[0];
            int new_key = o[1];

            auto it = M.find(old_key);
            nums[it->second] = new_key;
            M[new_key] = it->second;
            M.erase(it);
        }
        return nums;
    }
};
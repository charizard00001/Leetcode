class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N);
        vector<int> left_max(N), right_min(N);

        left_max[0] = nums[0];
        for(int i = 1 ; i < N ; ++i){
            left_max[i] = max(left_max[i - 1], nums[i]);
        }

        // cout << "left-max ";
        // for(auto &l : left_max) cout << l << " ";
        // cout << endl;

        right_min[N - 1] = nums[N - 1];
        for(int i = N - 2 ; i >= 0 ; --i){
            right_min[i] = min(nums[i], right_min[i + 1]);
        }

        // cout << "right-min ";
        // for(auto &r : right_min) cout << r << " ";
        // cout << endl;

        ans[N - 1] = left_max[N - 1];
        for(int i = N - 2 ; i >= 0 ; --i){
            // cout << "iteration " << i << " ";
            if(left_max[i] > right_min[i + 1]){
                ans[i] = ans[i + 1];
            }
            else{
                ans[i] = left_max[i];
            }
            // for(auto &a : ans) cout << a << " ";
            // cout << endl;
        }

        return ans;
    }
};
class Solution {
public:
    void wiggleSort(std::vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int mid = (nums.size() + 1) / 2;
        int j = mid - 1;
        int k = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = sorted[j--];
            } else {
                nums[i] = sorted[k--];
            }
        }
    }
};
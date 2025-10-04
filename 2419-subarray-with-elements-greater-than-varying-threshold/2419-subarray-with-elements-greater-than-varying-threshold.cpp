// min_element_of_subarray * k > threshold
// treat each element as minm and find subarray of it as min 
// and then check the threshold condition

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        // previous smaller element
        for(int i = 0 ; i < n ; ++i){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(!st.empty()) left[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        // next greater element
        for(int i = n - 1 ; i >= 0 ; --i){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(!st.empty()) right[i] = st.top();
            st.push(i);
        }
        for(int i = 0 ; i < n ; ++i){
            int len = right[i] - left[i] - 1;
            if((long long)nums[i] * len > threshold){
                return len;
            }
        }
        return -1;
    }
};
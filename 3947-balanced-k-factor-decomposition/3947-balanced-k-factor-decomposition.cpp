class Solution {
public:
    vector<int> best; // stores the best partition
    int bestdiff = INT_MAX; // stores the min diff of max and min

    vector<int> minDifference(int n, int k) {
        vector<int> curr;
        backtrack(n, k, 1, curr);
        return best;
    }

    void backtrack(int n, int k, int start, vector<int> &curr){

        // n, number to partition 
        // k, number of division left
        // start, the starting factor of n
        // curr, to store the partitions till now

        // basecase
        if(k == 1){
            // only one partition left
            // only option to add n 
            curr.push_back(n);
            update_ans(curr);
            curr.pop_back();
            return;
        }

        // iterating the factor of n, starting from the previously 
        // used factor

        for(int factor = start ; factor * factor <= n ; ++factor){
            if(n % factor == 0){
                curr.push_back(factor);
                backtrack(n/factor, k - 1, factor, curr);
                curr.pop_back();
            }
        }
    }

    void update_ans(vector<int> &curr){
        int maxm = *max_element(curr.begin(), curr.end());
        int minm = *min_element(curr.begin(), curr.end());

        if(maxm - minm < bestdiff){
            bestdiff =  maxm - minm;
            best = curr;
        }
    }

};
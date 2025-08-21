class Solution {
public:
    vector<int> prime_factors(int N){
        vector<int> ans;
        if(N%2 == 0){
            ans.push_back(2);
            while(N%2 == 0) N /= 2;
        }

        for(int i = 3 ; i * i <= N ; i+=2){
            if(N%i == 0){
                ans.push_back(i);
                while(N%i == 0) N /= i;
            }
        }

        if(N > 1) ans.push_back(N); // N is prime ??? why ????
        return ans;
    }

    int distinctPrimeFactors(vector<int>& nums) {
        unordered_map<int, int> M;
        for(auto &a : nums){
            vector<int> factors = prime_factors(a);
            for(auto &f : factors){
                M[f]++;
            }
        }
        return M.size();
    }
};
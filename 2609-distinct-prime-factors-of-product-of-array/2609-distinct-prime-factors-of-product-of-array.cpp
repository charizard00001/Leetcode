class Solution {
    unordered_map<int, int> M;
public:
    void prime_factors(int N){
        if(N%2 == 0){
            M[2]++; while(N%2 == 0) N /= 2;
        }

        for(int i = 3 ; i * i <= N ; i+=2){
            if(N%i == 0){
                M[i]++; while(N%i == 0) N /= i;
            }
        }

        if(N > 1) M[N]++; // N is prime ??? why ????
    }

    int distinctPrimeFactors(vector<int>& nums) {
        for(auto &a : nums) prime_factors(a); return M.size();
    }
};
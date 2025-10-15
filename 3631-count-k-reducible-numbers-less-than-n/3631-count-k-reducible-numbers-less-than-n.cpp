const int mod = 1e9 + 7;
class Solution {
public:
    vector<int> opr;
    int dp[801][801][2]; 
    string digits;
    void build(){
        opr.resize(801);
        opr[0] = 0;
        opr[1] = 0;
        for(int i = 2 ; i <= 800 ; ++i) opr[i] = 1 + opr[__builtin_popcount(i)];
    }
    void add_mod(int &a, int b){
        a += b;
        if(a >= mod) a-= mod;
    }
    int f(int pos, int cnt, int tight, int k){
        if(pos == digits.size()){
            // if(cnt == 0) return 0;
            // int opr_needed = (cnt == 1 ? 0 : 1 + opr[cnt]);
            // return opr_needed <= k;
            return (tight || cnt == 0) ? 0 : opr[cnt] < k;
        }
        if(dp[pos][cnt][tight] != -1) return dp[pos][cnt][tight];
        int limit = tight ? (digits[pos] - '0') : 1;
        int ans = 0;
        for(int d = 0 ; d <= limit ; ++d){
            int new_tight = tight && (d == limit);
            add_mod(ans, f(pos + 1, cnt + (d == 1), new_tight, k));
        }
        return dp[pos][cnt][tight] = ans;
    }
    int countKReducibleNumbers(string s, int k) {
        build();
        digits = s;
        memset(dp, -1, sizeof(dp));
        return f(0, 0, 1, k);
    }
};
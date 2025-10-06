class Solution {
    string s;
    long long dp[17][17][2][2];
public:
    long long f(int i, int carry, int za, int zb){
        if(i == s.size()){
            if(!carry){
                return 1;
            }
            return 0;
        }

        if(dp[i][carry][za][zb] != -1) return dp[i][carry][za][zb];

        int a_start = (za ? 0 : (i == 0 ? 1 : 0));
        int b_start = (zb ? 0 : (i == 0 ? 1 : 0));
        int a_end = (za ? 0 : 9);
        int b_end = (zb ? 0 : 9);
        long long count = 0;

        // if(za) a_end = 0;
        // if(zb) b_end = 0;

        // if(i == 0){
        //     a_start = 1;
        //     b_start = 1;
        // }

        for(int a = a_start; a <= a_end; ++a){
            for(int b = b_start; b <= b_end; ++b){
                int num = a + b + carry;
                // 17 % 10 = 7, 7 % 10 = 7
                if(num % 10 == s[i] - '0'){
                    int new_za = (a == 0 ? 1 : za);
                    int new_zb = (b == 0 ? 1 : zb);
                    count += f(i + 1, num / 10, new_za, new_zb);
                }
            }
        }

        return dp[i][carry][za][zb] = count;
    }
    long long countNoZeroPairs(long long n) {
        s = to_string(n);
        reverse(s.begin(), s.end());
        memset(dp, -1, sizeof(dp));
        return f(0, 0, 0, 0);
    }
};
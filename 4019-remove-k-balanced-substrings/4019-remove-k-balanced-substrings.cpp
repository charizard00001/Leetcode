class Solution {
public:
    bool check(const string &s, int k){
        int n = s.length();
        int l = n - 2*k, r = n - 1; 
        // 0 1 2 3 4 5 6, n = 7, k = 2
        while(l < r){
            if(s[l] != '(' || s[r] != ')'){
                return false;
            }
            l++, r--;
        }
        return true;
    }
    string removeSubstring(string s, int k) {
        string ans;
        int n = s.length();
        for(int i = 0 ; i < n ; ++i){
            int c = s[i];
            ans += c;
            int len = ans.length();
            if(len >= 2*k){
                if(check(ans, k)){
                    ans.resize(len - 2*k);
                }
            }
        }
        return ans;
    }
};
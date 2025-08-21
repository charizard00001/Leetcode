class Solution {
public:
    bool is_valid(string S){
        if(S.size() == 0) return false;
        for(auto &c : S){
            if(isalnum(c) || c == '_') continue;
            return false;
        }
        return true;
    }
    
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        map<string, multiset<string>> M; int N = code.size();
        for(int i = 0 ; i < N ; ++i){
            if(isActive[i] && is_valid(code[i])) M[businessLine[i]].insert(code[i]);
        }
        vector<string> ans;
        if(M.find("electronics") != M.end()) ans.insert(ans.end(), M["electronics"].begin(), M["electronics"].end());
        if(M.find("grocery") != M.end()) ans.insert(ans.end(), M["grocery"].begin(), M["grocery"].end());
        if(M.find("pharmacy") != M.end()) ans.insert(ans.end(), M["pharmacy"].begin(), M["pharmacy"].end());
        if(M.find("restaurant") != M.end()) ans.insert(ans.end(), M["restaurant"].begin(), M["restaurant"].end());
        return ans;
    }
};
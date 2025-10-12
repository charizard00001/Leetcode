class Solution {
public:
    const int MAXN = 1e5;
    vector<int> spf;
    long long ans = 0;
    vector<vector<int>> adj;
    vector<int> value;
    void sieve() {
        spf.assign(MAXN + 1, 0);
        iota(spf.begin(), spf.end(), 0); // spf[i] = i
        for (int i = 2; i * i <= MAXN; ++i) {
            if (spf[i] == i) { // i is prime
                for (int j = i * i; j <= MAXN; j += i)
                    if (spf[j] == j) spf[j] = i;
            }
        }
    }
    int squareFreeKernel(int x) {
        int res = 1;
        while (x > 1) {
            int p = spf[x];
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            if (cnt % 2 == 1) res *= p;
        }
        return res;
    }
    unordered_map<int, int> dfs(int u, int p) {
        unordered_map<int, int> M;
        for (auto &v : adj[u]) {
            if(v == p) continue;
            unordered_map<int, int> temp = dfs(v, u);
            if(temp.size() > M.size()) swap(temp, M);
            for(auto &[key, v] : temp){
                M[key] += v;
            }
        }
        if(M.find(value[u]) != M.end()){
            ans += M[value[u]];
        }
        M[value[u]]++;
        return M;
    }

    // unordered_map<int, int> dfs(int u, int p) {
    //     unordered_map<int, int> bigMap;

    //     for (auto &v : adj[u]) {
    //         if (v == p) continue;
    //         auto childMap = dfs(v, u);

    //         // Always merge smaller into larger
    //         if (childMap.size() > bigMap.size())
    //             swap(childMap, bigMap);

    //         for (auto &[key, val] : childMap) {
    //             bigMap[key] += val;
    //         }
    //     }

    //     // Use bigMap for current node
    //     if (bigMap.find(value[u]) != bigMap.end()) {
    //         ans += bigMap[value[u]];
    //     }

    //     bigMap[value[u]]++;
    //     return bigMap;
    // }

    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        sieve();
        for(auto &a : nums) value.push_back(squareFreeKernel(a));
        adj.assign(n, {});
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        unordered_map<int, int> M = dfs(0, -1);
        return ans;
    }
};
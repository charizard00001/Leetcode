using plli = pair<long long, int>;
using pii = pair<int, int>;
const int mod = 1e9 + 7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // unordered_map<int, int> M; // dist, # it hitttt
        vector<vector<pii>> adj(n);
        for(auto e : roads){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<int> count(n, 0);
        priority_queue<plli, vector<plli>, greater<>> pq;
        dist[0] = 0;
        count[0] = 1;
        pq.push({0, 0}); // sdist to reach u, u
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto &[v, w] : adj[u]){
                long long dv = d + w;
                if(dist[v] > dv){
                    count[v] = count[u];
                    dist[v] = dv;
                    pq.push({dist[v], v});
                }
                else if(dist[v] == dv){
                    count[v] = (count[v] + count[u]) % mod;
                }
            }
        }
        return count[n - 1];
    }
};
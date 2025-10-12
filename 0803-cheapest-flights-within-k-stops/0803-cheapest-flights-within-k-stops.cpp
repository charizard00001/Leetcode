using T = tuple<int, int, int>;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &e : flights){
            adj[e[0]].push_back(make_pair(e[1], e[2]));
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 5, INT_MAX));
        dp[src][1] = 0;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, src, 1});
        int ans = INT_MAX;
        while(!pq.empty()){
            auto [c, node, stops] = pq.top();
            if(node == dst) ans = min(ans, c);
            pq.pop();
            for(auto [neighbour, w] : adj[node]){
                int dist = c + w;
                if(stops + 1 <= k + 2 && dp[neighbour][stops + 1] > dist){
                    dp[neighbour][stops + 1] = dist;
                    pq.push({dist, neighbour, stops + 1});
                }
            }
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};
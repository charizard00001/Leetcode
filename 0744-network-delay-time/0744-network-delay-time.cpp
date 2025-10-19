using pii = pair<int, int>;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adj(n);
        for(auto &e : times){
            adj[e[0] - 1].push_back(make_pair(e[1] - 1, e[2]));
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[k - 1] = 0;
        pq.push(make_pair(0, k - 1)); //dist, node
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            for(auto &[v, w] : adj[u]){
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        int maxm = 0;
        for(auto &d : dist) {
            maxm = max(maxm, d);
            cout << d << " ";
        }
        return (maxm == INT_MAX ? -1 : maxm);
    }
};
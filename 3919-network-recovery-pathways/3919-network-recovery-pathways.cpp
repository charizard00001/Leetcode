// node 0 and n-1 -> always online
// min max problem -> Binary search ?????????????
// ya but with djkstra

class Solution {
    vector<vector<pair<int, int>>> adj;
    vector<long long> distance;
    vector<bool> alive;
    int N;
public:
    long long djkstra(int limit){
        distance.assign(N, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        distance[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()){
            auto [dist, node] = pq.top(); pq.pop();
            if(node == N - 1) return dist;
            if(dist != distance[node]) continue;
            for(auto &neighbour : adj[node]){
                int w = neighbour.second;
                int neighbour_node = neighbour.first;
                if(alive[neighbour_node] && w >= limit && distance[neighbour_node] > w + dist){
                    distance[neighbour_node] = w + dist;
                    pq.push({distance[neighbour_node], neighbour_node});
                }
            }
        }

        return distance[N - 1];
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        N = online.size(); adj.resize(N); alive = online;
        vector<int> cost;
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]}); cost.push_back(e[2]);
        }
        sort(cost.begin(), cost.end());
        cost.erase(unique(cost.begin(), cost.end()), cost.end());
        int low = 0, high = cost.size() - 1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int limit = cost[mid];
            long long distance = djkstra(limit);
            if(distance <= k){
                ans = limit;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};
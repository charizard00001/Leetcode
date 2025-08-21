// how do i know that i have to remove which edge ????

class Solution {
    vector<vector<pair<int, int>>> adj;
    vector<bool> visited;
    int N;
public:
    void dfs(int node, int weight){
        visited[node] = true;
        for(auto &neighbour : adj[node]){
            if(!visited[neighbour.first] && neighbour.second <= weight){
                dfs(neighbour.first, weight);
            }
        }
    }
    
    int count_components(int weight){
        visited.assign(N, false);
        int components = 0;
        for(int i = 0 ; i < N ; ++i){
            if(!visited[i]){
                dfs(i, weight); components++;
            }
        }
        return components;
    }
    
    int minCost(int n, vector<vector<int>>& edges, int k) {
        N = n; adj.assign(N, {});
        int high = 0, low = 0;
        vector<int> W; W.push_back(0);
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
            W.push_back(e[2]);
        }
        sort(W.begin(), W.end());
        W.erase(unique(W.begin(), W.end()), W.end());
        high = W.size() - 1;
        int ans = W.back();
        while(low <= high){
            int mid = low + (high -  low)/2;
            int weight = W[mid];
            int components = count_components(weight);
            if(components <= k){
                ans = weight;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
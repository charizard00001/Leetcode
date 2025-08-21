class Solution {
    vector<vector<pair<int, int>>> adj;
    vector<int> visited;
    int N;
    
public:
    void dfs(int node, int t){
        visited[node] = 1;
        for(auto &neighbour : adj[node]){
            if(!visited[neighbour.first] && neighbour.second > t){
                dfs(neighbour.first, t);
            }
        }
    }
    
    int count_components(int t){
        visited.assign(N, 0);;
        int components = 0;
        for(int i = 0 ; i < N ; ++i){
            if(!visited[i]){
                dfs(i, t); components++;
            }
        }
        return components;
    }
    
    int minTime(int n, vector<vector<int>>& edges, int k) {
        N = n; adj.resize(N);
        int high = 0, low = 0;
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]}); adj[e[1]].push_back({e[0], e[2]});
            high = max(high, e[2]);
        }

        int components = count_components(0);
        if(components >= k) return 0;
        
        while(low <= high){
            int curr_time = low + (high - low)/2;
            int curr_components = count_components(curr_time);
            if(curr_components >= k){
                high = curr_time - 1;
            }
            else low = curr_time + 1;
        }

        return low;
    }
};
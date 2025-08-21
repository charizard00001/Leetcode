class Solution {
    vector<vector<int>> adj;
    vector<int> V, status, grid;
    unordered_map<int, set<int>> M;
    int N;
    int grid_idx = 0;
        
public:
    void dfs(int node){
        V[node] = 1; grid[node] = grid_idx; M[grid_idx].insert(node);
        for(auto &neighbour : adj[node]){
            if(!V[neighbour]) dfs(neighbour);
        }
    }
    
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        N = c; adj.resize(N); V.resize(N, 0); status.resize(N, 1); grid.resize(N);
        
        for(auto &c : connections){
            adj[c[0] - 1].push_back(c[1] - 1); adj[c[1] - 1].push_back(c[0] - 1);
        }
        
        for(int i = 0 ; i < c ; ++i){
            if(!V[i]){
                dfs(i); grid_idx++;
            }
        }

        vector<int> ans;
        for(auto &q : queries){
            if(q[0] == 1){
                int node = q[1] - 1;
                if(status[node]) ans.push_back(node + 1);
                else{
                    if(M[grid[node]].empty()) ans.push_back(-1);
                    else ans.push_back(*M[grid[node]].begin() + 1);
                }
            }
            else{
                int node = q[1] - 1; status[node] = 0; M[grid[node]].erase(node);
            }
        }

        return ans;
    }
};
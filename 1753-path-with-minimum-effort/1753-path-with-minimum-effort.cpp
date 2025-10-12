using T = tuple<int, int, int>;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

class Solution {
public:
    bool check(int i, int j, int n, int m){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> mat(row, vector<int>(col, INT_MAX));
        mat[0][0] = 0;
        priority_queue<T, vector<T>, greater<T>> pq;
        // wt, node (x, y)
        pq.push({0, 0, 0});    
        while(!pq.empty()){
            auto [w, x, y] = pq.top();
            pq.pop();
            if(x == row - 1 && y == col - 1) return w;
            for(int i = 0 ; i < 4 ; ++i){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(check(nx, ny, row, col)){
                        int dw = max(w, abs(heights[nx][ny] - heights[x][y]));
                        if(mat[nx][ny] > dw){
                            mat[nx][ny] = dw;
                            pq.push({dw, nx, ny});
                        }
                    }
                }
        }
        return 0;
    }
};
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

class Solution {
public:
    bool check(int i, int j, int n, int m){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int row = grid.size();
        int col = grid[0].size();
        int timer = 0;
        queue<pair<int, int>> Q;
        grid[0][0] = 1;
        Q.push(make_pair(0, 0));
        while(!Q.empty()){
            timer++;
            int len = Q.size();
            while(len--){
                auto [x, y] = Q.front(); Q.pop();
                if(x == row - 1 && y == col - 1) return timer;
                for(int i = 0 ; i < 8 ; ++i){
                    for(int j = 0 ; j < 8 ; ++j){
                        int nx = x + dx[i];
                        int ny = y + dy[j];
                        if(check(nx, ny, row, col) && grid[nx][ny] == 0){
                            grid[nx][ny] = 1;
                            Q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
        return -1;
    }
};
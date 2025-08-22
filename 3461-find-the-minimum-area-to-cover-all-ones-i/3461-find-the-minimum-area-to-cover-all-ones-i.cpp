class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int col_s = 0, col_e = col - 1;
        int row_s = 90, row_e = row - 1;

        //for col
        bool flag = true;
        for(int j = 0 ; j < col ; ++j){
            for(int i = 0 ; i < row ; ++i){
                if(grid[i][j] == 1){
                    if(flag)col_s = j; flag = false;
                    col_e = j; break;
                }
            }
        }

        //for row
        flag = true;
        for(int i = 0 ; i < row ; ++i){
            for(int j = 0 ;  j < col ; ++j){
                if(grid[i][j] == 1){
                    if(flag) row_s = i; flag = false;
                    row_e = i; break;
                }
            }
        }

        int length = col_e - col_s + 1, bredth = row_e - row_s + 1;
        return bredth * length;
    }
};
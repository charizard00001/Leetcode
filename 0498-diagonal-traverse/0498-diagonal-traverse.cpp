class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> diagonal;
        bool flag = false; // true -> rotate false -> not
        int row = mat.size(), col = mat[0].size();
        for(int r = 0 ; r < row ; ++r){
            vector<int> temp;
            // at (r, 0)
            int i = r, j = 0;
            while(i >= 0 && j < col){
                temp.push_back(mat[i][j]);
                i--; j++;
            }
            if(flag){
                reverse(temp.begin(), temp.end());
            }
            flag = !flag;
            diagonal.insert(diagonal.end(), temp.begin(), temp.end());
        }

        for(int c = 1 ; c < col ; ++c){
            vector<int> temp;
            // at (n - 1, c)
            int i = row - 1, j = c;
            while(i >= 0 && j < col){
                temp.push_back(mat[i][j]);
                i--; j++;
            }
            if(flag){
                reverse(temp.begin(), temp.end());
            }
            flag = !flag;
            diagonal.insert(diagonal.end(), temp.begin(), temp.end());            
        }
        return diagonal;
    }
};
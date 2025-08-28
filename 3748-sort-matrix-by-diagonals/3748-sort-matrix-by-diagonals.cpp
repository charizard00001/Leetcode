class Solution {
    int N;
public:
    void sort_diagonal(int start_i, int start_j, vector<vector<int>>& grid, bool ascending) {
        int n = N - max(start_i, start_j); 
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                int &a = grid[start_i + j][start_j + j];
                int &b = grid[start_i + j + 1][start_j + j + 1];
                if ((ascending && a > b) || (!ascending && a < b)) {
                    swap(a, b);
                    swapped = true;
                }
            }
            if (!swapped) break; 
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        N = grid.size();

        for (int j = 1; j < N; j++) {
            sort_diagonal(0, j, grid, true);
        }

        for (int i = 0; i < N; i++) {
            sort_diagonal(i, 0, grid, false);
        }

        return grid;
    }
};

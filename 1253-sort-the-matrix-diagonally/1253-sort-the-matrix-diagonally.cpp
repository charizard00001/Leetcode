class Solution {
    int N, M;
public:
    void sort_diagonal(int start_i, int start_j, vector<vector<int>>& grid, bool ascending) {
        int len = min(N - start_i, M - start_j); 
        for (int i = 0; i < len - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < len - i - 1; j++) {
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

    vector<vector<int>> diagonalSort(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();

        for (int j = 0; j < M; j++) {
            sort_diagonal(0, j, grid, true);
        }

        for (int i = 1; i < N; i++) {
            sort_diagonal(i, 0, grid, true);
        }

        return grid;
    }
};

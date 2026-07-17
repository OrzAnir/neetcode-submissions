class Solution {
public:
    bool isValid(int row, int col, vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();
        int x = col;
        while(x >= 0) {
            if (grid[row][x] == 'Q') return false;
            x--;
        }
        int i = row, j = col;
        while(i >= 0 && j >= 0) {
            if (grid[i][j] == 'Q') return false;
            i--; j--;
        }
        i = row; j = col;
        while(i < n && j >= 0) {
            if (grid[i][j] == 'Q') return false;
            i++; j--;
        }
        return true;
    }
    void func(int index, vector<string>& grid, vector<vector<string>>& result) {
        if (index == grid[0].size()) {
            result.push_back(grid);
            return; 
        }
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            if (isValid(i, index, grid)) {
                grid[i][index] = 'Q';
                func(index + 1, grid, result);
                grid[i][index] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> grid(n, string(n, '.'));
        func(0, grid, result);
        return result;
    }
};

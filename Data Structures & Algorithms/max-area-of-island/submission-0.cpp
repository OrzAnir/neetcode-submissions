class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid) {
        visited[row][col] = 1;
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, -1, 0, 1};
        for(int i = 0; i < 4; i++) {
            int newr = row + delr[i];
            int newc = col + delc[i];
            if (newr < 0 || newc < 0 || newr >= n || newc >= m) continue;
            if (grid[newr][newc] == 1 && !visited[newr][newc]) {
                count += dfs(newr, newc, visited, grid);
            }
        }
        return count + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int maxarea = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    maxarea = max(maxarea, dfs(i, j, visited, grid));
                }
            }
        }
        return maxarea;
    }
};

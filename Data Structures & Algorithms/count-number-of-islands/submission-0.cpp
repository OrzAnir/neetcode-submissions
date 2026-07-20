class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid) {
        visited[row][col] = 1;
        int n = grid.size(), m = grid[0].size();
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, -1, 0, 1};
        for(int i = 0; i < 4; i++) {
            int newr = row + delr[i];
            int newc = col + delc[i];
            if (newr < 0 || newc < 0 || newr >= n || newc >= m) continue;
            if (grid[newr][newc] == '1' && !visited[newr][newc]) {
                dfs(newr, newc, visited, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int islands = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands += 1;
                    dfs(i, j, visited, grid);
                }
            }
        }
        return islands;
    }
};

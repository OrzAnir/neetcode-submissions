class Solution {
public:
    void bfs(vector<vector<int>>& heights, vector<vector<int>>& ocean) {
       queue<pair<int, int>> q;
       int n = heights.size(), m = heights[0].size();
       for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (ocean[i][j] == 1) q.push({i, j});
        }
       }
       while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            auto p = q.front(); q.pop();
            int row = p.first, col = p.second;
            int delr[] = {-1, 0, 1, 0};
            int delc[] = {0, -1, 0, 1};
            for(int j = 0; j < 4; j++) {
                int newr = row + delr[j];
                int newc = col + delc[j];
                if (newr < 0 || newc < 0 || newr >= n || newc >= m) continue;
                if (heights[newr][newc] >= heights[row][col] && !ocean[newr][newc]) {
                    ocean[newr][newc] = 1;
                    q.push({newr, newc});
                }
            }
        }
       }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        for(int i = 0; i < m; i++) {
            pacific[0][i] = 1;
            atlantic[n - 1][i] = 1;
        }
        for(int i = 0; i < n; i++) {
            pacific[i][0] = 1;
            atlantic[i][m - 1] = 1;
        }
        bfs(heights, pacific);
        bfs(heights, atlantic);
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) ans.push_back({i, j});
            }
        }
        return ans;
    }
};

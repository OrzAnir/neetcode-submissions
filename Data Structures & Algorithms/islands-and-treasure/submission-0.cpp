class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({0, {i, j}});
                }
            }
        }
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto p = q.front(); q.pop();
                int distance = p.first; auto p1 = p.second;
                int row = p1.first, col = p1.second;
                int delr[] = {-1, 0, 1, 0};
                int delc[] = {0, -1, 0, 1};
                for(int j = 0; j < 4; j++) {
                    int newr = row + delr[j];
                    int newc = col + delc[j];
                    if (newr < 0 || newc < 0 || newr >= n | newc >= m) continue;
                    if (grid[newr][newc] == INT_MAX) {
                        grid[newr][newc] = distance + 1;
                        q.push({distance + 1, {newr, newc}});
                    }
                }
            }
        }
    }
};

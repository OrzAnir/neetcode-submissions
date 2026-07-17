class Solution {
public:
    bool func(int index, int row, int col, vector<vector<char>>& board, string& word, 
    vector<vector<int>>& visited) {
        int n = board.size(), m = board[0].size();
        if (index == word.size() - 1) return true;
        visited[row][col] = 1;
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, -1, 0, 1};
        for(int i = 0; i < 4; i++) {
            int newr = row + delr[i];
            int newc = col + delc[i];
            if (newr < 0 || newc < 0 || newr >= n || newc >= m) continue;
            if (board[newr][newc] == word[index + 1] && !visited[newr][newc]) {
                if (func(index + 1, newr, newc, board, word, visited)) return true;
            }
        }
        visited[row][col] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if(func(0, i, j, board, word, visited)) return true;
                }
            }
        }
        return false;
    }
};

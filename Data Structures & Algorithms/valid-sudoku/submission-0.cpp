class Solution {
public:
    bool isValid(int row, int col, vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < m; i++) {
            if (i == col) continue;
            if (board[row][i] == board[row][col]) return false;
        }
        for(int i = 0; i < n; i++) {
            if (i == row) continue;
            if (board[i][col] == board[row][col]) return false;
        }
        int startRow = (row/3)*3, startCol = (col/3)*3;
        for(int i = startRow; i < startRow + 3; i++) {
            for(int j = startCol; j < startCol + 3; j++) {
                if (i == row && j == col) continue;
                if (board[i][j] == board[row][col]) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (board[i][j] != '.') {
                    if (!isValid(i, j, board)) return false;
                }
            }
        }
        return true;
    }
};

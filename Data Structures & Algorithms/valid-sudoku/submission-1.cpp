class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, set<int>> rows;
        map<int, set<int>> cols;
        map<pair<int, int>, set<int>> squares;
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (board[i][j] == '.') continue;
                int val = stoi(to_string(board[i][j]));
                if (rows[i].find(val) != rows[i].end()) return false;
                if (cols[j].find(val) != cols[j].end()) return false;
                if (squares[{i/3, j/3}].find(val) != squares[{i/3, j/3}].end()) return false;
                rows[i].insert(val);
                cols[j].insert(val);
                squares[{i/3, j/3}].insert(val);
            }
        }
        return true;
    }
};

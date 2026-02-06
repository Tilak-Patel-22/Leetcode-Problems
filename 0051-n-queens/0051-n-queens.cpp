class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, int n) {
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q')
                return false;
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void helper(vector<vector<string>>& ans, vector<vector<char>>& board, int col, int n) {
        if (col == n) {
            vector<string> temp;
            for (int i = 0; i < n; i++) {
                temp.push_back(string(board[i].begin(), board[i].end()));
            }
            ans.push_back(temp);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                helper(ans, board, col + 1, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        helper(ans, board, 0, n);
        return ans;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        queue<pair<int,int>> q;

        auto bfs = [&](int i, int j) {
            q.push({i, j});
            board[i][j] = 'T';

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                int dx[] = {-1, 1, 0, 0};
                int dy[] = {0, 0, -1, 1};

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                        board[nx][ny] == 'O') {
                        board[nx][ny] = 'T';
                        q.push({nx, ny});
                    }
                }
            }
        };

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') bfs(i, 0);
            if (board[i][n - 1] == 'O') bfs(i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') bfs(0, j);
            if (board[m - 1][j] == 'O') bfs(m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};
class Solution {
public:
    int m, n;

    vector<vector<int>> directions{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    bool isValid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void DFS(int i, int j, vector<vector<char>>& board) {
        board[i][j] = '#';

        for (auto d : directions) {
            int x_ = i + d[0];
            int y_ = j + d[1];

            if (isValid(x_, y_) && board[x_][y_] == 'O') {
                DFS(x_, y_, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;

        m = board.size();
        n = board[0].size();

        // First and last rows
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O')
                DFS(0, i, board);

            if (board[m - 1][i] == 'O')
                DFS(m - 1, i, board);
        }

        // First and last columns
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                DFS(i, 0, board);

            if (board[i][n - 1] == 'O')
                DFS(i, n - 1, board);
        }

        // Restore safe cells and capture surrounded cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '#')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};
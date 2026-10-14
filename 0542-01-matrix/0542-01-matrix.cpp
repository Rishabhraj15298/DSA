
class Solution {
public:
    vector<vector<int>> directions{
        {-1, 0}, {0, -1}, {1, 0}, {0, 1}
    };

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> result(m, vector<int>(n, -1));

        // Multi-source BFS
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            int x = temp.first;
            int y = temp.second;

            for (auto d : directions) {
                int x_ = x + d[0];
                int y_ = y + d[1];

                if (x_ >= 0 && x_ < m &&
                    y_ >= 0 && y_ < n &&
                    result[x_][y_] == -1) {

                    result[x_][y_] = result[x][y] + 1;
                    q.push({x_, y_});
                }
            }
        }

        return result;
    }
};

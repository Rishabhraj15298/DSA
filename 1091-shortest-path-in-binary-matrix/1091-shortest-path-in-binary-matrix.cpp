class Solution {
public:

    int m;
    int n;

    bool isSafe(int x, int y) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        vector<vector<int>> directions{
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1},
            {1, 1},
            {-1, 1},
            {1, -1},
            {-1, -1}
        };

        m = grid.size();
        n = grid[0].size();

        if (m == 0 || n == 0 || grid[0][0] == 1) {
            return -1;
        }

        queue<pair<int, int>> q;

        // Start from (0,0)
        q.push({0, 0});
        grid[0][0] = 1;

        int level = 1;

        while (!q.empty()) {

            int N = q.size();

            while (N--) {

                auto curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;

                // Destination reached
                if (x == m - 1 && y == n - 1) {
                    return level;
                }

                for (auto d : directions) {

                    int x_ = x + d[0];
                    int y_ = y + d[1];

                    if (isSafe(x_, y_) && grid[x_][y_] == 0) {

                        q.push({x_, y_});

                        // Mark visited
                        grid[x_][y_] = 1;
                    }
                }
            }

            // Move to next BFS level
            level++;
        }

        return -1;
    }
};
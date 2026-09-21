class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<P> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                P c = q.front();
                q.pop();

                int x = c.first;
                int y = c.second;

                for (auto& d : directions) {
                    int x_ = x + d[0];
                    int y_ = y + d[1];

                    if (x_ >= 0 && x_ < m && y_ >= 0 && y_ < n &&
                        height[x_][y_] == -1) {
                        height[x_][y_] = height[x][y] + 1;
                        q.push({x_, y_});
                    }
                }
            }
        }
        return height;
    }
};
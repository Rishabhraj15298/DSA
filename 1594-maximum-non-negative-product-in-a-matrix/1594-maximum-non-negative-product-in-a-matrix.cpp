class Solution {
public:
    int m, n;
    typedef long long ll;
    int MOD = 1e9 + 7;

    vector<vector<pair<ll, ll>>> t;

    pair<ll, ll> solve(int i, int j, vector<vector<int>>& grid) {

        if (i == m - 1 && j == n - 1) {
            return {grid[i][j], grid[i][j]};
        }

        // Already calculated
        if (t[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) {
            return t[i][j];
        }

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        // DOWN
        if (i + 1 < m) {
            auto [downMax, downMin] = solve(i + 1, j, grid);

            maxVal = max({
                maxVal,
                downMax * grid[i][j],
                downMin * grid[i][j]
            });

            minVal = min({
                minVal,
                downMax * grid[i][j],
                downMin * grid[i][j]
            });
        }

        // RIGHT
        if (j + 1 < n) {
            auto [rightMax, rightMin] = solve(i, j + 1, grid);

            maxVal = max({
                maxVal,
                rightMax * grid[i][j],
                rightMin * grid[i][j]
            });

            minVal = min({
                minVal,
                rightMax * grid[i][j],
                rightMin * grid[i][j]
            });
        }

        return t[i][j] = {maxVal, minVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        t = vector<vector<pair<ll, ll>>>(
            m,
            vector<pair<ll, ll>>(
                n,
                {LLONG_MIN, LLONG_MAX}
            )
        );

        auto [maxProd, minProd] = solve(0, 0, grid);

        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};
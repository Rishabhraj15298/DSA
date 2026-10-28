class Solution {
public:
    int findInd(int col, vector<vector<int>>& mat, int m) {
        int idx = -1;
        int maxi = -1;

        for (int i = 0; i < m; i++) {
            if (mat[i][col] > maxi) {
                maxi = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int s = 0;
        int e = n - 1;

        while (s <= e) {

            int mid = s + (e - s) / 2;

            int row = findInd(mid, mat, m);

            int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
            int right = mid + 1 < n ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            } else if (mat[row][mid] > left) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }

            
        }
        return {-1, -1};
    }
};
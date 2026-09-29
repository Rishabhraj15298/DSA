class Solution {
public:
    int t[2001][2001];
    bool pal[2001][2001];

    int solve(string &s, int i, int j) {

        if(i >= j) {
            return 0;
        }

        if(pal[i][j]) {
            return 0;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        int cuts = INT_MAX;

        for(int k = i; k < j; k++) {

            // Only consider valid palindrome left part
            if(pal[i][k]) {
                int temp = 1 + solve(s, k + 1, j);
                cuts = min(cuts, temp);
            }
        }

        return t[i][j] = cuts;
    }

    int minCut(string s) {

        int n = s.size();

        memset(t, -1, sizeof(t));
        memset(pal, false, sizeof(pal));

        // Build palindrome table
        for(int L = 1; L <= n; L++) {

            for(int i = 0; i + L - 1 < n; i++) {

                int j = i + L - 1;

                if(L == 1) {
                    pal[i][j] = true;
                }
                else if(L == 2) {
                    pal[i][j] = (s[i] == s[j]);
                }
                else {
                    pal[i][j] = (s[i] == s[j]) &&
                                pal[i + 1][j - 1];
                }
            }
        }

        return solve(s, 0, n - 1);
    }
};
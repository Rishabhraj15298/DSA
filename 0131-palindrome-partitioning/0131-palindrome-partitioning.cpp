class Solution {
public:

    void solve(string &s, int i,
               vector<string>& currPar,
               vector<vector<bool>>& t,
               vector<vector<string>>& result) {

        if(i == s.size()) {
            result.push_back(currPar);
            return;
        }

        for(int j = i; j < s.size(); j++) {

            // Only choose substring if it is palindrome
            if(t[i][j]) {

                currPar.push_back(s.substr(i, j-i+1));

                solve(s, j+1, currPar, t, result);

                currPar.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        int n = s.size();

        vector<vector<bool>> t(n, vector<bool>(n, false));

        // Build palindrome table
        for(int L = 1; L <= n; L++) {

            for(int i = 0; i + L - 1 < n; i++) {

                int j = i + L - 1;

                // Length 1
                if(i == j) {
                    t[i][j] = true;
                }

                // Length 2
                else if(L == 2) {
                    t[i][j] = (s[i] == s[j]);
                }

                // Length > 2
                else {
                    t[i][j] = (s[i] == s[j]) &&
                              t[i+1][j-1];
                }
            }
        }

        vector<vector<string>> result;
        vector<string> currPar;

        solve(s, 0, currPar, t, result);

        return result;
    }
};
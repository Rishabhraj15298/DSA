class Solution {

public: 

    void solve(int idx, string &digits, vector<string> &ans,
               unordered_map<char, string> &mp, string &temp) {

        // base case
        if (idx == digits.length()) {
            ans.push_back(temp);
            return;
        }

        // current digit
        char ch = digits[idx];
        string letters = mp[ch];

        // try all letters mapped to this digit
        for (char c : letters) {
            temp.push_back(c);       // choose
            solve(idx + 1, digits, ans, mp, temp); // explore
            temp.pop_back();         // backtrack
        }
    }

public:
    vector<string> letterCombinations(string digits) {

        if (digits.length() == 0) return {};

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        string temp = "";

        solve(0, digits, ans, mp, temp);
        return ans;
    }
};

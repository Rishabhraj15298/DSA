class Solution {
public:
    bool check(string &s , int i , int j){
        if(i>=j){
            return true;
        }
        if(s[i] == s[j]){
            return check(s , i+1 , j-1);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.size();

        int maxLen = INT_MIN;

        string res;

        for(int i =0;i<n;i++){
            for(int j = i ; j <n;j++){
                if(check(s,i,j) && j-i+1 > maxLen){
                    maxLen = j-i+1;
                    res = s.substr(i , maxLen);
                }
            }
        }
        return res;
    }
};
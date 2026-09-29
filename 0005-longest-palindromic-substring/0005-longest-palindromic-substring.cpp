class Solution {
public:
    // int t[1001][1001];
    // bool check(string &s , int i , int j){
    //     if(i>=j){
    //         return 1;
    //     }
       
    //     if(s[i] == s[j]){
    //         return t[i][j] = check(s , i+1 , j-1);
    //     }
    //      if(t[i][j] != -1 ) return t[i][j];
    //     return t[i][j] = 0;
    // }
    // string longestPalindrome(string s) {
    //     int n = s.size();
    //     memset(t , -1 , sizeof(t));
    //     int maxLen = INT_MIN;

    //     string res;

    //     for(int i =0;i<n;i++){
    //         for(int j = i ; j <n;j++){
    //             if(check(s,i,j) && j-i+1 > maxLen){
    //                 maxLen = j-i+1;
    //                 res = s.substr(i , maxLen);
    //             }
    //         }
    //     }
    //     return res;
    // }

    string longestPalindrome(string s ){
        int n = s.size();

        vector<vector<bool>>t(n , vector<bool>(n ,false));

        int maxLen = INT_MIN;
        int idx = -1;

        for(int L = 1 ; L <=n ;L++){
            for(int i =0;i+L-1<n;i++){
                int j = i+L-1;

                if(i == j){
                    t[i][j] = true;
                    idx = i;
                }
                else  if((i+1 == j) && s[i] == s[j] ){
                    t[i][j] = true;
                    maxLen = 2;
                    idx = i;
                }
                else if(s[i] == s[j] && t[i+1][j-1]){
                    t[i][j] = true;
                    if(j-i+1 > maxLen ){
                        maxLen = j-i+1;
                        idx = i;
                    }
                }
                else {
                    t[i][j] = false;
                }


            }
        }
        return s.substr(idx , maxLen);
    }
};
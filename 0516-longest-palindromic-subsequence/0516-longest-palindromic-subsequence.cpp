class Solution {
public:
    // int t[1001][1001];
    // int solve(string &s , int i , int j){
    //     if(i>j){
    //         return 0;
    //     }
    //     if(i == j){
    //         return 1;
    //     }
    //     if(t[i][j] != -1){
    //         return t[i][j];
    //     }
        
    //     if(s[i] == s[j] ){
    //        return t[i][j] =  2 + solve(s , i+1 , j-1 );
    //     }
    //     else {
    //          return t[i][j]  = max(solve(s, i+1 , j) , solve(s , i ,j-1));

    //     }
    //    return 0 ;
    // }
    // int longestPalindromeSubseq(string s) {
        
    //     int n = s.size();
    //     memset(t , -1 , sizeof(t));
    //     return solve(s , 0 , n-1);
    // }

    int longestPalindromeSubseq(string s ){
        int n = s.size();

        vector<vector<int >>t(n , vector<int >(n ,0));

        for(int L = 1;L<=n;L++){
            for(int i = 0 ; i+L-1 < n ; i++){
                int j = i+L-1;

                if(i == j){
                    t[i][j] = 1;
                }

                else {
                    if(s[i] == s[j]){
                        t[i][j ] = 2 + t[i+1][j-1];
                    }
                    else{
                        t[i][j] = max(t[i+1][j] , t[i][j-1]);
                    }
                }

            }
        }
        return t[0][n-1];
    }


};
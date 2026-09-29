class Solution {
public:
    // int t[501][501];
    // int solve(string &s , int i , int j ){
    //     if(i>=j){
    //         return 0;
    //     }

    //     if(t[i][j] != -1)return t[i][j];
    //     if(s[i] == s[j]){
    //         return t[i][j] = solve(s , i+1 , j-1);
    //     }
    //     else{
    //         return  t[i][j] =  min(1+ solve(s , i+1 , j) , 1+ solve(s , i , j-1));
    //     }
    //     return 0;
    // }
    // int minInsertions(string s) {
    //     int n = s.size();
    //     memset(t, -1 , sizeof(t));
    //     return solve(s , 0 , n-1);
    // }

    int minInsertions(string s ){
        int n = s.size();

        vector<vector<int>>t(n , vector<int>(n , 0));

        for(int L = 1;L<=n;L++){
            for(int i =0;i+L-1 < n ;i++){

                int j = i+L-1;

                // 1 length
                if(i == j){
                    t[i][j] = 0;
                }
                // 2 length
                else if(i+1 == j){
                    t[i][j] = (s[i] == s[j]) ? 0 : 1;
                }
                else{
                    // Generic case -> more than 2
                    if(s[i]  == s[j]){
                        t[i][j] = t[i+1][j-1];
                    }
                    else{

                    
                        t[i][j] = min(1+ t[i][j-1] , 1+ t[i+1][j]);
                    }
                }

            }
        }
        return t[0][n-1];
    }
};
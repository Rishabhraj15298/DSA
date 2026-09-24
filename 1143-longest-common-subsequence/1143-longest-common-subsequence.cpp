class Solution {
public:

    // ___________________________RECURSION + MEMOIZATION______________________-
    // int m , n ;
    // int t[1001][1001];
    // int solve(string &s1 , string &s2 , int i, int j ){
    //     if(i >= s1.length() || j>=s2.length()){
    //         return 0;
    //     }
    //     if(t[i][j] != -1){
    //         return t[i][j];
    //     }


    //     if(s1[i] == s2[j]){
    //          return t[i][j] = 1 + solve(s1 , s2 , i+1 , j+1);
    //     }
    //     else{
    //          return t[i][j] =   max(solve(s1 , s2 , i+1 , j) , solve(s1 , s2 , i , j+1));
    //     }
    // }

    // int longestCommonSubsequence(string s1, string s2) {
    //     m= s1.length();
    //     n = s2.length();

    //     memset(t , -1 , sizeof(t));

    //    return  solve(s1 , s2 , 0 ,0 );
    // }


    // ______________________BOTTOM - UP APPROACH_________________________________

    int longestCommonSubsequence(string s1 , string s2){
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>>t(m+1, vector<int>(n+1));

        for(int r = 0;r<=m;r++){
            t[r][0] = 0;
        }
        for(int c = 0;c<=n;c++){
            t[0][c] = 0;
        }

        for(int i = 1; i<=m;i++){
            for(int j =1 ;j<=n;j++){
                if(s1[i-1]  == s2[j-1]) {
                    t[i][j] = 1+ t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }
        }

        //_________PRINTING LCS_____________________

        string lcs = "";
        int i = m , j = n;

        while(i> 0 && j>0){
            if(s1[i-1] == s2[j-1]){
                lcs.push_back(s1[i-1]);
                i--;
                j--;//qki same h isiiye diagonally mmove krenge


            }
            else{
                //agar same nhi h toh maximum value ki taraf move krenge
                if(t[i-1][j] > t[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        reverse(lcs.begin() , lcs.end());
        cout <<lcs<<endl;
        return t[m][n];
    
    
    }
};
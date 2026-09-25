class Solution {
public:
    // int m , n ;
    // int t[502][502];
    // int solve(string &s1 , string &s2 , int i , int j ){
    //     if(i == 0 || j == 0){
    //         return i+j;
    //     }
    //     if(t[i][j] != -1){
    //         return t[i][j];
    //     }

    //     if(s1[i-1] == s2[j-1]){
    //         return t[i][j] = solve(s1 , s2 , i-1 , j-1);

    //     }
    //     int insertC  =  1 + solve(s1 , s2 , i , j-1);
    //     int removeC = 1 + solve(s1 , s2 , i-1 , j);
    //     int replaceC = 1 + solve(s1 , s2 , i-1 , j-1);

    //     return t[i][j] = min({insertC , removeC , replaceC});
    // }

    // int minDistance(string s1, string s2) {
    //     m = s1.size();
    //     n = s2.size();
    //     memset(t , -1 , sizeof(t));
    //     return solve(s1 , s2 , m , n);
    // }

    int minDistance(string s1 , string s2){
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>>t(m+1 , vector<int>(n+1));

        for(int i =0;i<=m;i++){
            for(int j = 0;j<=n;j++){
                if(i == 0 || j == 0 ){
                    t[i][j] = i+j;
                }
                else if(s1[i-1] == s2[j-1]){
                    t[i][j] = t[i-1][j-1];
                }
                else{
                    t[i][j] = 1 + min({t[i][j-1] , t[i-1][j] , t[i-1][j-1]});
                }
            }
        }
        return t[m][n];
    }
};
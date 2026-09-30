class Solution {
public:
    // int t[101][101];
    // int solve(int i , int j , int m , int n ){
    //     if(i == m-1 && j == n-1){
    //         return 1 ; // this means that we are at the destination

    //     }
    //     if(t[i][j] != -1){
    //         return t[i][j];
    //     }
    //     if(i <0 || i>=m || j<0 || j>=n){
    //         return 0; // this means that we are out of bounds
    //     }
    //     int right = solve(i , j+1 , m , n);
    //     int down = solve(i+1 , j , m , n);

    //     return t[i][j] = right + down ;
    // }

    // int uniquePaths(int m, int n) {
    //     memset(t ,  -1 , sizeof(t));
    //     return solve(0 ,0, m , n );
    // }

    int uniquePaths(int m , int n ){
        vector<vector<int>>t(m , vector<int >(n));
        // state : t[i][j] -> it represent the no. of paths to reach (i,j)
        t[0][0] = 1;
        // fill entire 0th row and col with 1;
        for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            if(i == 0 && j == 0)
                continue;

            if(i == 0) {
                t[i][j] = 1;
            }
            else if(j == 0) {
                t[i][j] = 1;
            }
            else {
                t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }
    }

        
        return t[m-1][n-1];
    }
};


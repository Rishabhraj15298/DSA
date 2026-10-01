class Solution {
public:

    // +++++++++++++++++BINARY SEARCH + DFS++++++++++++++++++++++++++++++++++
    // int m , n ;
    // unordered_map<string , bool >t;
    // bool canSurvive(int i , int j , int mid , vector<vector<int>>&dungeon){
    //     if(i>=m || j>=n){
    //         return false;
    //     }

    //     mid += dungeon[i][j];

        

    //     if(mid <= 0){
    //         return false;
    //     }
    //     if(i == m-1 && j==n-1){
    //         return true;
    //     }
    //     string key = to_string(i) + "_ " + to_string(j) + "_" + to_string(mid); 
    //     if(t.count(key)){
    //         return t[key];
    //     }

    //     return t[key] =  canSurvive(i , j+1 , mid , dungeon) || canSurvive(i+1 , j  , mid, dungeon);

    // }
    // int calculateMinimumHP(vector<vector<int>>& dungeon) {
    //     m= dungeon.size();
    //     n = dungeon[0].size();

    //     int l = 0;
    //     int r = 4 * 1e7;

    //     int minHP = 4*1e7;

    //     while(l <= r){
    //         int mid = l+(r-l)/2;

    //         if(canSurvive(0,0,mid,dungeon)){
    //             minHP = mid;
    //             r = mid-1;
    //         }
    //         else{
    //             l = mid+1;
    //         }
    //     }

    //     return minHP;
        

    // }


//  +++++++++++++++++++++RECURSION + MEMO.+++++++++++++++++++++++++++++++++

// int m , n ;
// int t[201][201];
// int solve(int i , int j , vector<vector<int>>&dungeon){
//     if(i>=m || j>=n){
//         return 1e9;
//     }

//     // last cell mei aagye -> ab value bharo 
//     if(i == m-1 && j == n-1){
//         if(dungeon[i][j] > 0){
//             return 1;
//         }
//         else{
//             return abs(dungeon[i][j]) + 1;
//         }

//     }
//     if(t[i][j] != -1)return t[i][j];

//     int right = solve(i+1 , j , dungeon);
//     int down = solve(i , j+1 , dungeon);

//     int res = (min(right , down))  - dungeon[i][j];
//     return t[i][j] = (res > 0) ? res : 1;
// }
// int calculateMinimumHP(vector<vector<int>>&dungeon){

//     m = dungeon.size();
//     n = dungeon[0].size();
//     memset(t , -1 , sizeof(t));
//     return solve(0,0,dungeon);
// }

int calculateMinimumHP(vector<vector<int>>&dungeon){
    int m = dungeon.size();
    int n = dungeon[0].size();

    vector<vector<int>>t(m , vector<int>(n));

    for(int i = m-1 ; i>=0 ;i--){
        for(int j = n-1 ; j>=0 ; j--){
            if(i == m-1 && j == n-1){
                t[i][j] = (dungeon[i][j] > 0 ) ? 1 : abs(dungeon[i][j]) + 1;
            }
            else{
                int right = (j+1 >= n ) ? 1e9 : t[i][j+1];
                int down = (i+1 >= m ) ? 1e9 : t[i+1][j];

                int result = min(down , right) - dungeon[i][j];

                t[i][j] = result>0 ? result :  1;
            }
        }
    }
    return t[0][0];
}
};
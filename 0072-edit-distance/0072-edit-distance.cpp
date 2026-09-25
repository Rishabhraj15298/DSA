class Solution {
public:
    int m , n ;
    int t[502][502];
    int solve(string &s1 , string &s2 , int i , int j ){
        if(i == m){
            // then we need to insert the remaining elements of s2
            return n-j;
        }
        if(j==n){
            //In this case , we need to remove the extra elements from the s1
            return m-i ;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }

        if(s1[i] == s2[j]){
            return t[i][j] = solve(s1 , s2 , i+1 , j+1);

        }
        int insertC  =  1 + solve(s1 , s2 , i , j+1);
        int removeC = 1 + solve(s1 , s2 , i+1 , j);
        int replaceC = 1 + solve(s1 , s2 , i+1 , j+1);

        return t[i][j] = min({insertC , removeC , replaceC});
    }

    int minDistance(string s1, string s2) {
        m = s1.size();
        n = s2.size();
        memset(t , -1 , sizeof(t));
        return solve(s1 , s2 , 0 , 0);
    }
};
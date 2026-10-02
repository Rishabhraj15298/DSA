class Solution {
public:
    int n , total ;
    int t[21][10001];
    int solve(int i , int r , vector<int>&nums , int result){
        if(i>=n ){
            return (r==result) ? 1 : 0;
        }
        if(t[i][total + r] != -1) return t[i][total+ r];
        int plus = solve(i+1 , r+nums[i] , nums ,result);
        int minus = solve(i+1 , r-nums[i] , nums , result);
        
        return t[i][total + r] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        for(int i : nums){
            total+=i;
        }
        memset(t , -1 , sizeof(t));
        return solve( 0 , 0 , nums , target);
    }
};
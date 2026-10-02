class Solution {
public:
    int n ;
    int solve(int i , int r , vector<int>&nums , int result){
        if(i>=n ){
            return (r==result) ? 1 : 0;
        }

        int plus = solve(i+1 , r+nums[i] , nums ,result);
        int minus = solve(i+1 , r-nums[i] , nums , result);
        
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();

        return solve( 0 , 0 , nums , target);
    }
};
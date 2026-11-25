class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0 ;
        int l = 0 ;
        int maxi = INT_MIN;

        for(int r = 0 ;r<n;r++){
            sum += nums[r];

            while(sum + k < r-l+1){
                sum -= nums[l];
                l++;
            }

            maxi = max(maxi , r-l+1);
        }
        return maxi;
    }
};
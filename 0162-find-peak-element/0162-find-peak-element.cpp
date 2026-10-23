class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int low = 0 ;
        int high = n-1;

        if(n==1)return 0;

        while(low <= high ){
            int mid  = low+(high-low ) /2;

            if(mid > 0 && mid < n-1){
                int ele = nums[mid];
                if(ele > nums[mid-1] && ele > nums[mid+1]){
                    return mid;
                }

                else if(ele < nums[mid-1]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else if(mid == 0 ){
                if(nums[0] > nums[1]){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            else{
                if(nums[n-1] > nums[n-2] ){
                    return n-1;
                }
                else{
                    return n-2;
                }
            }
        }
        return -1;
        
    }
};
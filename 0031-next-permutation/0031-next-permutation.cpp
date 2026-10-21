class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1] ){
                pivot = i;
                break;
            }
        }

        // IF there is no pivot , then reverse the whole array 
        if(pivot == -1){
            reverse(nums.begin() , nums.end());
            return;
        }

        int j = n-1;
        while(nums[j] <= nums[pivot]){
            j--;
        }

        swap(nums[j] , nums[pivot]);
        reverse(nums.begin() + pivot+1 , nums.end());
    }
};
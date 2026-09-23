class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>sortedArray;

        for(int i =0;i<n;i++){
            
            auto it = lower_bound(begin(sortedArray) , end(sortedArray) , nums[i]);

            if(it== end(sortedArray)){
                sortedArray.push_back(nums[i]);
            }
            else{
                *it = nums[i];
            }
        }

        return sortedArray.size();
    }
};
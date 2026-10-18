class Solution {
public:
    void sortColors(vector<int>& nums) {
        // DUTCH - NATIONAL FLAG
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int m = 0;

        while(m<=e){

            if(nums[m] == 0 ){
                swap(nums[m] , nums[s]);
                    s++;
                    m++;
                

            }
            else if(nums[m] == 2){
                swap(nums[m] , nums[e]);
                e--;
                

            }
            else{
                m++;
            }
        }
    }
};
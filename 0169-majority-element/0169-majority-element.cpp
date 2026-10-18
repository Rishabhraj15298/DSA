class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int ele = INT_MAX;
        for(int i=0;i<n;i++){
            
            if(cnt == 0){
                ele = nums[i];
                
            }

            if(nums[i] == ele){
                cnt++;
            }
            else{
                cnt--;
            }



        
        }
        return ele;
    }
};
class Solution {
public:
    bool isValid(vector<int>&nums , int k ,int n , int mid){
        int st = 1 ; int sum = 0;

        for(int i =0;i<n;i++){
            if(nums[i] > mid)return false;

           sum += nums[i];
           if(sum > mid ){
            st ++ ;
            sum = nums[i];
           }

           
        }
        return st > k ? false : true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();int sum = 0;
        for(int i =0 ;i<n;i++){
            sum += nums[i];
        }

        int s = 0 ;
         int e = sum;
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;

            if(isValid(nums , k ,n ,  mid)){
                ans = mid ;
                e= mid -1;
            }
            else{
                s = mid+1;
            }
        }
        return ans ;

        
    }
};
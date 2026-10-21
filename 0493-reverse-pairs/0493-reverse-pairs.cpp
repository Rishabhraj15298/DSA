class Solution {
public:

    int merge(vector<int>&nums , int s ,int mid ,  int e){
        vector<int>temp;
        int count = 0;
        int i = s;
        int j = mid+1;

        for (int i = s; i <= mid; i++) {
            while (j <= e && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }

            count += j - (mid + 1);
        }
        j=mid+1;

        while(i<=mid && j<=e){
                
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
                temp.push_back(nums[i]);
                i++;
            }
            while(j<=e){
                temp.push_back(nums[j]);
                j++;
            }
        for(int i =0;i<temp.size();i++){
            nums[i+s] = temp[i];
        }    

        return count;

    }
    int mergeSort(vector<int>&nums , int s , int e){
        if(s>=e)return 0;


        int mid = s+(e-s)/2;
        int leftC = mergeSort(nums , s , mid);
        int rightC = mergeSort (nums , mid+1 , e);
        int count = merge(nums , s , mid , e);

        return leftC + rightC + count ;
    }
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        return mergeSort(nums , 0 , n-1);
    }
};
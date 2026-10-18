class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1  = INT_MIN ;
        int ele2 =INT_MIN;
        int c1 = 0 , c2 = 0;


        for(int i : nums){
            if(c1 ==0 && ele2 != i){
                ele1 = i;
                c1 = 1;
            }
            else if(c2 == 0 && ele1 !=i){
                ele2 = i;
                c2 = 1;
            }

            else if (i == ele1) c1++;
            else if (i == ele2) c2++;

            else{
                c1--;
                c2--;
            }
        }

        vector<int>ans;
        int f1 = 0 , f2 = 0;
        for(int i : nums){
            if(i==ele1) f1++;
            if(i==ele2)f2++;

    
        }
        if(f1 > (n/3))ans.push_back(ele1);
        if(f2 > (n/3)) ans.push_back(ele2);


        return ans;
        
    }
};
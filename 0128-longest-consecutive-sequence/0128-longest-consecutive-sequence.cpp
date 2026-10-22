class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // set ka use krenge , pure set ko pehle populate krdo -> look for the -1 first
        int n = nums.size();
        unordered_set<int> st(nums.begin() , nums.end( ));
        int maxi = 0;

        for(int ele : st){

            if(!st.count(ele-1)){
                int cnt = 1;
                int x = ele;

                while(st.count(x+1)){
                    cnt++;
                    x++;
                }
                maxi = max(maxi , cnt);



            }
        }

        return maxi;

    }
};
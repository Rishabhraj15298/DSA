class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        map<int , int >mp;
        int n = nums2.size();

        for(int i = n-1;i>=0;i--){
            
            while(!st.empty() && nums2[i] > st.top()){
                st.pop();
            }
            mp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);

            
        }
        vector<int>ans;
        for(int i : nums1){
            ans.push_back(mp[i]);
        }
        return ans ;
    }
};
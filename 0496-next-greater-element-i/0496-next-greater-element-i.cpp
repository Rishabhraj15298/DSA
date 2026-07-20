class Solution {
public:
    vector<int> findNGE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            if (st.empty())
                nge[i] = -1;
            else
                nge[i] = st.top();

            st.push(arr[i]);
        }

        return nge;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;

        vector<int> ng = findNGE(nums2);

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (nums1[i] == nums2[j]) {
                    ans.push_back(j);
                }
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            ans[i] = ng[ans[i]];
        }

        return ans;
    }
};
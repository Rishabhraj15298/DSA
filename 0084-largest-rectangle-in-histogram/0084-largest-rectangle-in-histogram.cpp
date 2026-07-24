class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        stack<int> st;
        int maxi = 0;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[i] < heights[st.top()]) {

                int ele = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxi = max(maxi,
                           heights[ele] * (nse - pse - 1));
            }

            st.push(i);
        }

        while (!st.empty()) {

            int ele = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            maxi = max(maxi,
                       heights[ele] * (nse - pse - 1));
        }

        return maxi;
    }
};
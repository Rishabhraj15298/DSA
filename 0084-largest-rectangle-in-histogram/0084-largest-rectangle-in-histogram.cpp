class Solution {
public:
    vector<int>findnse(vector<int>arr , int n ){
        vector<int>ans(n);
        stack<int>st;
        for(int i =n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();
            st.push(i);

        }
        return ans;
    }

    vector<int>findpse(vector<int>arr, int n){
        vector<int>ans(n);
        stack<int>st;

        for(int i =0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int>nse = findnse(heights , n);
        vector<int>pse = findpse(heights , n);
        int maxi = INT_MIN;
        for(int i =0;i<n;i++){
            maxi = max(maxi , ( heights[i] * (nse[i] - pse[i] - 1)));

        }

        return maxi;
    }
};
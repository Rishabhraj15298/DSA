class Solution {
public:
    vector<int> findNSE(vector<int> arr, int n) {
        vector<int> ans(n);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> findPSE(vector<int> arr, int n) {
        vector<int> ans(n);

        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {

        // steps to follow :
        //  for each element , we have to find the NSE index and PSE index
        int n = arr.size();
        vector<int> NSE = findNSE(arr, n);
        vector<int> PSE = findPSE(arr, n);

        long long total = 0;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < n; i++) {

            long long left = i - PSE[i]; // over here pse stores the index of pse for i
            long long right = NSE[i] - i;

            total = (total + ((left * right )%MOD * arr[i]) % MOD) % MOD;
        }

        return total;
    }
};
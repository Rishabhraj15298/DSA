class Solution {
public:
    // Next Smaller Element
    vector<int> findNSE(vector<int>& arr, int n) {
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

    // Previous Smaller Element
    vector<int> findPSE(vector<int>& arr, int n) {
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

    // Next Greater Element
    vector<int> findNGE(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    // Previous Greater Element
    vector<int> findPGE(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }

    long long sumSubarrayMinimums(vector<int>& arr) {
        int n = arr.size();

        vector<int> NSE = findNSE(arr, n);
        vector<int> PSE = findPSE(arr, n);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - PSE[i];
            long long right = NSE[i] - i;

            total += left * right * 1LL * arr[i];
        }

        return total;
    }

    long long sumSubarrayMaximums(vector<int>& arr) {
        int n = arr.size();

        vector<int> NGE = findNGE(arr, n);
        vector<int> PGE = findPGE(arr, n);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - PGE[i];
            long long right = NGE[i] - i;

            total += left * right * 1LL * arr[i];
        }

        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaximums(nums) - sumSubarrayMinimums(nums);
    }
};
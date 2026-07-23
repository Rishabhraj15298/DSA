class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int n = height.size();
        int r = n - 1;
        int total = 0;
        int l_max = 0, r_max = 0;

        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] < l_max) {
                    total += l_max - height[l];
                } else {
                    l_max = height[l];
                }
                l++;
            } else {
                if (height[r] < r_max) {
                    total += r_max - height[r];

                } else {
                    r_max = height[r];
                }
                r--;
            }
        }
        return total;
    }
};
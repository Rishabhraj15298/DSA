class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int s = 0;
        int e = n - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            bool isEven = ((e - mid) % 2 == 0);

            if (nums[mid] == nums[mid + 1]) {
                if (isEven) {
                    s = mid + 2;
                }
                else {
                    e = mid - 1;
                }
            }
            else if (mid > 0 && nums[mid] == nums[mid - 1]) {
                if (isEven) {
                    e = mid - 2;
                }
                else {
                    s = mid + 1;
                }
            }
            else {
                return nums[mid];
            }
        }

        return nums[s];
    }
};
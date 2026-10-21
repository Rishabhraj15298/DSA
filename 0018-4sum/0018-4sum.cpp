
class Solution {
public:
    int n;
    vector<vector<int>> result;

    void twoSum(vector<int>& nums, long long target, int i, int k) {
        int left = k + 1;
        int right = n - 1;

        while (left < right) {
            long long sum = (long long)nums[left] + nums[right];

            if (sum == target) {
                result.push_back({
                    nums[i], nums[k], nums[left], nums[right]
                });

                left++;
                right--;

                while (left < right && nums[left] == nums[left-1])
                    left++;

                while (left < right && nums[right] == nums[right+1])
                    right--;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        n = nums.size();
        result.clear();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n-3; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;

            for (int k = i+1; k < n-2; k++) {
                if (k > i+1 && nums[k] == nums[k-1])
                    continue;

                long long newTarget = (long long)target - nums[i] - nums[k];
                twoSum(nums, newTarget, i, k);
            }
        }

        return result;
    }
};

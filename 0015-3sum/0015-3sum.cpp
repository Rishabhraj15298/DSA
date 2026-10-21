
class Solution {
public:
    vector<vector<int>> result;
    int n;

    void twoSum(vector<int>& nums, int target, int i) {
        int j = n - 1;

        while (i < j) {
            int sum = nums[i] + nums[j];

            if (sum == target) {
                result.push_back({-target, nums[i], nums[j]});
                i++;
                j--;

                while (i < j && nums[i] == nums[i - 1])
                    i++;

                while (i < j && nums[j] == nums[j + 1])
                    j--;
            }
            else if (sum < target) {
                i++;
            }
            else {
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        n = nums.size();
        result.clear();

        if (n < 3) return {};

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = -nums[i];
            twoSum(nums, target, i + 1);
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Sort the array (using <ranges>, available in C++20/23)
        std::ranges::sort(nums);

        vector<vector<int>> result;
        int n = static_cast<int>(nums.size());

        // First loop: fix nums[i]
        for (int i = 0; i < n; i++) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Second loop: fix nums[j]
            for (int j = i + 1; j < n; j++) {
                // Skip duplicates for j
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                // Two-pointer approach for the remaining two numbers
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    // Use long long to safely handle sums (to avoid overflow)
                    long long sum = static_cast<long long>(nums[i]) +
                                    nums[j] + nums[left] + nums[right];

                    if (sum < target) {
                        ++left;
                    } else if (sum > target) {
                        --right;
                    } else {
                        // Found a quadruplet
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for left
                        int oldLeft = nums[left];
                        while (left < right && nums[left] == oldLeft) {
                            ++left;
                        }

                        // Skip duplicates for right
                        int oldRight = nums[right];
                        while (left < right && nums[right] == oldRight) {
                            --right;
                        }
                    }
                }
            }
        }
        return result;
    }
};
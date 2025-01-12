class Solution {
public:
    int trap(vector<int>& height) {
        int n = (int)height.size();
        if (n < 3) return 0; // No water can be trapped if there are less than 3 heights.

        vector<int> left(n), right(n);

        // Precompute the maximum heights to the left of each position.
        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
        }

        // Precompute the maximum heights to the right of each position.
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }

        // Calculate the trapped water by iterating through each position.
        int ans = 0;
        for (int i = 0; i < n; i++) {
            // Water trapped at the current position is determined by the smaller of the two heights.
            ans += min(left[i], right[i]) - height[i];
        }

        return ans; // Return the total amount of trapped water.
    }
};
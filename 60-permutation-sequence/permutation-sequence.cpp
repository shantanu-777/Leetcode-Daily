class Solution {
public:
    string getPermutation(int n, int k) {
        // Initialize factorials and the list of available digits
        vector<int> factorial(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        // Create the list of digits from 1 to n
        vector<int> numbers(n);
        iota(numbers.begin(), numbers.end(), 1);  // Fill with values 1, 2, ..., n

        k--;  // Convert k to 0-indexed

        string result = "";

        // Build the permutation
        for (int i = 1; i <= n; ++i) {
            int index = k / factorial[n - i];  // Find which block the kth permutation falls into
            result += to_string(numbers[index]);

            // Remove the used digit from the list
            numbers.erase(numbers.begin() + index);

            // Update k to reflect the remaining block
            k %= factorial[n - i];
        }

        return result;
    }
};
class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) return 0;

        int i = 0, sign = 1;
        long ans = 0;
        int MAX = INT_MAX, MIN = INT_MIN;

        // Remove leading whitespaces
        while (i < s.size() && s[i] == ' ') i++;

        // Check for sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Process digits
        while (i < s.size() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // Handle overflow/underflow
            if (sign == 1 && ans > MAX) return MAX;
            if (sign == -1 && -ans < MIN) return MIN;

            i++;
        }

        return (int)(sign * ans);
    }
};
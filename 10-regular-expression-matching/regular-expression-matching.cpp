class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.length();
        int n = s.length();

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        //base case
        dp[0][0] = true;

        //fill in the table
        for(int i = 1; i <=m; i++) {
            for (int j = 0; j <=n; j++) {
                //case 1-2: . or matching character
                if (j > 0 && (p[i-1] == s[j-1] || p[i-1] == '.')) {
                    dp[i][j] = dp[i-1][j-1]; // inheriting from the diaganol
                }
                // case 3: *
                else if (i > 1 && p[i-1] == '*') {
                    dp[i][j] = dp[i-2][j];
                    if (j > 0 && (p[i-2] == s[j-1] || p[i-2] == '.')) {
                        dp[i][j] = (dp[i][j] || dp[i][j-1]);
                    }
                }
            }
        }
        return dp[m][n];
    }
};
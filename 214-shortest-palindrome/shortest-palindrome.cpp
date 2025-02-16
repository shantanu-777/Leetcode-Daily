class Solution {
public:
    void computeLPS(string &s, vector<int> &lps, int n){
        lps[0] = 0;
        int i = 1, len = 0;
        while(i < n){
            if (s[i] == s[len]){
                lps[i++] = ++len;
            }
            else if (len == 0){
                lps[i++] = len;
            }
            else {
                len = lps[len - 1];
            }
        }
    }

    string shortestPalindrome(string s) {
        int n = s.size();

        if (s.size() == 0)
            return "";
            
        vector<int> lps(n);
        computeLPS(s, lps, n);
        string pattern = s;
        reverse(s.begin(), s.end());

        int i = 0, j = 0;
        while (i < n) {
            if (s[i] == pattern[j]) {
                i++; j++;
            }
            else if (j == 0) {
                i++;
            }
            else {
                j = lps[j - 1];
            }
        }

        while (j < n) {
            s += pattern[j++];
        }
        return s;
    }
};
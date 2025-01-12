class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        int sidx = 0, pidx = 0;
        int staridx = -1, stmpidx = -1;

        while (sidx < slen) {
            // Case 1: Characters match or '?' matches any single character
            if (pidx < plen && (s[sidx] == p[pidx] || p[pidx] == '?')) {
                sidx++;
                pidx++;
            }
            // Case 2: '*' matches zero or more characters
            else if (pidx < plen && p[pidx] == '*') {
                staridx = pidx;
                stmpidx = sidx;
                pidx++;
            }
            // Case 3: Mismatch and backtrack to last '*'
            else if (staridx != -1) {
                pidx = staridx + 1;
                stmpidx++;
                sidx = stmpidx;
            }
            // Case 4: No match possible
            else {
                return false;
            }
        }

        // Check remaining characters in pattern are '*'
        while (pidx < plen && p[pidx] == '*') {
            pidx++;
        }

        return pidx == plen;
    }
};

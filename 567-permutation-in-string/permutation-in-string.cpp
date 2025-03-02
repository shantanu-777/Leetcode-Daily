class Solution {
public:
    bool isfreqsame(vector<int> f1, vector<int> f2) {
        for(int i = 0; i < 26; i++) {
            if(f1[i] != f2[i]) {
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);

        for(int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a']++;
        }

        int window_size = s1.size();

        for(int i = 0; i < s2.size(); i++) {
            int window_idx = 0, position_of_char = i;
            vector<int> window_freq(26, 0);

            while(window_idx < window_size && position_of_char < s2.size()) {
                window_freq[s2[position_of_char] - 'a']++;
                position_of_char++; window_idx++;
            }

            if(isfreqsame(freq , window_freq)) {
                return true;
            }
        }

        return false;
    }
};
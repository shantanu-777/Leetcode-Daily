class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int start = 0;
        int end = 0;
        int result = 0;

        while (end < gain.size()) {
            result = max(start, result);
            start += gain[end];
            end++;            
        }

        result = max(result, start);
        return result;
    }
};
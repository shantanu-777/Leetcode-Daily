#include <vector>
#include <algorithm>

class Solution {
public:
    long long dividePlayers(std::vector<int>& skill) {
        // Step 1: Sort the skill array
        std::sort(skill.begin(), skill.end());
        
        int n = skill.size();
        int totalSkill = skill[0] + skill[n - 1]; // Required sum for each pair
        long long chemistrySum = 0;

        // Step 2: Pair players using two pointers
        for (int i = 0; i < n / 2; i++) {
            // Check if the sum of current pair matches the required totalSkill
            if (skill[i] + skill[n - i - 1] != totalSkill) {
                return -1; // Invalid configuration, return -1
            }
            // Calculate the chemistry (product of pair) and add it to the sum
            chemistrySum += static_cast<long long>(skill[i]) * skill[n - i - 1];
        }

        return chemistrySum; // Return total chemistry
    }
};
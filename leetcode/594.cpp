/**
594. Longest Harmonious Subsequence
 * */

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int max = 0;
        unordered_map<int, int> map;
        
        for (const auto& x : nums) {
            ++map[x];
            if (map[x - 1] > 0) {
                max = std::max(max, map[x - 1] + map[x]);
            }
            if (map[x + 1] > 0) {
                max = std::max(max, map[x + 1] + map[x]);
            }  
        }
        
        return max;
    }
};
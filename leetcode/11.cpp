/**
 * 11. Container With Most Water
 * */

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int max = 0;
        int curr = 0;
        
        int l = 0;
        int r = height.size() - 1;
        
        while (l < r) {
            max = std::max((r - l) * std::min(height[l], height[r]), max);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        
        return max;
    }
};
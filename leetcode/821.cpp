/**
 * 821. Shortest Distance to a Character
 * */

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res(s.size(), 0);
        
        int recent = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                recent = i;
            } else {
                if (recent < 0) {
                    res[i] = std::numeric_limits<int>::max();
                } else {
                    res[i] = i - recent;
                }
            }

        }
        
        recent = -1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == c) {
                recent = i;
            } else {
                if (recent >= 0) {
                    res[i] = std::min(res[i], recent - i);
                }
            }
        } 

        return res;
    }
};
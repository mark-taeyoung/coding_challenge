/**
 * 1337. The K Weakest Rows in a Matrix
 * */

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> res;
        res.reserve(k);
        
        vector<queue<int>> freq(n + 1);
        
        for (int i = 0; i < m; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    break;
                } else {
                    ++count;
                }
            }
            freq[count].push(i);
        }

        for (int i = 0; i < n + 1; ++i) {
            while (!freq[i].empty() && res.size() < k) {
                res.push_back(freq[i].front());
                freq[i].pop();
            }
        }
        
        return res;
    }
};
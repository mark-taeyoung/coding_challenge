/**
 * 1091. Shortest Path in Binary Matrix
 * */

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int len = grid.size();
        
        if (grid[0][0] > 0 || grid[len - 1][len - 1] > 0) {
            return -1;
        }
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        
        int cost = 0;
        
        while (!q.empty()) {
            ++cost;
            int qSize = q.size();
            while (qSize > 0) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if (i == len - 1 && j == len - 1) {
                    return cost;
                }

                for (int k = -1; k < 2; ++k) {
                    for (int l = -1; l < 2; ++l) {
                        int ii = i + k;
                        int jj = j + l;
                        if (ii >= 0 &&
                                jj >= 0 && 
                                ii < len && 
                                jj < len &&
                                grid[ii][jj] == 0) {
                            q.push({ii, jj});
                            grid[ii][jj] = 1;
                        }
                    }
                }
                --qSize;
            }
        }
        
        return -1;
    }
};
    
    
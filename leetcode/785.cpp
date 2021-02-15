/**
 * 785 Is Graph Bipartite
 * */
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> qq;
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i].size() > 0) {
                qq.push(i);
            }
        }

        vector<int> group(graph.size(), 0);
        
        while (!qq.empty()) {
            int curr = qq.front();
            qq.pop();
            if (group[curr] != 0) {
                continue;
            } 
            
            int flag = -1;
            group[curr] = flag;
            
            queue<int> q;
            q.push(curr);
            
            while (!q.empty()) {
                int sz = q.size();
                flag = -flag;
                for (int i = 0; i < sz; ++i) {
                    int currr = q.front();
                    q.pop();
                    for (const auto& x : graph[currr]) {
                        if (group[x] == 0) {
                            group[x] = flag;
                            q.push(x);
                        } else if (group[x] != flag) {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
/**
 * 784. Letter Case Permutation
 * */

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        
        vector<int> alphaIdx;
        alphaIdx.reserve(S.size());
        
        for (int i = 0; i < S.size(); ++i) {
            if (isalpha(S[i])) {
                alphaIdx.push_back(i);
                S[i] = tolower(S[i]);
            }
        }
        
        int numCases = pow(2, alphaIdx.size());
        
        for (int i = 0; i < numCases; ++i) {
            res.push_back(S);
            auto it = alphaIdx.begin();
            int curr = i;
            while (curr > 0) {
                if (curr & 1) {
                    res.back()[*it] = toupper(res.back()[*it]);
                }
                curr = curr >> 1;
                ++it;
            }
        }
        
        return res;
    }
};
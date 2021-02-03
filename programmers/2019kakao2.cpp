/**
 * 후보키
*/

#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    int row = relation.size();
    int col = relation[0].size();
    int possibleKeySize = pow(2, col);
    
    vector<int> validKeys(possibleKeySize, 0);
    for (int i = 1; i < possibleKeySize; ++i) {
        unordered_set<string> set;
        for (int j = 0; j < row; ++j) {
            string str = "";
            auto it = relation[j].begin();
            for (int k = 1; k < possibleKeySize; k *= 2) {
                if ((i & k) > 0) {
                    str += *it + ",";
                }
                ++it;
            }
            set.insert(str);
        }
        if (set.size() == row) {
            validKeys[i] = 1;
        }
    }

    for (int i = 1; i < possibleKeySize; ++i) {
        if (validKeys[i] == 0) {
            continue;
        }
        for (int j = i + 1; j < possibleKeySize; ++j) {
            if (validKeys[j] > 0 && (i & j) == i) {
                validKeys[j] = 0;
            }
        }
        answer += validKeys[i];
    }
    
    return answer;
}
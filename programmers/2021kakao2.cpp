/**
 * 2021 KAKAO BLIND RECRUITMENT 
 * 메뉴 리뉴얼
*/
#include <bits/stdc++.h>

using namespace std;

void get_perm(const string& orders, 
        unordered_map<string, int>& freq,
        vector<int>& maxFreq,
        string& curr, 
        const int& len, 
        int i) {
    
    if (len == curr.size()) {
        freq[curr] = freq[curr] + 1;
        maxFreq[len] = std::max(maxFreq[len], freq[curr]);
        return;
    }
    
    for (int j = i; j < orders.size(); j++) {
        curr.push_back(orders[j]);
        get_perm(orders, freq, maxFreq, curr, len, j + 1);
        curr.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
        
    unordered_map<string, int> freq;
    vector<int> maxFreq(11, 0);
    
    string curr = "";
    for (auto& order : orders) {
        std::sort(order.begin(), order.end());
        for (const auto& size : course) {
            get_perm(order, freq, maxFreq, curr, size, 0);
        }
    }
    
    for (const auto& x : freq) {
        string course = x.first;
        int courseFreq = x.second;
        if (courseFreq > 1 && courseFreq == maxFreq[course.size()]) {
            answer.push_back(course);
        }
    }

    std::sort(answer.begin(), answer.end());
    return answer;
}
/**
 * 2021 KAKAO BLIND RECRUITMENT 
 * 순위 검색
*/
#include <bits/stdc++.h>

using namespace std;

int get_start_pos(const vector<int>& scores, const int& target) {
    int l = 0;
    int r = scores.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (target <= scores[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

void info_parser(unordered_map<int, vector<int>>& imap, const string& i, int start, int found, int key) {
    string delimiter = " ";
    if ((found = i.find(delimiter, start)) == string::npos) {
        imap[key].push_back(stoi(i.substr(start)));
        return ;
    }

    string curr = i.substr(start, found - start);
    int add = 0;
    if (curr == "cpp") {
        add = 1000;
    } else if (curr == "java") {
        add = 2000;
    } else if (curr == "python") {
        add = 3000;
    } else if (curr == "backend") {
        add = 100;
    } else if (curr == "frontend") {
        add = 200;
    } else if (curr == "senior") {
        add = 10;
    } else if (curr == "junior") {
        add = 20;
    } else if (curr == "chicken") {
        add = 1;
    } else if (curr == "pizza") {
        add = 2;
    } else {
        cout << "!!!!!unexpected!!!!!  ";
    }
    
    start = found + delimiter.size();
    info_parser(imap, i, start, found, key);
    info_parser(imap, i, start, found, key + add);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> res;

    string delimiter = " ";
    
    unordered_map<int, vector<int>> imap;
    
    for (const auto& i : info) {
        info_parser(imap, i, 0, 0, 0);
    }
    
    for (auto& iscores : imap) {
        std::sort(iscores.second.begin(), iscores.second.end());
    }

    for (const auto& q : query) {
        int key = 0;
        size_t start = 0;
        size_t found = 0;
        int add = 0;
        while ((found = q.find(delimiter, start)) != string::npos) {
            if (q[0] != 'a') {
                string curr = q.substr(start, found - start);
            
                if (curr == "cpp") {
                    add = 1000;
                } else if (curr == "java") {
                    add = 2000;
                } else if (curr == "python") {
                    add = 3000;
                } else if (curr == "backend") {
                    add = 100;
                } else if (curr == "frontend") {
                    add = 200;
                } else if (curr == "senior") {
                    add = 10;
                } else if (curr == "junior") {
                    add = 20;
                } else if (curr == "chicken") {
                    add = 1;
                } else if (curr == "pizza") {
                    add = 2;
                }
                key += add;
                add = 0;
            } else {
                start = start + 3;
            }
            start = found + delimiter.size();
        } 
        
        int pos = get_start_pos(imap[key], stoi(q.substr(start)));
        int count = imap[key].size() - pos;
        
        res.push_back(count);
    }
    
    return res;
}
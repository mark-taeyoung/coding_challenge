/**
 * 기둥과 보 설치
 * */

#include <bits/stdc++.h>

using namespace std;

bool build_checker(vector<vector<bitset<2>>>& wall,
            const int& x,
            const int& y,
            const int& isFloor) {
    bool ret = false;
    
    if (!isFloor) {
        ret = wall[x - 1][y][1] || wall[x][y][1] || wall[x][y - 1][0];
    } else {  
        ret = (wall[x - 1][y][1] && wall[x + 1][y][1]) ||
                wall[x][y - 1][0] || wall[x + 1][y - 1][0];
    }
    
    return ret;
}

void remove_helper(vector<vector<bitset<2>>>& wall,
            const int& x,
            const int& y,
            const int& isFloor) {
    wall[x][y][isFloor] = 0;

    if (!isFloor) {
        if (    (wall[x][y + 1][0] && !build_checker(wall, x, y + 1, false)) || 
                (wall[x][y + 1][1] && !build_checker(wall, x, y + 1, true)) ||
                (wall[x - 1][y + 1][1] && !build_checker(wall, x - 1, y + 1, true))
           ) {
            wall[x][y][isFloor] = 1;
        }
    } else {
        if (    (wall[x][y][0] && !build_checker(wall, x, y, false)) || 
                (wall[x + 1][y][0] && !build_checker(wall, x + 1, y, false)) ||
                (wall[x - 1][y][1] && !build_checker(wall, x - 1, y, true)) ||
                (wall[x + 1][y][1] && !build_checker(wall, x + 1, y, true))) {
            wall[x][y][isFloor] = 1;
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<vector<bitset<2>>> wall(n + 3, vector<bitset<2>>(n + 3, 0));
    
    for (int x = 1; x <= n + 1; ++x) {
        wall[x][1].set(1,1);
    }
    
    for (const auto& frame : build_frame) {
        const int x = frame[0] + 1;
        const int y = frame[1] + 1;
        const int isFloor = frame[2];
        const int build = frame[3];
        
        if (build) {
            if (build_checker(wall, x, y, isFloor)) {
                wall[x][y][isFloor] = 1;
            }
        } else {
            remove_helper(wall, x, y, isFloor);
        }
    }
    
    for (int x = 1; x <= n + 1; ++x) {
        for (int y = 1; y <= n + 1; ++y) {
            if (wall[x][y][0]) {
                answer.push_back({x - 1, y - 1, 0});
            }
            if (y > 1 && wall[x][y][1]) {
                answer.push_back({x - 1, y - 1, 1});
            }
        }
    } 

    return answer;
}
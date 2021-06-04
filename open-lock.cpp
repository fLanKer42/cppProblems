#include <iostream>
#include <bits/stdc++.h>

/*
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.
The lock initially starts at '0000', a string representing the state of the 4 wheels.
You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.
Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.
*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int min = 0;
        unordered_set<string> closed, dead;
        for (string c  : deadends) {
            dead.insert(c);
        }

        queue<string> open;
        open.push("0000");
        
        while (!open.empty()) {
            int layer = open.size();
            while(layer > 0) {
                string str = open.front();
                open.pop();
                if (dead.find(str) != dead.end()) {
                    layer--;
                    continue;
                }
                if (str == target) {
                    return min;
                }
                char chs[5];
                strcpy(chs, str.c_str());
                for (int i = 0; i < 4; i++) {
                    char temp = chs[i];
                    for (int j = -1; j <= 1; j += 2) {
                        chs[i] = (char)((temp - '0' + j + 10) % 10 + '0');
                        string newStr(chs);
                        if ((closed.find(newStr) == closed.end()) && (dead.find(newStr) == dead.end())) {
                            open.push(newStr);
                            closed.insert(newStr);
                        }
                    }
                    chs[i] = temp;
                }
                layer--;
            }
            min++;
        }
        return -1;
    }
};
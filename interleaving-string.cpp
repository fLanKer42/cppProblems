#include <iostream>
#include <bits/stdc++.h>

/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), c = s3.size();
        if (m+n != c) {
            return false;
        }
        bool dpa[m+1][n+1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                dpa[i][j] = false;
            }
        }
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) {
                    dpa[i][j] = true;
                }
                else if (i == 0) {
                    if (s2[j-1] == s3[j-1]) {
                        dpa[i][j] = dpa[i][j-1];
                    }
                }
                else if (j == 0) {
                    if (s1[i-1] == s3[i-1]) {
                        dpa[i][j] = dpa[i-1][j];
                    }
                }
                else if(s1[i-1] == s3[i+j-1] && s2[j-1] != s3[i+j-1]) {
                    dpa[i][j] = dpa[i-1][j];
                }
                else if (s1[i-1] != s3[i+j-1] && s2[j-1] == s3[i+j-1]) {
                    dpa[i][j] = dpa[i][j-1];
                }
                else if (s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1]) {
                    dpa[i][j] = dpa[i][j-1]||dpa[i-1][j];
                }
            }
        }
        return dpa[m][n];
    }
};
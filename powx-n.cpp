#include <iostream>
//#include <bits/stdc++.h>
/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104 
*/

class Solution {
public:
    double myPow(double x, long int n) {
        if (n < 0) {
            long int c = -1*n;
            return 1/myPow(x,c);
        }
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        unsigned int t = 1;
        double ret = x;
        while (t*2 < n) {
            t = t*2;
            ret = ret*ret;
            
        }
        return ret*(myPow(x, n-t));
    }
};
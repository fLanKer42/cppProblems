#include <iostream>
#include <bits/stdc++.h>

/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
Notice that you may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            int h = min(height[i],height[j]);
            int currArea = (j-i)*h;
            maxArea = max(currArea,maxArea);
            if (h == height[i]) {
                i++;
            }
            else {
                j--;
            }
            
        }
        return maxArea;
    }
    
};
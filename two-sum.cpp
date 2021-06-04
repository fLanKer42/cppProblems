/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

example
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].


2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/
#include <iostream>
#include <bits/stdc++.h>


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,n,j;
        n = nums.size();
        for(i = 0 ; i < n ; i++ ) {
            for(j = i + 1 ; j < n ; j++ ) {
                if((nums[i] + nums[j]) == target) {
                    vector<int> return_value { i, j};
                    return return_value;
                }
            }
        }
        vector<int> return_value(0);
        return return_value;
    }
};
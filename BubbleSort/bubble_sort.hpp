#pragma once

#include <vector>

// https://leetcode.com/problems/sort-an-array/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i; j < nums.size(); ++j)
                if (nums[j] < nums[i])
                    std::swap(nums[i], nums[j]);

        return nums;
    }
};

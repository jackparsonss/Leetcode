/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int left_s = 0, right_s = 0;
        do {
            left_s += nums[left];
            right_s += nums[right];
            left++; right--;
        } while(left_s != right_s && left <= right);

        if(left <= right) {
            return left+1;
        }

        return -1;
    }
};
// @lc code=end


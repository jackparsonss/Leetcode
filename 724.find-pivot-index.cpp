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
        int left = 0, right = 0;

        for (int i = 1; i < nums.size(); i++){
            right += nums[i];
        }

        if(right == 0) {
            return 0;
        }

        for (int i = 1; i < nums.size(); i++){
            right -= nums[i];
            left += nums[i-1];

            if(left == right) {
                return i;
            }
        }

        if(left == 0) {
            return nums.size()-1;
        }
        
        return -1;
    } 
};
// @lc code=end


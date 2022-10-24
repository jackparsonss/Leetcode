/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        return max(helper(nums, 1, nums.size()-1), helper(nums, 0, nums.size()-2)); 
    }

    int helper(vector<int> nums, int start, int end) {
        int prev = 0, curr = 0;

        for (int i = start; i <= end; i++){
            int temp = max(prev + nums[i], curr);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};
// @lc code=end


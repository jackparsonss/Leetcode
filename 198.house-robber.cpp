/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, curr = 0;

        for (int i = 0; i < nums.size(); i++){
            int temp = max(prev + nums[i], curr);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ma = INT_MIN;
        int curr = 0;
        for(int num: nums) {
            curr += num;
            ma = max(curr, ma);

            if(curr < 0) {
                curr = 0;
            }
        }

        return ma;
    }
};
// @lc code=end


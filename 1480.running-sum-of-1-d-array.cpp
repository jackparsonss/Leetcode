/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution{
public:
    vector<int> runningSum(vector<int> &nums){
        vector<int> out;
        int curr_sum = 0;
        for(int num : nums) {
            curr_sum += num;
            out.push_back(curr_sum);
        }

        return out;
    }
};
// @lc code=end

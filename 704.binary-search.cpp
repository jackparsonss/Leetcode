/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, hi = nums.size()-1; 
        while(low <= hi) {
            int mid = (low + hi) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end


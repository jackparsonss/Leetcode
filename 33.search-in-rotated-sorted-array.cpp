/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(target == nums[mid]) {
                return mid;
            }

            if(nums[left] <= nums[mid]) {
                if(nums[left] <= target && target <= nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if(nums[mid] <= target && target <= nums[right]) {
                    left = mid + 1; 
                } else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end


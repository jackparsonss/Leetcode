/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int best = 100000;
        for(int i = 0; i <= n-3; i++) {
            int left = i+1, right = n-1; 

            while(left < right) {
                int curr = nums[i] + nums[left] + nums[right];

                if(abs(target - best) > abs(target - curr)) {
                    best = curr;
                }

                if(curr < target) {
                    left++;
                } else if(curr > target) {
                    right--;
                } else {
                    return curr;
                }
            }
        }
        return best;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int best = 0;
        while(left < right) {
            int length = min(height[left], height[right]);
            int area = length * (right - left);
            best = max(best, area);
            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return best; 
    }
};
// @lc code=end


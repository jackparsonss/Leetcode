/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            if(m.find(comp) != m.end()) {
                return {m[comp], i};
            }
            m[nums[i]] = i;
        }
        return {-1, -1};
    }
};
// @lc code=end


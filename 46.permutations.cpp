/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out; 
        helper(out, nums, 0);
        return out;
    }

    void helper(vector<vector<int>> &out, vector<int>& nums, int cs) {
        if(cs == nums.size()) {
            out.push_back(nums);
            return;
        }

        for (int i = cs; i < nums.size(); i++){
            swap(nums[cs], nums[i]);
            helper(out, nums, cs+1);
            swap(nums[cs], nums[i]);
        }
    }
};
// @lc code=end


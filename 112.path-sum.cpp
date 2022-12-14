/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum, 0);
    }

    bool helper(TreeNode* root, int target, int curr) {
        if(!root){
            return false;
        }

        curr += root->val;
        if(!root->left && !root->right) {
            return curr == target;
        }
        return helper(root->left, target, curr) || helper(root->right, target, curr);
    }
};
// @lc code=end


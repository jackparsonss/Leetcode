/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    int pathSum(TreeNode* root, int targetSum) {
        int out = 0;
        helper(root, targetSum, out, 0);

        return out;
    }

    void helper(TreeNode* root, int target, int& total, int curr) {
        if(!root) {
            return;
        }

        curr += root->val;

        if(curr == target) {
            total++;
        }
        
        if(curr > target) {
            curr = 0;
        }

        helper(root->left, target, total, curr);
        helper(root->right, target, total, curr);
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        int di = 0;
        height(root, di);
        return di;
    }

    int height(TreeNode* root, int& di) {
        if(!root){
            return 0;
        }

        int left = height(root->left, di);
        int right = height(root->right, di);

        di = max(di, left + right);
        return 1 + max(left, right);
    }
};
// @lc code=end


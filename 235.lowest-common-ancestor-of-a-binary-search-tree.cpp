/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val = root->val;
        if(p->val < val && q->val < val) {
            return lowestCommonAncestor(root->left, p, q);
        } 
        
        if(p->val > val && q->val > val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};
// @lc code=end

